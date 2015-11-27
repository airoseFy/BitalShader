package com.bigital.shaderdemo;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.app.ActivityManager;
import android.app.ActivityManager.RunningAppProcessInfo;
import android.content.Context;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.drawable.Drawable;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;
import android.view.TextureView;
import android.view.View;
import android.widget.Button;


public class MainActivity extends Activity {
	private final String TAG = MainActivity.class.toString();
	
	static{
		System.loadLibrary("shader");
	}
	
	private GLSurfaceView surfaceView = null;
	
	private Button button = null;
	
	private Bitmap bitmap = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
        bitmap = BitmapFactory.decodeResource(getResources(), R.drawable.ic_launcher);
        surfaceView = new GLSurfaceView(this);
        surfaceView.setEGLConfigChooser(8, 8, 8, 0, 24, 0);
        surfaceView.setEGLContextClientVersion(2);
        surfaceView.setRenderer(renderer);
        setContentView(surfaceView);    
        TextureView textureView = null ;
        textureView.getSurfaceTexture();
    }
    
    private GLSurfaceView.Renderer renderer = new GLSurfaceView.Renderer() {
		
		@Override
		public void onSurfaceCreated(GL10 arg0, EGLConfig arg1) {
			// TODO Auto-generated method stub
			OnSurfaceCreated(surfaceView.getHolder().getSurface());
		}
		
		@Override
		public void onSurfaceChanged(GL10 arg0, int arg1, int arg2) {
			// TODO Auto-generated method stub
			OnSurfaceChanged(arg1, arg2);
		}
		
		@Override
		public void onDrawFrame(GL10 arg0) {
			// TODO Auto-generated method stub
			OnDrawFrame(bitmap);
		}
	}; 
	
	@Override
	protected void onDestroy() {
		kill();
		super.onDestroy();
	};
	
	private void kill(){
		ActivityManager am = (ActivityManager) getSystemService(Context.ACTIVITY_SERVICE);
		String mtaPackageName = getPackageName();
		for(RunningAppProcessInfo info:am.getRunningAppProcesses()){
			if(mtaPackageName.equalsIgnoreCase(info.processName)){
				android.os.Process.killProcess(info.pid);
			}
		}
	}
	
	private static native void OnSurfaceCreated(Surface surface);
	
	private static native void OnSurfaceChanged(int width, int height);
	
	private static native void OnDrawFrame(Bitmap bitmap);
}
