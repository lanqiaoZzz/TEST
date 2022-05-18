#pragma once
#include "File.h"
#include<iostream>
using namespace std;

//对文件进行管理
//文件始终按照上传时间顺序排列（增、删、改、查时需注意）
class Folder {

public:
	//构造函数:根据容量初始化文件夹
	Folder();

	//添加文件
	void addFile();

	//查看文件
	void print_info();

	//删除文件
	void deleteFile();

	//获取文件
	int getFile();

	//文件路径录入并判断
	void input_path(char* path);

	//修改文件
	void modifyFile();

	//在文件夹中对序号为index的文件进行去重，若重复，删去
	void checkDuplicate();

	void add_homework_file(char*& student_id, char*& homework_id);

	//在文件夹中查询给定文件名的文件
	void queryFileByName(char name[]);

	//按照不同关键字对文件进行排序：1.上传时间（由早到晚 由晚到早）
	void sortFileByTime();
private:
	int fileNumber;                //当前存储了多少个文件，用于确定文件序号
	File files[30];                        //多个文件组成的数组
};