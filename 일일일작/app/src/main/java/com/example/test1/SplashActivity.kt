package com.example.test1

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import android.content.Intent



class SplashActivity : AppCompatActivity() {

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        val intent = Intent(this, MainActivity::class.java)            // 실제 사용할 메인 액티비티
        Thread.sleep(2000)
        startActivity(intent)
        finish()
    }
}
