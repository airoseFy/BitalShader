package com.bigital.shaderdemo;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;


public class MainActivity extends Activity {
	private final String TAG = MainActivity.class.toString();
	
	static{
		System.loadLibrary("shader");
	}
	
	private GLSurfaceView surfaceView = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
        surfaceView = new GLSurfaceView(this);
//        surfaceView.getHolder().addCallback(callback);
//        surfaceView.setZOrderOnTop(true);
        surfaceView.setRenderer(renderer);
        setContentView(surfaceView);      
    }
    
    private GLSurfaceView.Renderer renderer = new GLSurfaceView.Renderer() {
		
		@Override
		public void onSurfaceCreated(GL10 arg0, EGLConfig arg1) {
			// TODO Auto-generated method stub
//			onSurfaceCreated(surfaceView.getHolder().getSurface());
		}
		
		@Override
		public void onSurfaceChanged(GL10 arg0, int arg1, int arg2) {
			// TODO Auto-generated method stub
			
		}
		
		@Override
		public void onDrawFrame(GL10 arg0) {
			// TODO Auto-generated method stub
			
		}
	}; 
	
    private SurfaceHolder.Callback callback = new SurfaceHolder.Callback() {
		
		@Override
		public void surfaceDestroyed(SurfaceHolder holder) {
			// TODO Auto-generated method stub
			//Log.d(TAG, "surfaceDestroyed");
			onSurfaceDestroy(holder.getSurface());
		}
		
		@Override
		public void surfaceCreated(SurfaceHolder holder) {
			// TODO Auto-generated method stub
			//Log.d(TAG, "surfaceCreated");
			onSurfaceCreated(holder.getSurface());
		}
		
		@Override
		public void surfaceChanged(SurfaceHolder holder, int format, int width,
				int height) {
			// TODO Auto-generated method stub
			//Log.d(TAG, "surfaceChanged width = "+width+" height = "+height);
			onSurfaceChanged(holder.getSurface());
		}
	};
	
	private static native void onSurfaceCreated(Surface surface);
	
	private static native void onSurfaceChanged(Surface surface);
	
	private static native void onSurfaceDestroy(Surface surface);
}
