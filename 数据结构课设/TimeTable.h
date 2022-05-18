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
	//添加课程
	void addCourse();
	//删除课程
	void deleteCourse();
	//修改课程
	void modifyCourse();
	//查看课程信息
	void checkCourseInfo();
	//列举课程
	void showCourses();
	//获取课程
	int getCousrse();
public:
	//加载课程
	void uploadCourse();
	//按照课程名进行查找
	void queryCourseByName();
	//排序：根据上课时间
	void sortByCourseTime();
	//排序：根据考试时间（从早到晚）
	void sortByExamTime();	
private:
	Course myCourse[30];                //由课程数组
	int CourseNum;                      //课程数目
};