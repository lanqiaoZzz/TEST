#pragma once
#include<String.h>
#include"Folder.h"
#include"Homework.h"
#include"Time.h"
#include<fstream>
class Course {
public:
	~Course();
	Course() {};
	Course(char name[], char courseTime[], char coursePlace[], char paperData[], char courseQqGroup[],Time time);
	char* getname() {
			return name;
	}
	Folder* getelectronicData();
	Homework* get_myHomework() {
		return this->myHomework;
	}
	void set_examTime(char time[]) {
		if (strlen(time) < 5) {
			strcpy(this->examTime, "             ");
		}
		strcpy(this->examTime ,time);

	}
	void set_exam_time(Time T) {
		this->exam_time = T;
	}
	void set_examPlace(char place[]) {
		if (strlen(place) <3 ) {
			strcpy(this->examTime, "    ");
		}
		strcpy(this->examPlace, place);
	}
	char* get_examTime() {
		return this->examTime;
	}
	char*get_examPlace() {
		return this->examPlace;
	}
	void set_progress(char progress[]) {
		strcpy(this->progress, progress);
	}
	char* get_progress() {
		return this->progress;
	}
	void get_info(char courseInfo[]);
	Time get_course_time() {
		return this->course_time;
	}
	Time get_exam_time() {
		return this->exam_time;
	}
public:
	//�洢��ҵ
	void saveHomework();
	//������ҵ
	void uploadHomenwork();
	//�����ҵ
	void clear_disk();
	//��ȡ��ҵ
	int getHomework();
	//�����ҵ
	void addHomework();
	//ɾ����ҵ
	void deleteHomework();
	//�޸���ҵ
	void modifyHomework();
	//��ʦ�鿴��ҵ
	void checkHomework();
	//ѧ���鿴��ҵ
	void checkHomework(int id);
public:
	//���ڴ��м��ص�������

public:
	//���γ̱��浽�ڴ�
	void save_course(ofstream& ofs);
	static int ID;
private:
	char name[50];                   //�γ���
	char courseTime[50];			//�Ͽ�ʱ�䣨��ʽ��x~x��[�ܼ��ڼ���]��
	char coursePlace[10];			 //�Ͽεص�
	char paperData[50];				//ֽ�ʿγ�����
	char courseQqGroup[15];			//�γ�qqȺ
	Time course_time;				//�Ͽ�ʱ��
	

	//��ҵ
	int homework_num;		//��ҵ����
	Homework myHomework[30];	//��ҵ����
	char homework_filename[40];	//��ҵ�ļ���
	
	 //��������
	Folder electronicData;

	//��ǰ����
	char progress[20]= "            ";

	//����
	char examTime[40] = "            ";		//����ʱ��
	char examPlace[10]=" ";					//���Եص�
	Time exam_time;							//����ʱ��

	int course_ID;
};