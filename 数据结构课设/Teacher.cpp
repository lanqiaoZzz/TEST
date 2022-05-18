#include"Teacher.h"
Teacher::Teacher() {

}
Teacher::Teacher(TimeTable* table) {
	this->table = table;
}

void Teacher::assignHomework() {
	int index = this->table->getCousrse();
	Course* courses = this->table->getmycourse();
	courses[index].addHomework();
}

void Teacher::delete_homework() {
	int courseindex = this->table->getCousrse();
	Course* courses = this->table->getmycourse();
	courses[courseindex].deleteHomework();
}

void Teacher::modify_homework() {
	Course* courses = this->table->getmycourse();
	int index = this->table->getCousrse();
	courses[index].modifyHomework();
}

void Teacher::check_homework()
{
	int coursenum = this->table->getCoursenum();
	Course* courses = this->table->getmycourse();
	for (int i = 0; i < coursenum; i++)
	{
		courses[i].checkHomework();
	}
}

void Teacher::Release_exam() {
	int C = this->table->getCousrse();
	Course* courses = this->table->getmycourse();
	char time[50];
	char place[50];
	cout << "�����뿼��ʱ��,�磺��17����һ8����10��" << endl;
	cin >> time;
	cout << "������4�����֣��ֱ��ʾ ��A����Bx����y��" << endl;
	int a, b, c, d, e;
	cin >> a >> c >> d >> e;
	b = a;
	Time T;
	T.SetTime(a, b, c, d, e, 1);

	cout << "�����뿼�Եص�" << endl;
	cin >> place;
	
	courses[C].set_examTime(time);
	courses[C].set_exam_time(T);
	courses[C].set_examPlace(place);

	cout << "���ѳɹ�������һ�ſ��ԣ�" <<endl;
	system("pause");
}

void Teacher::modify_exam() {
	this->Release_exam();
}

void Teacher::modify_progress() {
	int C = this->table->getCousrse();
	Course* courses = this->table->getmycourse();
	char progress[50];
	cout << "�����뵱ǰ����" << endl;
	cin >> progress;
	courses[C].set_progress(progress);
	cout << "�����޸ĳɹ�" << endl;
	system("pause");
}

void Teacher::modifyCourse() {
	this->table->modifyCourse();
}

void Teacher::checkCourse() {
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

void Teacher::releaseNewCourse() {
	this->table->addCourse();
}

void Teacher::deleteCourse() {
	this->table->deleteCourse();
}


