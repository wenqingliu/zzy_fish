package com.jt.activity;

import com.hjwl.newox.leshi.R;

import android.annotation.SuppressLint;
import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.content.res.Resources;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.util.DisplayMetrics;
import android.util.LruCache;
import android.view.WindowManager;
import android.view.animation.AlphaAnimation;
import android.view.animation.Animation;
import android.view.animation.Animation.AnimationListener;
import android.widget.ImageView;

@TargetApi(Build.VERSION_CODES.HONEYCOMB_MR1) @SuppressLint("NewApi") 
public class WelcomeActivity extends Activity {

	private Handler mHandler = new Handler();
	private ImageView splashImageView;
	private Bitmap imageViewBitmap = null;
	private int orientation;
	private LruCache<String, Bitmap> mMemoryCache;
	private Bitmap map; 

	private int screenWidth;
	private int screenHeight;

	@TargetApi(Build.VERSION_CODES.HONEYCOMB_MR1) @SuppressLint("NewApi") @Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_welcome);

		int maxMemory = (int) (Runtime.getRuntime().maxMemory() / 1024);
		int cacheSize = maxMemory / 8;
//		mMemoryCache = new LruCache<String, Bitmap>(cacheSize) {
//			@Override
//			protected int sizeOf(String key, Bitmap bitmap) {
//				return bitmap.getByteCount() / 1024;
//			}
//		};
		splashImageView = (ImageView) findViewById(R.id.splashId);
		orientation = getResources().getConfiguration().orientation;
		imageViewBitmap = getBitmap(R.drawable.icon_welcome);
		loadSplashIn();
	}

	public void addBitmapToMemoryCache(String key, Bitmap bitmap) {
		map = bitmap;
//		if (getBitmapFromMemCache(key) == null) {
//			mMemoryCache.put(key, bitmap);
//		}
	}

//	public Bitmap getBitmapFromMemCache(String key) {
//		return mMemoryCache.get(key);
//	}

	public void loadSplashIn() {
		AlphaAnimation alphaAnimation_in = new AlphaAnimation(0.0f, 1.0f);
		alphaAnimation_in.setDuration(1500);
		alphaAnimation_in.setAnimationListener(new AnimationListener() {

			@Override
			public void onAnimationStart(Animation animation) {
				// TODO Auto-generated method stub
				if (splashImageView != null) {
					splashImageView.setImageBitmap(imageViewBitmap);
				}
			}

			@Override
			public void onAnimationRepeat(Animation animation) {
				// TODO Auto-generated method stub

			}

			@Override
			public void onAnimationEnd(Animation animation) {
				// TODO Auto-generated method stub

				mHandler.postDelayed(new Runnable() {

					@Override
					public void run() {
						// TODO Auto-generated method stub
						loadSplashOut();
					}
				}, 1000);
			}
		});

		splashImageView.startAnimation(alphaAnimation_in);

	}

	public Bitmap getBitmap(int id) {

		Bitmap bitmap = map;//getBitmapFromMemCache("splash");
		if (bitmap != null) {
			return bitmap;
		}
		WindowManager wm = this.getWindowManager();
		DisplayMetrics dm = new DisplayMetrics();
		wm.getDefaultDisplay().getMetrics(dm);
		screenWidth = dm.widthPixels;
		screenHeight = dm.heightPixels;
		bitmap = decodeSampledBitmapFromResource(getResources(), id, screenWidth, screenHeight);

		addBitmapToMemoryCache("splash", bitmap);

		return bitmap;
	}

	public void loadSplashOut() {
		AlphaAnimation alphaAnimation_out = new AlphaAnimation(1.0f, 0.0f);
		alphaAnimation_out.setDuration(1000);
		alphaAnimation_out.setAnimationListener(new AnimationListener() {

			@Override
			public void onAnimationStart(Animation animation) {
				// TODO Auto-generated method stub

			}

			@Override
			public void onAnimationRepeat(Animation animation) {
				// TODO Auto-generated method stub

			}

			@Override
			public void onAnimationEnd(Animation animation) {
				// TODO Auto-generated method stub
				splashImageView.setImageBitmap(null);
//				Intent intent = new Intent();
//				intent.setClass(getApplicationContext(), GameActivity.class);
//				startActivity(intent);
				WelcomeActivity.this.finish();
				imageViewBitmap.recycle();
				imageViewBitmap = null;
			}
		});
		splashImageView.startAnimation(alphaAnimation_out);
	}

	public static int calculateInSampleSize(BitmapFactory.Options options, int reqWidth, int reqHeight) {
		final int height = options.outHeight;
		final int width = options.outWidth;
		int inSampleSize = 1;
		if (height > reqHeight || width > reqWidth) {
			if (width > height) {
				inSampleSize = Math.round((float) height / (float) reqHeight);
			} else {
				inSampleSize = Math.round((float) width / (float) reqWidth);
			}
		}
		return inSampleSize;
	}

	public Bitmap decodeSampledBitmapFromResource(Resources res, int resId, int reqWidth, int reqHeight) {

		final BitmapFactory.Options options = new BitmapFactory.Options();
		options.inJustDecodeBounds = true;
		BitmapFactory.decodeResource(res, resId, options);
		options.inSampleSize = calculateInSampleSize(options, reqWidth, reqHeight);
		options.inJustDecodeBounds = false;
		return BitmapFactory.decodeResource(res, resId, options);
	}
}
