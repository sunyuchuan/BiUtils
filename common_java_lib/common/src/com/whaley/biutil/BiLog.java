package com.whaley.biutil;

import org.json.JSONObject;

/**
 * Created by wanglei on 2016/7/28.
 */
public class BiLog implements IBiLog {
    private String LogVersion = "02";
    private JSONObject LogHeader = new JSONObject();
    protected JSONObject Params = new JSONObject();

    protected void PutHeader(String name, String value) {
	try {
	    LogHeader.put(name, value);
	}
	catch (Exception e) {
	}
    }

    protected void PutHeader(String name, long value) {
	try {
	    LogHeader.put(name, value);
	}
	catch (Exception e) {
	}
    }
    
    public BiLog(String logType) {
	PutHeader("logVersion", LogVersion);
	PutHeader("logType", logType);
	PutHeader("happenTime", System.currentTimeMillis());
    }
    
    @Override
    public void PushParameter(String name, String value)
    {
	try {
	    Params.put(name, value);
	}
	catch (Exception e) {
	}
    }

    @Override
    public String GetString()
    {
	String logstr = null;
	try {
	    JSONObject jsonLog = new JSONObject(LogHeader.toString());
	    jsonLog.put("params", Params);
	    logstr = jsonLog.toString();
	}
	catch (Exception e) {
	}
        return logstr;
    }
}
