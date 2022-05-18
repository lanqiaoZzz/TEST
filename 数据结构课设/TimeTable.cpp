#include"TimeTable.h"
#include "Course.h"
#include<iostream>
#include<fstream>
using namespace std;
//���캯������ʼ���γ̱�
TimeTable::TimeTable(){
	this->CourseNum = 0;
	this->uploadCourse();
}

void TimeTable::addCourse() {
	{
		char name[20];                        //�γ���
		char courseTime[40];        //�Ͽ�ʱ�䣨��ʽ��x~x��[�ܼ��ڼ���]��
		char coursePlace[10];        //�Ͽεص�
		char paperData[20];                //ֽ�ʿγ�����
		char courseQqGroup[15]; //�γ�qqȺ   
		cout << "������γ�����" << endl;
		cin >> name;
		cout << "�������Ͽ�ʱ�䣨����:1-16��[��һ1-2��]" << endl;
		cin >> courseTime;

		cout<<"������������֣��ֱ��ʾ a-b��[��Cd-e��]" << endl;
		int a, b, c, d, e;
		cin >> a >> b >> c >> d >> e;
		Time time;
		time.SetTime(a, b, c, d, e, 0);

		cout << "�������Ͽεص㣺" << endl;
		cin >> coursePlace;
		cout << "������ֽ�ʿγ����ϣ�" << endl;
		cin >> paperData;
		cout << "������γ�qqȺ ��" << endl;
		cin >> courseQqGroup;

		Course newcourse(name, courseTime, coursePlace, paperData, courseQqGroup,time);
		this->myCourse[this->CourseNum] = newcourse;

		this->CourseNum++;
		
		cout << "��ӳɹ���" << endl;
		system("pause");
		
	}
}

void TimeTable::deleteCourse() {
	int index = this->getCousrse();

	if (index == -1) {
		cout << "ɾ��ʧ��!" << endl;
		return;
	}
	
	for (int i = index; i < this->CourseNum; i++)
	{
		this->myCourse[i] = this->myCourse[i + 1];
	}

	this->CourseNum--;
	cout << "ɾ���ɹ�" << endl;
	system("pause");
}

void TimeTable::modifyCourse() {
	int index = this->getCousrse();
	char name[50];                        //�γ���
	char courseTime[50];        //�Ͽ�ʱ�䣨��ʽ��x~x��[�ܼ��ڼ���]��
	char coursePlace[10];        //�Ͽεص�
	char paperData[50];                //ֽ�ʿγ�����
	char courseQqGroup[15]; //�γ�qqȺ   
	cout << "�������µĿγ�����" << endl;
	cin >> name;
	cout << "�������µ��Ͽ�ʱ�䣨���� 1-16��[��һ1-2��]" << endl;
	cin >> courseTime;

	cout << "������������֣��ֱ��ʾ a-b��[��Cd-e��]" << endl;
	int a, b, c, d, e;
	cin >> a >> b >> c >> d >> e;
	Time time;
	time.SetTime(a, b, c, d, e, 0);

	cout << "�������µ��Ͽεص㣺" << endl;
	cin >> coursePlace;
	cout << "�������µ�ֽ�ʿγ����ϣ�" << endl;
	cin >> paperData;
	cout << "�������µĿγ�qqȺ ��" << endl;
	cin >> courseQqGroup;

	Course newcourse(name, courseTime, coursePlace, paperData, courseQqGroup, time);
	this->myCourse[index] = newcourse;
	
	cout << "�޸ĳɹ���" << endl;
	system("pause");
}

void TimeTable::checkCourseInfo() {
	if (this->CourseNum == 0) {
		cout << "��ǰ��û���κογ̣�" << endl;
		return;
	}
	cout << "�γ�����\t�Ͽ�ʱ��\t\t�Ͽεص�\tֽ������\t\t��ǰ����\t�γ�Ⱥ\t\t���Եص� \t����ʱ��" << endl;
	char courseInfo[150];
	for (int i = 0; i < this->CourseNum; i++) {
		courseInfo[0] = 0;
		this->myCourse[i].get_info(courseInfo);
		cout << courseInfo << endl;
	}
}

void TimeTable::showCourses() {
	for (int i = 0; i < this->CourseNum; i++) {
		cout << "�γ�" << i + 1 <<":\t"
			<< this->myCourse[i].getname()
			<< endl;
	}
	
}

int TimeTable::getCousrse(){
	if (this->CourseNum == 0) {
		cout << "��ǰ��û���κογ̣�" << endl;
		return -1;
	}
	this->showCourses();

	cout << "������γ̱��" << endl;

	int index;
	cin >> index;

	while (index<1||index>this->CourseNum)
	{
		cout << "��Ч���룬����������" << endl;
		cin >> index;
	}
	
	return index-1;
}

void TimeTable::uploadCourse() {
	ifstream ifs;
	ifs.open("�γ�.txt", ios::in);
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

	cout << "��������Ҫ���ҵĿγ�����" << endl;
	cin >> courseName;
	
	cout << "�γ�����\t�Ͽ�ʱ��\t\t�Ͽεص�\tֽ������\t\t��ǰ����\t�γ�Ⱥ\t\t���Եص� \t����ʱ��" << endl;

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
		cout << "����ʧ�� ���޴˿Σ�" << endl;
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
