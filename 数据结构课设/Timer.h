#pragma once
#include<iostream>
#include<thread>
using namespace std;


class Timer {

public:

	//ģ��ϵͳʱ�� + �������� + ����ں����������
	//static void task();

	//��ʼ��ʱ
	//static void start();

	//ֹͣ��ʱ
	//static void stop();

public:

	static int curWeek, curDay, curTime;
	static int isWorking;   //1����ʼ��ʱ 0��ֹͣ��ʱ
	static int interval;
};
