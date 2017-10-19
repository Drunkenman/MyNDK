package hankin.myndk;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;

public class MainActivity extends AppCompatActivity {

    static {
        System.loadLibrary("myndk");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }

    private native void cpp(String str);
    public native void java();
    public void print(String str){
        Log.d("mydebug---", str);
    }

    public void javaCallCPP(View view){
        cpp("你好来自java");
    }

    public void cppCallJava(View view){
        java();
    }

}
