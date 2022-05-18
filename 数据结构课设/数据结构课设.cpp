#define _CRT_SECURE_NO_WARNINGS
#include"TimeTable.h"
#include <iostream>
#include"Student.h"
#include"Teacher.h"
#include<fstream>
void StudentEnd(Student* S);
void TeacherEnd(Teacher* T);
int main()
{
	TimeTable* T=new TimeTable;
	Student* S = new Student(T);
	Teacher* Te = new Teacher(T);

	cout << "********************************************" << endl;
	cout << "*******  欢迎使用课程信心管理系统！ ********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.管理员  *******************" << endl;
	cout << "*************  2.学生  *********************" << endl;
	cout << "********************************************" << endl;
	cout << endl;

	int choice = 0;
	cin >> choice;
	cin.get();
	switch (choice)
	{
	case 0:return 0; break;
	case 1:TeacherEnd(Te);  cout << "按回车键继续" << endl;  cin.get(); break;
	case 2:StudentEnd(S);  cout << "按回车键继续" << endl;  cin.get(); break;
	}
	system("cls");
}
void StudentEnd(Student* S) {
	system("cls");
	int choice;
	while (1)
	{
		cout << "********************************************" << endl;
		cout << "*** 欢迎使用课程信息管理系统！（学生） *****" << endl;
		cout << "*************  00.退出管理程序  *************" << endl;
		cout << "*************  01.显示课程信息  *************" << endl;
		cout << "*************  02.查找课程信息  *************" << endl;
		cout << "*************  03.显示作业信息  *************" << endl;
		cout << "*************  04.提交课程作业  *************" << endl;
		cout << "*************  05.课程作业压缩  ************"  << endl;
		cout << "*************  06.查看电子资料  *************" << endl;
		cout << "*************  07.上传电子资料  *************" << endl;
		cout << "*************  08.删除电子资料  *************" << endl;
		cout << "*************  09.修改电子资料  *************" << endl;
		cout << "*************  10.电子资料压缩  *************" << endl;
		cout << "*************  11.电子资料查重  *************" << endl;
		cout << "********************************************" << endl;
		cout << endl;

		cout << endl << "请输入您的选择:" << endl;
		cin >> choice;
		cin.get();
		switch (choice)
		{
		case 0:return; break;
		case 1:S->checkCourse();			cout << "按回车键继续" << endl;  cin.get(); break;
		case 2:S->queryCourseByName();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 3:S->checkHomework();			cout << "按回车键继续" << endl;  cin.get(); break;
		case 4:S->submit_homework();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 5:;	cout << "按回车键继续" << endl;  cin.get(); break;
		case 6:S->check_electronicData();	cout << "按回车键继续" << endl;  cin.get(); break;
		case 7:S->add_electronicData();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 8:S->delete_electronicData();	cout << "按回车键继续" << endl;  cin.get(); break;
		case 9:S->modify_electronicData();	cout << "按回车键继续" << endl;  cin.get(); break;
		case 10:;	cout << "按回车键继续" << endl;  cin.get(); break;
		case 11:S->checkDuplicate(1);		cout << "按回车键继续" << endl;  cin.get(); break;
		}
		system("cls");
	}
}
void TeacherEnd(Teacher* T) {
	system("cls");
	int choice;
	while (1)
	{
		cout << "********************************************" << endl;
		cout << "*** 欢迎使用课程信息管理系统！（管理员） ***" << endl;
		cout << "*************  00.退出管理程序  *************" << endl;
		cout << "*************  01.增加课程信息  *************" << endl;
		cout << "*************  02.显示课程信息  *************" << endl;
		cout << "*************  03.删除课程信息  *************" << endl;
		cout << "*************  04.修改课程信息  *************" << endl;
		cout << "*************  05.布置课程作业  *************" << endl;
		cout << "*************  06.查看课程作业  *************" << endl;
		cout << "*************  07.删除课程作业  *************" << endl;
		cout << "*************  08.修改课程作业  *************" << endl;
		cout << "*************  09.发布考试信息  *************" << endl;
		cout << "*************  10.更改课程进度  ************" << endl;
		cout << "********************************************" << endl;
		cout << endl;

		cout << endl << "请输入您的选择:" << endl;
		cin >> choice;
		cin.get();
		switch (choice)
		{
		case 0:return; break;
		case 1:T->releaseNewCourse();	cout << "按回车键继续" << endl;  cin.get(); break;
		case 2:T->checkCourse();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 3:T->deleteCourse();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 4:T->modifyCourse();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 5:T->assignHomework();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 6:T->check_homework();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 7:T->delete_homework();	cout << "按回车键继续" << endl;  cin.get(); break;
		case 8:T->modify_homework();	cout << "按回车键继续" << endl;  cin.get(); break;
		case 9:T->Release_exam();		cout << "按回车键继续" << endl;  cin.get(); break;
		case 10:T->modify_progress();	cout << "按回车键继续" << endl;  cin.get(); break;
		}
		system("cls");
	}
}

