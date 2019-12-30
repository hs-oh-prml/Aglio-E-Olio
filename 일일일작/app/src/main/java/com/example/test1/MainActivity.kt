package com.example.test1

import android.support.v7.app.AppCompatActivity
import android.os.Bundle
import kotlin.random.Random

class MainActivity : AppCompatActivity() {

    val int_Array = ArrayList<Int>() ;

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)

        shuffle()
    }

    fun shuffle() : Unit{
        val dice : Int = Random.nextInt(0,100)
    }
}
