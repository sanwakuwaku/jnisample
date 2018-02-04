package com.sanwaku2.ndkcallbacksample;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    static {
        System.loadLibrary("native-lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        TextView tv = findViewById(R.id.sample_text);
        tv.setText(stringFromJNI());
        stringFromJNI2(new CompleteListener() {
            @Override
            public void onComplete() {
                Log.d("test", "onComplete call.");
            }
        });
    }

    public native String stringFromJNI();

    public native String stringFromJNI2(CompleteListener listener);

    public interface CompleteListener {
        void onComplete();
    }
}
