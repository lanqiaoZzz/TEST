#pragma once
#include "TimeTable.h"
#include<iostream>
#include"Timer.h"
#include"Time.h"
using namespace std;
class Teacher {
public:
	//布置作业
	void assignHomework();
	//删除作业
	void delete_homework();
	//修改作业
	void modify_homework();
	//查看作业
	void check_homework();
public:
	//发布考试
	void Release_exam();
	//修改考试信息
	void modify_exam();
public:
	//更改课程进度
	void modify_progress();
public:
	
	Teacher();
	Teacher(TimeTable *table);
	//发布一门新课程
	void releaseNewCourse();
	//修改课程信息
	void modifyCourse();
	//查看自己上的课程
	void checkCourse();
	//删除课程
	void deleteCourse();
	
private:
	TimeTable* table;
	int id; //职工号
	char name[20]; //姓名
	char course_filename[40];//课程文件名
};