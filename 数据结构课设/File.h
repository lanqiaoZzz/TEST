#pragma once
#include<iostream>
#include<fstream>
#include"Timer.h"
using namespace std;
class File {

public:
	
	File(char* file_path, char* file_name) {
		strcpy(this->name, file_name);               //文件名
		strcpy(this->path, file_path);				 //文件路径
		this->fileWeek = Timer::curWeek;
		this->fileTime = Timer::curTime;
		this->fileDay = Timer::curDay;
	}

	File() {};

	void setname(char* filename) {
		strcpy(this->name, filename);
	}

	void setpath(char* filepath) {
		strcpy(this->path, filepath);
	}
	
	void refreshtime() {
		this->fileWeek = Timer::curWeek;
		this->fileTime = Timer::curTime;
		this->fileDay = Timer::curDay;
	}

	char* getname() {
		return this->name;
	}

	char* getpath() {
		return this->path;
	}

	int getsize() {
		return this->size;
	}

	void setsize(int size) {
		this->size = size;
	}

	//和文件b重复返回true
	bool checkDuplicate(File b);
private:
	char name[50];              //文件名
	char path[100];				//文件路径
	int	size=100;					//文件大小(字节)
	//上传时间
	int fileWeek;
	int fileDay;
	int fileTime;
};