#include"Course.h"
int Course::ID = 0;
Course::Course(char name[], char courseTime[], char coursePlace[], char paperData[], char courseQqGroup[],Time time) {
	strcpy_s(this->name, name);
	strcpy_s(this->courseTime, courseTime);
	strcpy_s(this->coursePlace, coursePlace);
	strcpy_s(this->paperData, paperData);
	strcpy_s(this->courseQqGroup, courseQqGroup);
	this->course_time = time;
	this->course_ID = this->ID;
	strcpy_s(this->homework_filename, "course _homework.txt");
	this->homework_filename[6] = 'A' + this->course_ID;
	this->exam_time.SetTime(20, 20, 1, 23, 24, 1);
	this->ID++;
	this->homework_num = 0;
	uploadHomenwork();
}

Course::~Course() {
	
}

Folder* Course::getelectronicData() {
	return &this->electronicData;
};

void Course::clear_disk() {
	fstream ofs;
	ofs.open(this->homework_filename, ios::out);
	ofs << endl;
}

int Course::getHomework() {
	//当没有作业时
	if (this->homework_num == 0)
	{
		cout << "该课程暂无作业" << endl;
		return -1;
	}
	//定位作业
	int homework_index = 0;
	this->checkHomework();
	cout << "请输入作业序号" << endl;
	cin >> homework_index;
	//输入检测
	while (homework_index<1 || homework_index>this->homework_num)
	{
		cout << "无效输入，请重新输入" << endl;
		cin >> homework_index;
	}
	return homework_index-1;
}

void Course::addHomework() {
	char C[100];
	cout << "请输入作业内容:" << endl;
	cin >> C;
	Homework h(C);
	int index = this->homework_num++;
	this->myHomework[index]=h;
	cout << "添加成功！" << endl;
	//更新磁盘内容
	this->saveHomework();
	system("pause");
}

void Course::checkHomework() {
	cout << this->name << ":" << endl;
	if (this->homework_num == 0)
		cout << "\t无" << endl;
	else
		for (int i = 0; i < homework_num; i++)
		{
			cout << "\t作业" << i + 1 << ":\n\t\t"
				<< this->myHomework[i].get_unpaidHomework() << endl
				<< endl;
		}
}

void Course::checkHomework(int id) {
	cout << this->name << endl;
	if (this->homework_num == 0) {
		cout << "    无" << endl;
		return;
	}
	for (int i = 0; i < homework_num; i++)
	{
		cout << "    作业" << i + 1 << ": " 
			<< this->myHomework[i].get_unpaidHomework() << endl;
		int state = this->myHomework[i].get_state(id);
		if (state == 0) {
			cout << "\t状态:未提交" << endl
				<< endl;
		}
		else {
			cout << "\t状态:已提交" << endl
				<< endl;
		}
	}
}

void Course::deleteHomework() {
	int index = this->getHomework();
	//向前覆盖
	for (int i = index; i < this->homework_num; i++)
	{
		this->myHomework[i] = this->myHomework[i + 1];
	}
	//更新作业数量
	this->homework_num--;
	cout << "删除成功" << endl;
	//更新磁盘内容
	this->saveHomework();
	system("pause");
}

void Course::modifyHomework() {
	int index = this->getHomework();
	//录入新作业
	char C[100];
	cout << "您要将作业修改为：" << endl;
	cin >> C;
	this->myHomework[index].set_unpaidHomework(C);
	cout << "修改成功！" << endl;
	//更新磁盘内容
	this->saveHomework();
	system("pause");
}

void Course::saveHomework() {
	//打开与该课程唯一对应的文件
	ofstream ofs;
	ofs.open(this->homework_filename, ios::out);
	ofs << this->homework_num << endl;
	for (int i = 0; i < this->homework_num; i++) {
		ofs << this->myHomework[i].get_unpaidHomework() << endl;
	}
	ofs.close();
}

void Course::uploadHomenwork() {
	//打开文件
	ifstream ifs;
	ifs.open(this->homework_filename, ios::in);
	//如果没有文件,被删除，或者还没被创建
	if (!ifs.is_open()) {
		return;
	}
	//读入作业数量
	ifs >> this->homework_num;
	for (int i = 0; i < this->homework_num; i++)
	{
		char C[100];
		ifs >> C;
		this->myHomework[i].set_unpaidHomework(C);
	}
	//关闭文件
	ifs.close();
}

void Course::save_course(ofstream& ofs) {
	ofs << this->name << endl
		<< this->courseTime << endl
		<< this->coursePlace << endl
		<< this->paperData << endl
		<< this->courseQqGroup << endl;
}

void Course::get_info(char courseInfo[]) {
	strcpy(courseInfo,this->name);
	strcat(courseInfo,"\t");
	strcat(courseInfo,this->courseTime);
	strcat(courseInfo, "\t");
	strcat(courseInfo, this->coursePlace);
	strcat(courseInfo, "\t\t");
	strcat(courseInfo,this->paperData );
	strcat(courseInfo, "\t");
	strcat(courseInfo, this->progress);
	strcat(courseInfo, "\t\t");
	strcat(courseInfo,this->courseQqGroup);
	strcat(courseInfo, "\t");
	strcat(courseInfo,this->examPlace);
	strcat(courseInfo, "\t\t");
	strcat(courseInfo, this->examTime);
}