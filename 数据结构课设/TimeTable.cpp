#include"TimeTable.h"
#include "Course.h"
#include<iostream>
#include<fstream>
using namespace std;
//构造函数：初始化课程表
TimeTable::TimeTable(){
	this->CourseNum = 0;
	this->uploadCourse();
}

void TimeTable::addCourse() {
	{
		char name[20];                        //课程名
		char courseTime[40];        //上课时间（格式：x~x周[周几第几节]）
		char coursePlace[10];        //上课地点
		char paperData[20];                //纸质课程资料
		char courseQqGroup[15]; //课程qq群   
		cout << "请输入课程名：" << endl;
		cin >> name;
		cout << "请输入上课时间（形如:1-16周[周一1-2节]" << endl;
		cin >> courseTime;

		cout<<"请输入五个数字，分别表示 a-b周[周Cd-e节]" << endl;
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		Time time;
		time.SetTime(a, b, c, d, e, 0);

		cout << "请输入上课地点：" << endl;
		cin >> coursePlace;
		cout << "请输入纸质课程资料：" << endl;
		cin >> paperData;
		cout << "请输入课程qq群 ：" << endl;
		cin >> courseQqGroup;

		Course newcourse(name, courseTime, coursePlace, paperData, courseQqGroup,time);
		this->myCourse[this->CourseNum] = newcourse;

		this->CourseNum++;
		
		cout << "添加成功！" << endl;
		system("pause");
		
	}
}

void TimeTable::deleteCourse() {
	int index = this->getCousrse();

	if (index == -1) {
		cout << "删除失败!" << endl;
		return;
	}
	
	for (int i = index; i < this->CourseNum; i++)
	{
		this->myCourse[i] = this->myCourse[i + 1];
	}

	this->CourseNum--;
	cout << "删除成功" << endl;
	system("pause");
}

void TimeTable::modifyCourse() {
	int index = this->getCousrse();
	char name[50];                        //课程名
	char courseTime[50];        //上课时间（格式：x~x周[周几第几节]）
	char coursePlace[10];        //上课地点
	char paperData[50];                //纸质课程资料
	char courseQqGroup[15]; //课程qq群   
	cout << "请输入新的课程名：" << endl;
	cin >> name;
	cout << "请输入新的上课时间（形如 1-16周[周一1-2节]" << endl;
	cin >> courseTime;

	cout << "请输入五个数字，分别表示 a-b周[周Cd-e节]" << endl;
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	Time time;
	time.SetTime(a, b, c, d, e, 0);

	cout << "请输入新的上课地点：" << endl;
	cin >> coursePlace;
	cout << "请输入新的纸质课程资料：" << endl;
	cin >> paperData;
	cout << "请输入新的课程qq群 ：" << endl;
	cin >> courseQqGroup;

	Course newcourse(name, courseTime, coursePlace, paperData, courseQqGroup, time);
	this->myCourse[index] = newcourse;
	
	cout << "修改成功！" << endl;
	system("pause");
}

void TimeTable::checkCourseInfo() {
	if (this->CourseNum == 0) {
		cout << "当前还没有任何课程！" << endl;
		return;
	}
	cout << "课程名称\t上课时间\t\t上课地点\t纸质资料\t\t当前进度\t课程群\t\t考试地点 \t考试时间" << endl;
	char courseInfo[150];
	for (int i = 0; i < this->CourseNum; i++) {
		courseInfo[0] = 0;
		this->myCourse[i].get_info(courseInfo);
		cout << courseInfo << endl;
	}
}

void TimeTable::showCourses() {
	for (int i = 0; i < this->CourseNum; i++) {
		cout << "课程" << i + 1 <<":\t"
			<< this->myCourse[i].getname()
			<< endl;
	}
	
}

int TimeTable::getCousrse(){
	if (this->CourseNum == 0) {
		cout << "当前还没有任何课程！" << endl;
		return -1;
	}
	this->showCourses();

	cout << "请输入课程编号" << endl;

	int index;
	cin >> index;

	while (index<1||index>this->CourseNum)
	{
		cout << "无效输入，请重新输入" << endl;
		cin >> index;
	}
	
	return index-1;
}

void TimeTable::uploadCourse() {
	ifstream ifs;
	ifs.open("课程.txt", ios::in);
	ifs >> this->CourseNum;
	for (int i = 0; i < this->CourseNum; i++) {
		char name[50];             
		char courseTime[50];       
		char coursePlace[10];      
		char paperData[50];			
		char courseQqGroup[15];	
		char progress[20];
		char examTime[50];
		char examplace[20];
		ifs >> name;
		ifs >> courseTime;

		int a, b, c, d, e;
		ifs >> a >> b >> c >> d >> e;
		Time time;
		time.SetTime(a, b, c, d, e, 0);

		ifs >> coursePlace;
		ifs >> paperData;
		ifs >> progress;
		ifs >> courseQqGroup;

		ifs >> examTime;
		ifs >> a >> c >> d >> e;
		b = a;
		ifs >> examplace;
		Time ET;
		ET.SetTime(a, b, c, d, e, 1);
		Course newcourse(name, courseTime, coursePlace, paperData, courseQqGroup, time);
		newcourse.set_examTime(examTime);
		newcourse.set_exam_time(ET);
		newcourse.set_progress(progress);
		newcourse.set_examPlace(examplace);
		this->myCourse[i] = newcourse;
	}
}

void TimeTable::queryCourseByName()
{
	bool flag = false;
	char courseName[50];
	char courseInfo[200];

	cout << "请输入您要查找的课程名称" << endl;
	cin >> courseName;
	
	cout << "课程名称\t上课时间\t\t上课地点\t纸质资料\t\t当前进度\t课程群\t\t考试地点 \t考试时间" << endl;

	for (int i = 0; i < this->CourseNum; i++) 
	{
		if(strcmp(this->myCourse[i].getname(), courseName)==0)
		{
			flag = true;
			this->myCourse[i].get_info(courseInfo);
			cout <<courseInfo<< endl;
		}
	}

	if (!flag)
	{
		cout << "查找失败 查无此课！" << endl;
		return;
	}

	system("pause");
}

void TimeTable::sortByCourseTime() {
	Time time1;
	Time time2;
	Course course;
	for (int i = 0; i < this->CourseNum - 1; i++)
	{
		time1 = this->myCourse[i].get_course_time();

		for (int j = i + 1; j < this->CourseNum; j++) {

			time2 = this->myCourse[j].get_course_time();

			if (time1.compareTo(time2)==0) {
				course = this->myCourse[j];
				this->myCourse[j] = this->myCourse[i];
				this->myCourse[i] = course;
				time1 = this->myCourse[i].get_course_time();
			}
		}
	}
}

void TimeTable::sortByExamTime() {
	Time time1;
	Time time2;
	Course course;
	for (int i = 0; i < this->CourseNum - 1; i++)
	{
		time1 = this->myCourse[i].get_exam_time();

		for (int j = i + 1; j < this->CourseNum; j++) {

			time2 = this->myCourse[j].get_exam_time();

			if (time1.is_clear(time2) == 0) {
				course = this->myCourse[j];
				this->myCourse[j] = this->myCourse[i];
				this->myCourse[i] = course;
				time1 = this->myCourse[i].get_exam_time();
			}
		}
	}
}
