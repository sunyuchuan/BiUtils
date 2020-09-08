package com.whaley.biutil;

/**
 * Created by wanglei on 2016/7/28.
 */
public interface IBiLog {
    public void PushParameter(String name, String value);
    public String GetString();
}
