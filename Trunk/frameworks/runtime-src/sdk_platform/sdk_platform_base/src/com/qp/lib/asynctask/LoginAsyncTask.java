package com.qp.lib.asynctask;

import android.os.AsyncTask;

public class LoginAsyncTask extends AsyncTask<String, Integer, String> {
	@SuppressWarnings("unused")
	private static final String	TAG	= "PlazzLoginAsyncTask";

	public static interface BackgroundDispose {

		public abstract void onDoInBackground(LoginAsyncTask loginasynctask, String as[]);
	}

	BackgroundDispose	m_backgroundDispose;

	public LoginAsyncTask(BackgroundDispose backgroundDispose) {
		m_backgroundDispose = backgroundDispose;
	}

	protected String doInBackground(String... params) {
		if (m_backgroundDispose != null)
			m_backgroundDispose.onDoInBackground(this, params);
		return "";
	}

	protected void onPostExecute(String s) {
	}

	protected void onPreExecute() {
	}

	protected void onProgressUpdate(Integer... ainteger) {
	}

	protected void onCancelled() {
	}
}
