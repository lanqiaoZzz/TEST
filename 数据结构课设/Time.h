#pragma once
#include"Timer.h"
class Time
{
private:
	int week[20];
	int day[8];
	int startTime;
	int endTime;
public:
	Time(int *week, int *day, int startTime, int endTime);
	 Time();
	 //将参数转化为结构数据
	 void SetTime(int a, int b, int c, int d,int e,int mod);
	//判断当前时间与time谁先发生，如果当前时间先发生，返回1，time时间先发生则返回0
	int is_clear(Time time);
	//时间比较函数
	int compareTo(Time time);
	//冲突返回一，不冲突返回0；
	int conflict_detection(Time time);
};
