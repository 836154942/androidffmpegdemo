package com.example.spc.mmfpeghello;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("avutil-55");
        System.loadLibrary("avcodec-57");
        System.loadLibrary("avformat-57");
        System.loadLibrary("avdevice-57");
        System.loadLibrary("swresample-2");
        System.loadLibrary("swscale-4");
        System.loadLibrary("postproc-54");
        System.loadLibrary("avfilter-6");
        System.loadLibrary("hello_jni");
    }


    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    public void click1(View v) {
        Toast.makeText(this, new NativeMethods().helloWorld(), Toast.LENGTH_SHORT).show();
    }
    public void click2(View v) {
        Toast.makeText(this, new NativeMethods().urlprotocolinfo(), Toast.LENGTH_SHORT).show();
    }
    public void click3(View v) {
        Toast.makeText(this, new NativeMethods().avformatinfo(), Toast.LENGTH_SHORT).show();
    }
    public void click4(View v) {
        Toast.makeText(this, new NativeMethods().avcodecinfo(), Toast.LENGTH_SHORT).show();
    }
    public void click5(View v) {
        Toast.makeText(this, new NativeMethods().avfilterinfo(), Toast.LENGTH_SHORT).show();
    }
}
