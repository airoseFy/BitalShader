package com.bigital.shaderdemo;

import android.app.Activity;
import android.os.Bundle;
import android.util.Log;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;


public class MainActivity extends Activity {
	private final String TAG = MainActivity.class.toString();
	
	static{
		System.loadLibrary("shader");
	}
	
	private SurfaceView surfaceView = null;
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
//        setContentView(R.layout.activity_main);
        surfaceView = new SurfaceView(this);
        surfaceView.getHolder().addCallback(callback);
        setContentView(surfaceView);      
    }
    
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
	
	private native void onSurfaceCreated(Surface surface);
	
	private native void onSurfaceChanged(Surface surface);
	
	private native void onSurfaceDestroy(Surface surface);
}
