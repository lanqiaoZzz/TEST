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
	//存储作业
	void saveHomework();
	//加载作业
	void uploadHomenwork();
	//清空作业
	void clear_disk();
	//获取作业
	int getHomework();
	//添加作业
	void addHomework();
	//删除作业
	void deleteHomework();
	//修改作业
	void modifyHomework();
	//老师查看作业
	void checkHomework();
	//学生查看作业
	void checkHomework(int id);
public:
	//从内从中加载电子资料

public:
	//将课程保存到内存
	void save_course(ofstream& ofs);
	static int ID;
private:
	char name[50];                   //课程名
	char courseTime[50];			//上课时间（格式：x~x周[周几第几节]）
	char coursePlace[10];			 //上课地点
	char paperData[50];				//纸质课程资料
	char courseQqGroup[15];			//课程qq群
	Time course_time;				//上课时间
	

	//作业
	int homework_num;		//作业数量
	Homework myHomework[30];	//作业数组
	char homework_filename[40];	//作业文件名
	
	 //电子资料
	Folder electronicData;

	//当前进度
	char progress[20]= "            ";

	//考试
	char examTime[40] = "            ";		//考试时间
	char examPlace[10]=" ";					//考试地点
	Time exam_time;							//考试时间

	int course_ID;
};