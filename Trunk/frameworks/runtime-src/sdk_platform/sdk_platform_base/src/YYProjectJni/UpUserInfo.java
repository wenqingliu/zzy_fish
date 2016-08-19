package YYProjectJni;

import java.io.ByteArrayOutputStream;
import java.io.File;
import java.io.FileNotFoundException;

import org.json.JSONException;
import org.json.JSONObject;

import com.jt.sdk_platform_base.SDKControlOriginal;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask;
import com.qp.lib.asynctask.ReadPostUrlAsyncTask.ReadPostExecute;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.app.ProgressDialog;
import android.app.AlertDialog.Builder;
import android.content.ActivityNotFoundException;
import android.content.ContentResolver;
import android.content.ContentValues;
import android.content.Context;
import android.content.DialogInterface;
import android.content.Intent;
import android.content.DialogInterface.OnCancelListener;
import android.graphics.Bitmap;
import android.graphics.BitmapFactory;
import android.graphics.Color;
import android.graphics.drawable.BitmapDrawable;
import android.graphics.drawable.ColorDrawable;

import android.net.Uri;
import android.os.Bundle;
import android.os.Environment;
import android.os.Handler;
import android.provider.MediaStore;
import android.util.Base64;
import android.util.Log;
import android.view.ContextThemeWrapper;
import android.view.KeyEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.widget.Button;
import android.widget.EditText;
import android.widget.GridView;
import android.widget.ImageButton;
import android.widget.ImageView;
import android.widget.LinearLayout;
import android.widget.RadioButton;
import android.widget.RelativeLayout;
import android.widget.Toast;

public class UpUserInfo implements OnClickListener {
	private static final String DISPLAY_NAME = "temp";
	private static final String FILE_NAME = "NewOx";

	public static final int SELECT_STYLEHEAD = 0;
	public static final int SELECT_PICTURE = 1;
	public static final int SELECT_CAPTURE = 2;
	public static final int CROP_SMALL_PICTURE = 3;
	
	private Uri imageUri;
	private AlertDialog SelectBuilder;
	private Bitmap bmp;
	private int HeadWidth = 100;
	private int HeadHeight = 100;
	private String userID = "";
	private String domainURL = "";
	
//	Dialog m_PopupWindow;
	ProgressDialog m_ProgressDialog;
	View uphead, upinfo;
	int defaHeadIndex = -1;
	Activity context;


	private static Uri getOutputMediaFileUri() {
		return Uri.fromFile(getOutputMediaFile());
	}

	private static File getOutputMediaFile() {
		String status = Environment.getExternalStorageState();
		if (!status.equals(Environment.MEDIA_MOUNTED))
			return null;
		File mediaStorageDir = null;
		try {

			mediaStorageDir = new File(
					Environment.getExternalStorageDirectory(), FILE_NAME);

		} catch (Exception e) {

		}

		// Create the storage directory if it does not exist
		if (!mediaStorageDir.exists()) {
			if (!mediaStorageDir.mkdirs()) {

			}
		}
		File mediaFile;
		mediaFile = new File(mediaStorageDir.getPath() + File.separator
				+ DISPLAY_NAME + ".jpg");

		return mediaFile;
	}

	public void onShowDialog(String title, String message) {
		dismissDialog();

		m_ProgressDialog.setTitle(title);
		m_ProgressDialog.setMessage(message);

		m_ProgressDialog.setCancelable(false);
		m_ProgressDialog.show();
	}

