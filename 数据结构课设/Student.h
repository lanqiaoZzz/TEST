#pragma once
#include "TimeTable.h"
#include"Time.h"
#include"Timer.h"
//#include"Activity.h"
#include<iostream>
using namespace std;
class Student {
public:
	//��ȡ���������ļ���
	Folder* get_electronicDataFoder();

	//��ӵ�������
	void add_electronicData();

	//ɾ����������
	void delete_electronicData();

	//�޸ĵ�������
	void modify_electronicData();

	//�鿴�γ�����
	void check_electronicData();
public:
	//�鿴���д�����ҵ
	void checkHomework();

	//�ύ��ҵʱmod=1������ʱ��mod=0
	Folder* getHomeworkFoder(int mod);

	//�ύ��ҵ
	void submit_homework();

	//�鿴�ѽ���ҵ
	 void check_paidhomework();

	//�޸���ҵ
	 void modify_paidhomework();
public:
	Student();

	Student(TimeTable* timetable);
public:
	//�鿴���пγ�;
	void checkCourse();

	//ͨ���γ����Ʋ�ѯ�γ���Ϣ
	void queryCourseByName();

public:
	//ѹ��ĳ�����ӿγ�����/��ɵ���ҵ
	void compressFile();

	//mod==0:��ȡ��ҵ�ļ��� mod==1 ��ȡ���������ļ���
	void checkDuplicate(int mod);
public:
	//�����,���ջʱ��������в���
	void create_activitiy();

	//��ӡ���Ϣ�����ջʱ������
	//void print_activity_info();

	////��ʱ���ѯ�,Ĭ�ϲ�ѯ���ܵĻ�����ֲ��ң�
	//void query_activity_bytime();

	////ɾ���
	//void delete_acticity();

	////ʱ���ͻ���,�ڴ����ʱ������
	//void time_conflict_detection(Time time);
public:
	static int ID;
private:
	int id;
	char name[20]; //����  xkx:����С��չ��20
	TimeTable* table; //�γ̱�,xkx:���γ̱��Ϊָ������
public:
	//static Activity* my_activity; //����� 
	//static int activity_capacity;  //��������
	//static int activity_num;//�����
};