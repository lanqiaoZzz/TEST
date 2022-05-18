#pragma once
#include "Course.h"
#include"Timer.h"
class TimeTable {
public:
	int getCoursenum() {
		return this->CourseNum;
	}
	
	Course* getmycourse() {
		return this->myCourse;
	}

	TimeTable();
public:
	//��ӿγ�
	void addCourse();
	//ɾ���γ�
	void deleteCourse();
	//�޸Ŀγ�
	void modifyCourse();
	//�鿴�γ���Ϣ
	void checkCourseInfo();
	//�оٿγ�
	void showCourses();
	//��ȡ�γ�
	int getCousrse();
public:
	//���ؿγ�
	void uploadCourse();
	//���տγ������в���
	void queryCourseByName();
	//���򣺸����Ͽ�ʱ��
	void sortByCourseTime();
	//���򣺸��ݿ���ʱ�䣨���絽��
	void sortByExamTime();	
private:
	Course myCourse[30];                //�ɿγ�����
	int CourseNum;                      //�γ���Ŀ
};