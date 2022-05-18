#pragma once
#include "File.h"
#include<iostream>
using namespace std;

//���ļ����й���
//�ļ�ʼ�հ����ϴ�ʱ��˳�����У�����ɾ���ġ���ʱ��ע�⣩
class Folder {

public:
	//���캯��:����������ʼ���ļ���
	Folder();

	//����ļ�
	void addFile();

	//�鿴�ļ�
	void print_info();

	//ɾ���ļ�
	void deleteFile();

	//��ȡ�ļ�
	int getFile();

	//�ļ�·��¼�벢�ж�
	void input_path(char* path);

	//�޸��ļ�
	void modifyFile();

	//���ļ����ж����Ϊindex���ļ�����ȥ�أ����ظ���ɾȥ
	void checkDuplicate();

	void add_homework_file(char*& student_id, char*& homework_id);

	//���ļ����в�ѯ�����ļ������ļ�
	void queryFileByName(char name[]);

	//���ղ�ͬ�ؼ��ֶ��ļ���������1.�ϴ�ʱ�䣨���絽�� �����磩
	void sortFileByTime();
private:
	int fileNumber;                //��ǰ�洢�˶��ٸ��ļ�������ȷ���ļ����
	File files[30];                        //����ļ���ɵ�����
};