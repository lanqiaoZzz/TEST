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

void Student::create_activitiy() {
	cout << "请输入你的活动个数:";
	cin >> this->activity_num;
	for (int i = 0; i < this->activity_num; i++)
	{
		Activity** newmyactivity = new Activity *[i + 1];
		if (this->my_activity != NULL)
		{
			for (int j = 0; j < i; j++)
			{
				newmyactivity[j] = this->my_activity[j];
			}
		}
		//录入活动信息
		int type = 0, setClock = 0, x = 0, y = 0, a = 0, b = 0;
		char name[10], timeword[15], place[10];

		Time time;
		cout << "请输入活动名：" << endl;
		cin >> name;
		cout << "请输入活动类型（0表示个人活动，1表示集体活动）：" << endl;
		cin >> type;
		cout << "请输入活动时间（自然语言）：" << endl;
		cin >> timeword;
		cout << "请输入活动时间：（格式：x y a b m n，表示第x周-第y周周a到周bm点-n点）";
		cin >> x >> y >> a >> b >> time.startTime >> time.endTime;
		for (int m = x; m <= y; m++) time.week[m] = 1;
		for (int m = a; m <= b; m++) time.day[m] = 1;
		cout << "请输入活动地点：" << endl;
		cin >> place;
		cout << "请输入是否设定闹钟（0不设定，1设定）：" << endl;
		cin >> setClock;
		//创建新活动
		Activity* newactivity = new Activity(type, name, timeword, time, place, setClock);
		newmyactivity[i] = newactivity;
		delete[] this->my_activity;
		this->my_activity = newmyactivity;
		cout << "您已成功添加一项活动" << endl;
		if (i != 0)
		{
			for (int j = 0; j < i; j++)
			{
				if (time.conflict_detection(this->my_activity[i]->getTime1(), this->my_activity[j]->getTime1())) cout << "与现有活动时间冲突！" << endl;
				if (time.is_clear(this->my_activity[i]->getTime1(), this->my_activity[j]->getTime1()))
				{
					my_activity[i] = my_activity[j];
					my_activity[j] = newactivity;
				}
			}
		}
	}
}

void Student::print_activity_info() {
	for (int i = 0; i < activity_num; i++) {
		cout << my_activity[i]->getName();
		if (my_activity[i]->getType() == 0) cout << " [个人活动] ";
		else cout << " [集体活动] ";
		cout << my_activity[i]->getTimeword() << " " << my_activity[i]->getPlace() << endl;
	}
}

void Student::query_activity_bytime(Activity** my_activity, int low, int high, int curWeek) {
	Time time;

	int mid = 0;
	while (high >= low)
	{
		mid = (high + low) / 2;
		Time time1, time2;
		time1.week[curWeek] = 1;
		time1.day[1] = 1;
		time1.startTime = 1;
		time1.endTime = 1;
		time2.week[curWeek] = 1;
		time2.day[7] = 7;
		time2.startTime = 24;
		time2.endTime = 24;
		if (time.is_clear(my_activity[mid]->getTime1(), time1))
		{
			low = mid + 1;
		}
		else if (time.is_clear(time2, my_activity[mid]->getTime1()))
		{
			high = mid - 1;
		}
		else break;
	}
	for (int i = low; i <= high; i++)
	{
		char* temp;
		temp = my_activity[i]->getName();
		printf("%s", temp);
		//cout << my_activity[i]->getName();
		if (my_activity[i]->getType() == 0) cout << " [个人活动] ";
		else cout << " [集体活动] ";


		temp = my_activity[i]->getTimeword();
		printf("%s ", temp);

		temp = my_activity[i]->getPlace();
		printf("%s", temp);
		//cout << my_activity[i]->getTimeword() << " " << my_activity[i]->getPlace() << endl;

		cout << endl;
	}
}

void Student::delete_activity(Activity* p) {
	for (int i = 0; this->my_activity[i] != p; i++)
		if (i >= 0 && i < this->activity_num)
		{
			//用指针p指向该活动所在空间
			Activity* p = this->my_activity[i];
			//删除：数组向前覆盖
			for (int j = i; j < this->activity_num - 1; j++)
			{
				this->my_activity[j] = this->my_activity[j + 1];
			}
			//更新活动数量
			this->activity_num--;
			//释放空间
			delete p;
			cout << "删除成功" << endl;
		}
		else
		{
			cout << "删除失败 查无此活动！" << endl;
		}
}