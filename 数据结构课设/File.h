#pragma once
#include<iostream>
#include<fstream>
#include"Timer.h"
using namespace std;
class File {

public:
	
	File(char* file_path, char* file_name) {
		strcpy(this->name, file_name);               //�ļ���
		strcpy(this->path, file_path);				 //�ļ�·��
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

	//���ļ�b�ظ�����true
	bool checkDuplicate(File b);
private:
	char name[50];              //�ļ���
	char path[100];				//�ļ�·��
	int	size=100;					//�ļ���С(�ֽ�)
	//�ϴ�ʱ��
	int fileWeek;
	int fileDay;
	int fileTime;
};