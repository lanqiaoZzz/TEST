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

void Student::checkHomework() {
	Course* courses = this->table->getmycourse();
	int n = this->table->getCoursenum();
	for (int i = 0; i < n; i++)
	{
		cout << "课程" << i + 1<<": ";
		courses[i].checkHomework(this->id);
	}
	cout << "********************************************" << endl;
	cout << "*************  0.退出  *********************" << endl;
	cout << "*************  1.提交作业  *****************" << endl;
	cout << "*************  2.查看已交作业  *************" << endl;
	cout << "*************  3.修改已交作业  *************" << endl;
	cout << "*************  4.已交作业查重  *************" << endl;
	cout << "********************************************" << endl;
	cout<< "请输入您的选择" << endl;
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
	cout << "请输入课程号" << endl;
	int Cindex;
	cin >> Cindex;
	cout << "请输入作业号" << endl;
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
	cout << "请输入您要上传的文件的数量：" << endl;
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

//创建活动,按照活动时间升序进行插入
/*录入活动时间时，询问是否重复*/
void Student::create_activitiy() {

}

////打印活动信息，按照活动时间升序
//void Student::print_activity_info() {
//	for (int i = 0; i < activity_num; i++) {
//		cout << my_activity[i]->getName();
//			if (my_activity[i]->getType() == 0) cout << " [个人活动] ";
//			else cout << " [集体活动] ";
//		cout << my_activity[i]->getTimeword() << " " << my_activity[i]->getPlace() << endl;
//	}

	////按时间查询活动,默认查询本周的活动（二分查找）
	//int Student::query_activity_bytime(int weeks[], ) {

	//}

	//删除活动
	/*void Student::delete_acticity() {

	}*/

	//时间冲突检测,在创建活动时被调用
	//void Student::time_conflict_detection(Time time) {

	//}