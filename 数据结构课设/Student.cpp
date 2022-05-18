#include"Student.h"
int Student::ID = 0;

Student::Student() {

}
Student::Student(TimeTable* timetable) {
	this->table = timetable;
	this->id = this->ID;
	this->ID++;
}

void Student::queryCourseByName() {
	this->table->queryCourseByName();
}

void Student::checkCourse() {
	this->table->checkCourseInfo();

	int mod;

	cout << "**************************************************" << endl;
	cout << "*************  0.�˳�  ***************************" << endl;
	cout << "*************  1.������ʱ���������  *************" << endl;
	cout << "*************  2.���Ͽ�ʱ���������  *************" << endl;
	cout << "**************************************************" << endl;
	cout << "����������ѡ��" << endl;

	cin >> mod;
	if (mod == 2)
		this->table->sortByCourseTime();
	else if (mod == 1)
		this->table->sortByExamTime();
	else
		return;
	system("cls");
	this->table->checkCourseInfo();
	system("pause");
	return;
}

void Student::checkHomework() {
	Course* courses = this->table->getmycourse();
	int n = this->table->getCoursenum();
	for (int i = 0; i < n; i++)
	{
		cout << "�γ�" << i + 1<<": ";
		courses[i].checkHomework(this->id);
	}
	cout << "********************************************" << endl;
	cout << "*************  0.�˳�  *********************" << endl;
	cout << "*************  1.�ύ��ҵ  *****************" << endl;
	cout << "*************  2.�鿴�ѽ���ҵ  *************" << endl;
	cout << "*************  3.�޸��ѽ���ҵ  *************" << endl;
	cout << "*************  4.�ѽ���ҵ����  *************" << endl;
	cout << "********************************************" << endl;
	cout<< "����������ѡ��" << endl;
	int choose = 0;
	cin >> choose;
	switch (choose)
	{
	case 1:
		this->submit_homework();
		break;
	case 2:
		this->check_paidhomework();
		break;
	case 3:
		this->modify_paidhomework();
		break;
	case 4:
		this->checkDuplicate(0);
		break;
	default:
		break;
	}
}

Folder* Student::getHomeworkFoder(int mod) {
	cout << "������γ̺�" << endl;
	int Cindex;
	cin >> Cindex;
	cout << "��������ҵ��" << endl;
	int Hindex;
	cin >> Hindex;

	Cindex--;
	Hindex--;

	Course* courses=this->table->getmycourse();
	Homework* homeworks=courses[Cindex].get_myHomework();
	if(mod==1)
		homeworks[Hindex].set_state(this->id);
	return homeworks[Hindex].get_paidHomework();
}

void Student::submit_homework() {
	Folder* folder = this->getHomeworkFoder(1);
	folder->addFile();
	system("pause");
}

void Student::check_paidhomework() {
	Folder* folder = this->getHomeworkFoder(0);
	folder->print_info();
	system("pause");
}

void Student::modify_paidhomework() {
	Folder* folder = this->getHomeworkFoder(0);
	folder->modifyFile();
	system("pause");
}

Folder* Student::get_electronicDataFoder() {
	Course* C= this->table->getmycourse();
	int  n = this->table->getCousrse();
	return C[n].getelectronicData();
}

void Student::add_electronicData() {
	Folder* folder = this->get_electronicDataFoder();
	int length;
	cout << "��������Ҫ�ϴ����ļ���������" << endl;
	cin >> length;
	for (int i = 0; i < length; i++)
	{
		folder->addFile();
	}
	system("pause");
}

void Student::delete_electronicData() {
	Folder* folder = this->get_electronicDataFoder();
	folder->deleteFile();
	system("pause");
}

void Student::modify_electronicData() {
	Folder* folder = this->get_electronicDataFoder();
	folder->modifyFile();
	system("pause");
}

void Student::check_electronicData() {
	Folder* folder = this->get_electronicDataFoder();
	folder->print_info();
	system("pause");
}

void Student::checkDuplicate(int mod) {
	Folder *F;
	if (mod == 0) {
		F = this->getHomeworkFoder(0);
	}
	else
	{
		F = this->get_electronicDataFoder();
	}
	F->checkDuplicate();
	system("pause");
}

//�����,���ջʱ��������в���
/*¼��ʱ��ʱ��ѯ���Ƿ��ظ�*/
void Student::create_activitiy() {

}

////��ӡ���Ϣ�����ջʱ������
//void Student::print_activity_info() {
//	for (int i = 0; i < activity_num; i++) {
//		cout << my_activity[i]->getName();
//			if (my_activity[i]->getType() == 0) cout << " [���˻] ";
//			else cout << " [����] ";
//		cout << my_activity[i]->getTimeword() << " " << my_activity[i]->getPlace() << endl;
//	}

	////��ʱ���ѯ�,Ĭ�ϲ�ѯ���ܵĻ�����ֲ��ң�
	//int Student::query_activity_bytime(int weeks[], ) {

	//}

	//ɾ���
	/*void Student::delete_acticity() {

	}*/

	//ʱ���ͻ���,�ڴ����ʱ������
	//void Student::time_conflict_detection(Time time) {

	//}