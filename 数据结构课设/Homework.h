#pragma once
//#include "Folder.h"
#include<string.h>
#include<iostream>
#include<fstream>
#include"Folder.h"
#include"Timer.h"
using namespace std;
//已交作业 与 待交作业
class Homework {

public:
	Homework() {
		for (int i = 0; i < 30; i++)
		{
			this->state[i] = 0;
		}
	};

	Homework(char unpaidHomework[]) {
		strcpy(this->unpaidHomework, unpaidHomework);
		for (int i = 0; i < 30; i++)
		{
			this->state[i] = 0;
		}
	}

	void set_unpaidHomework(char unpaidHomework[]) {
		strcpy(this->unpaidHomework, unpaidHomework);
	}

	char* get_unpaidHomework() {
		return this->unpaidHomework;
	}
	
	int get_state(int index) {
		return this->state[index];
	}

	void set_state(int index) {
		this->state[index] = 1;
	}
	
	Folder* get_paidHomework() {
		return &this->paidHomework;
	}
private:
	char unpaidHomework[100];	//待交作业
	int state[30];				//分别存储每个学生的作业状态，0表示未提交，1表示提交
	Folder paidHomework;		//已交作业
};