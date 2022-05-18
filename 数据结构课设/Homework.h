#pragma once
//#include "Folder.h"
#include<string.h>
#include<iostream>
#include<fstream>
#include"Folder.h"
#include"Timer.h"
using namespace std;
//�ѽ���ҵ �� ������ҵ
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
	char unpaidHomework[100];	//������ҵ
	int state[30];				//�ֱ�洢ÿ��ѧ������ҵ״̬��0��ʾδ�ύ��1��ʾ�ύ
	Folder paidHomework;		//�ѽ���ҵ
};