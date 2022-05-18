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
	cout << "请输入考试时间,如：第17周周一8点至10点" << endl;
	cin >> time;
	cout << "请输入4个数字，分别表示 第A周周Bx点至y点" << endl;
	int a, b, c, d, e;
	cin >> a >> c >> d >> e;
	b = a;
	Time T;
	T.SetTime(a, b, c, d, e, 1);

	cout << "请输入考试地点" << endl;
	cin >> place;
	
	courses[C].set_examTime(time);
	courses[C].set_exam_time(T);
	courses[C].set_examPlace(place);

	cout << "您已成功发布了一门考试！" <<endl;
	system("pause");
}

void Teacher::modify_exam() {
	this->Release_exam();
}

void Teacher::modify_progress() {
	int C = this->table->getCousrse();
	Course* courses = this->table->getmycourse();
	char progress[50];
	cout << "请输入当前进度" << endl;
	cin >> progress;
	courses[C].set_progress(progress);
	cout << "进度修改成功" << endl;
	system("pause");
}

void Teacher::modifyCourse() {
	this->table->modifyCourse();
}

void Teacher::checkCourse() {
	this->table->checkCourseInfo();

	int mod;

	cout << "**************************************************" << endl;
	cout << "*************  0.退出  ***************************" << endl;
	cout << "*************  1.按考试时间进行排序  *************" << endl;
	cout << "*************  2.按上课时间进行排序  *************" << endl;
	cout << "**************************************************" << endl;
	cout << "请输入您的选择" << endl;

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