	public void CCUploadHead(JSONObject response){
		try {
			userID = response.getString("userID");
			domainURL = response.getString("domainURL");
			SelectBuilder.show();
		} catch (JSONException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public UpUserInfo(Activity context) {
		this.context = context;
		imageUri = getOutputMediaFileUri();

		m_ProgressDialog = new ProgressDialog(context);

		init();

	}

	public void init() {

		SelectBuilder = new AlertDialog.Builder(context)
				.setTitle("头像修改")
				.setItems(new String[] {"手机相册", "相机拍摄"
						//, "平台头像"
						},
						new DialogInterface.OnClickListener() {

							@Override
							public void onClick(DialogInterface dialog,
									int which) {
								Intent intent;
								defaHeadIndex = -1;
								switch (which) {
//								case SELECT_STYLEHEAD:
//
//									break;
								case 0:

									intent = new Intent(
											Intent.ACTION_PICK,
											android.provider.MediaStore.Images.Media.EXTERNAL_CONTENT_URI);
//									intent = new Intent(Intent.ACTION_PICK, null);
//									intent.setDataAndType(
//											MediaStore.Images.Media.EXTERNAL_CONTENT_URI, "image/*");

									intent.setType("image/*");

									intent.putExtra("crop", "true");

									intent.putExtra("aspectX", 1);

									intent.putExtra("aspectY", 1);

									intent.putExtra("outputX", HeadWidth);

									intent.putExtra("outputY", HeadHeight);

									intent.putExtra("scale", true);

									intent.putExtra("return-data", true);

									intent.putExtra("outputFormat",
											Bitmap.CompressFormat.JPEG
													.toString());

									intent.putExtra("noFaceDetection", true); // no
																				// face
																				// detection

									((Activity) UpUserInfo.this.context)
											.startActivityForResult(intent,
													SELECT_PICTURE);

									;
									break;
								case 1:
									intent = new Intent(
											MediaStore.ACTION_IMAGE_CAPTURE);

									intent.putExtra(
											MediaStore.Images.Media.ORIENTATION,
											0);

									intent.putExtra(MediaStore.EXTRA_OUTPUT,
											imageUri);

									((Activity) UpUserInfo.this.context)
											.startActivityForResult(intent,
													SELECT_CAPTURE);

									;
									break;
								/*case 2:
									JSONObject jobj = new JSONObject();
									try {
										jobj.put("url",SDKControlOriginal.getDelegate().getUserLogoInfo().getBigFace());
										jobj.put("result",1);
										SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Notify",jobj);
									} catch (JSONException e) {
										// TODO Auto-generated catch block
										e.printStackTrace();
									}
									Log.d("~~", "!!");
									break;*/
								}
								dialog.dismiss();

							}

						}).create();
	}

	public void onActivityResult(int requestCode, int resultCode, Intent data) {
		if (resultCode == Activity.RESULT_OK && requestCode == SELECT_PICTURE) {
			bmp = data.getParcelableExtra("data");
			if (bmp != null) {
				upHead(bmp);
			}else{
				Toast.makeText(this.context,"获取图片数据失败", Toast.LENGTH_LONG).show();
			}
		} else if (resultCode == Activity.RESULT_OK
				&& requestCode == CROP_SMALL_PICTURE) {
			bmp = decodeUriAsBitmap(imageUri);
			upHead(bmp);
		} else if (resultCode == Activity.RESULT_OK
				&& requestCode == SELECT_CAPTURE) {
			cropImageUri(imageUri, HeadWidth, HeadHeight, CROP_SMALL_PICTURE);
		} else {
//			Toast.makeText(context, "请重新选择图片", Toast.LENGTH_SHORT).show();
		}

	}

	private void cropImageUri(Uri uri, int outputX, int outputY, int requestCode) {

		Intent intent = new Intent("com.android.camera.action.CROP");
		intent.setType("image/*");
		intent.setDataAndType(uri, "image/*");

		intent.putExtra("crop", "true");

		intent.putExtra("aspectX", 1);

		intent.putExtra("aspectY", 1);

		intent.putExtra("outputX", outputX);

		intent.putExtra("outputY", outputY);

		intent.putExtra("scale", true);

		intent.putExtra(MediaStore.EXTRA_OUTPUT, uri);

		intent.putExtra("return-data", false);

		intent.putExtra("outputFormat", Bitmap.CompressFormat.JPEG.toString());

		intent.putExtra("noFaceDetection", true); // no face detection

		context.startActivityForResult(intent, requestCode);

	}

	private Bitmap decodeUriAsBitmap(Uri uri) {
		Bitmap bitmap = null;
		try {
			bitmap = BitmapFactory.decodeStream(context.getContentResolver()
					.openInputStream(uri));
		} catch (FileNotFoundException e) {
			e.printStackTrace();
			return null;
		}
		return bitmap;
	}

	public void upUserInfo() {
		// 只有不能修改 用户信息的时候才直接修改头像
		upHead(bmp);
	}

	public boolean upUserInfo(final String sznd, final int gender) {

		if (sznd != null) {
			onShowDialog("修改用户数据", "修改中...");

			return true;
		}
		return false;
	}

	public boolean upHead(int index) {

		if (index >= 0) {
			onShowDialog("修改用户头像", "修改中...");

			return true;
		}
		return false;
	}

	public boolean upHead(final Bitmap bmp) {

		if (bmp != null) {
			onShowDialog("修改用户头像", "修改中...");
//			domainURL = "http://wxtest.zzy1314.com";
			String url = domainURL + "/UploadFace.aspx";
			JSONObject jParam = new JSONObject();
			try {
				jParam.put("userid",userID);
//				Byte b = new Byte("");
				ByteArrayOutputStream baos = new ByteArrayOutputStream();
				bmp.compress(Bitmap.CompressFormat.JPEG, 100, baos);
				String photodata = new String(Base64.encode(baos.toByteArray(), Base64.DEFAULT));
				jParam.put("pic",photodata);
			} catch (JSONException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			ReadPostUrlAsyncTask post = new ReadPostUrlAsyncTask(url,"",jParam);
			post.addReadPostExecute(new ReadPostExecute() {
				
				@Override
				public void onPostExecute(String str) {
					m_ProgressDialog.dismiss();
					Log.d("", str.trim());
					if(str.trim().substring(0,5).indexOf("http") == -1){
						Toast.makeText(UpUserInfo.this.context,"头像上传失败", Toast.LENGTH_LONG).show();
						return;
					}
					JSONObject jobj = new JSONObject();
					try {
						jobj.put("url",str.trim());
						jobj.put("result",1);
						SDKControlOriginal.getDelegate().SendMessageWithParameters("ccNd_Notify",jobj);
						Toast.makeText(UpUserInfo.this.context,"头像上传成功", Toast.LENGTH_LONG).show();
					} catch (JSONException e) {
						// TODO Auto-generated catch block
						e.printStackTrace();
						Toast.makeText(UpUserInfo.this.context,e.getMessage(), Toast.LENGTH_LONG).show();
					}
				}
			});
			post.execute("");
			return true;
		}
		return false;
	}

	public void dismissDialog() {
		if (m_ProgressDialog != null)
			m_ProgressDialog.dismiss();
	}

	@Override
	public void onClick(View v) {

	}

}
