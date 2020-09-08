package com.whaley.biutil.directuploader;
import com.whaley.biutil.IBiLogUploader;
/**
 * Created by wanglei on 2016/7/28.
 */
public class BiLogUploaderFactory {
    public static IBiLogUploader CreateBiLogUplader()
    {
        return new BiDirectLogUploader();
    }
}
