#pragma once
#include "TimeTable.h"
#include<iostream>
#include"Timer.h"
#include"Time.h"
using namespace std;
class Teacher {
public:
	//������ҵ
	void assignHomework();
	//ɾ����ҵ
	void delete_homework();
	//�޸���ҵ
	void modify_homework();
	//�鿴��ҵ
	void check_homework();
public:
	//��������
	void Release_exam();
	//�޸Ŀ�����Ϣ
	void modify_exam();
public:
	//���Ŀγ̽���
	void modify_progress();
public:
	
	Teacher();
	Teacher(TimeTable *table);
	//����һ���¿γ�
	void releaseNewCourse();
	//�޸Ŀγ���Ϣ
	void modifyCourse();
	//�鿴�Լ��ϵĿγ�
	void checkCourse();
	//ɾ���γ�
	void deleteCourse();
	
private:
	TimeTable* table;
	int id; //ְ����
	char name[20]; //����
	char course_filename[40];//�γ��ļ���
};