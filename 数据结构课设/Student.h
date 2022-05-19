#pragma once
#include "TimeTable.h"
#include"Time.h"
#include"Timer.h"
#include"Activity.h"
#include<iostream>
using namespace std;
class Student {
public:
	//获取电子资料文件夹
	Folder* get_electronicDataFoder();

	//添加电子资料
	void add_electronicData();

	//删除电子资料
	void delete_electronicData();

	//修改电子资料
	void modify_electronicData();

	//查看课程资料
	void check_electronicData();
public:
	//查看所有待交作业
	void checkHomework();

	//提交作业时mod=1，其他时候mod=0
	Folder* getHomeworkFoder(int mod);

	//提交作业
	void submit_homework();

	//查看已交作业
	 void check_paidhomework();

	//修改作业
	 void modify_paidhomework();
public:
	Student();

	Student(TimeTable* timetable);
public:
	//查看所有课程;
	void checkCourse();

	//通过课程名称查询课程信息
	void queryCourseByName();

public:
	//压缩某个电子课程资料/完成的作业
	void compressFile();

	//mod==0:获取作业文件夹 mod==1 获取电子资料文件夹
	void checkDuplicate(int mod);
public:
	//创建活动,按照活动时间升序进行插入
	void create_activitiy();

	//打印活动信息，按照活动时间升序
	void print_activity_info();

	//按时间查询活动,默认查询本周的活动（二分查找）
	void query_activity_bytime();

	//删除活动
	void delete_acticity();

	//时间冲突检测,在创建活动时被调用
	void time_conflict_detection(Time time);
public:
	static int ID;
private:
	int id;
	char name[20]; //姓名  xkx:将大小扩展到20
	TimeTable* table; //课程表,xkx:将课程表改为指针类型
public:
	static Activity* my_activity; //活动数组 
	static int activity_capacity;  //活动最大容量
	static int activity_num;//活动数量
};