#pragma once
#include<iostream>
#include<thread>
using namespace std;

class TimeTable;

class Timer {

public:

	//开始计时
	static void start(TimeTable* table);

	//停止计时
	static void stop();
		
	//模拟系统时间前进：以计算机的10s作为系统的1h
	static void forward(TimeTable* table);

	//课程闹钟：每晚9点提醒学生第二天上的课
	static void remind_course(TimeTable* table);

public:

	static int curWeek, curDay, curTime;
	static int isWorking;   //1：开始计时 0：停止计时
	static int interval;
};
