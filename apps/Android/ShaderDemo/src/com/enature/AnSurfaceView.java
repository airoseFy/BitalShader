package com.enature;

import android.content.Context;
import android.view.Surface;
import android.view.SurfaceHolder;
import android.view.SurfaceView;

public class AnSurfaceView extends SurfaceView implements SurfaceHolder.Callback {

	static{
		System.loadLibrary("NatureEngine");
	}
	
	public AnSurfaceView(Context context) {
		super(context);
		// TODO Auto-generated constructor stub
		this.getHolder().addCallback(this);
	}
	
	@Override
	public void surfaceChanged(SurfaceHolder holder, int format, int width, int height) {
		// TODO Auto-generated method stub
		OnSurfaceChanged(holder.getSurface());
	}

	@Override
	public void surfaceCreated(SurfaceHolder holder) {
		// TODO Auto-generated method stub
		OnSurfaceCreated(holder.getSurface());
	}

	@Override
	public void surfaceDestroyed(SurfaceHolder holder) {
		// TODO Auto-generated method stub
		OnSurfaceDestroyed(holder.getSurface());
	}

	protected native void OnSurfaceCreated(Surface surface);
	
	protected native void OnSurfaceDestroyed(Surface surface);
	
	protected native void OnSurfaceChanged(Surface surface);
}
