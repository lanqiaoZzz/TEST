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
	 //������ת��Ϊ�ṹ����
	 void SetTime(int a, int b, int c, int d,int e,int mod);
	//�жϵ�ǰʱ����time˭�ȷ����������ǰʱ���ȷ���������1��timeʱ���ȷ����򷵻�0
	int is_clear(Time time);
	//ʱ��ȽϺ���
	int compareTo(Time time);
	//��ͻ����һ������ͻ����0��
	int conflict_detection(Time time);
};
