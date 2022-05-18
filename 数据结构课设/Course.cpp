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
	//��û����ҵʱ
	if (this->homework_num == 0)
	{
		cout << "�ÿγ�������ҵ" << endl;
		return -1;
	}
	//��λ��ҵ
	int homework_index = 0;
	this->checkHomework();
	cout << "��������ҵ���" << endl;
	cin >> homework_index;
	//������
	while (homework_index<1 || homework_index>this->homework_num)
	{
		cout << "��Ч���룬����������" << endl;
		cin >> homework_index;
	}
	return homework_index-1;
}

void Course::addHomework() {
	char C[100];
	cout << "��������ҵ����:" << endl;
	cin >> C;
	Homework h(C);
	int index = this->homework_num++;
	this->myHomework[index]=h;
	cout << "��ӳɹ���" << endl;
	//���´�������
	this->saveHomework();
	system("pause");
}

void Course::checkHomework() {
	cout << this->name << ":" << endl;
	if (this->homework_num == 0)
		cout << "\t��" << endl;
	else
		for (int i = 0; i < homework_num; i++)
		{
			cout << "\t��ҵ" << i + 1 << ":\n\t\t"
				<< this->myHomework[i].get_unpaidHomework() << endl
				<< endl;
		}
}

void Course::checkHomework(int id) {
	cout << this->name << endl;
	if (this->homework_num == 0) {
		cout << "    ��" << endl;
		return;
	}
	for (int i = 0; i < homework_num; i++)
	{
		cout << "    ��ҵ" << i + 1 << ": " 
			<< this->myHomework[i].get_unpaidHomework() << endl;
		int state = this->myHomework[i].get_state(id);
		if (state == 0) {
			cout << "\t״̬:δ�ύ" << endl
				<< endl;
		}
		else {
			cout << "\t״̬:���ύ" << endl
				<< endl;
		}
	}
}

void Course::deleteHomework() {
	int index = this->getHomework();
	//��ǰ����
	for (int i = index; i < this->homework_num; i++)
	{
		this->myHomework[i] = this->myHomework[i + 1];
	}
	//������ҵ����
	this->homework_num--;
	cout << "ɾ���ɹ�" << endl;
	//���´�������
	this->saveHomework();
	system("pause");
}

void Course::modifyHomework() {
	int index = this->getHomework();
	//¼������ҵ
	char C[100];
	cout << "��Ҫ����ҵ�޸�Ϊ��" << endl;
	cin >> C;
	this->myHomework[index].set_unpaidHomework(C);
	cout << "�޸ĳɹ���" << endl;
	//���´�������
	this->saveHomework();
	system("pause");
}

void Course::saveHomework() {
	//����ÿγ�Ψһ��Ӧ���ļ�
	ofstream ofs;
	ofs.open(this->homework_filename, ios::out);
	ofs << this->homework_num << endl;
	for (int i = 0; i < this->homework_num; i++) {
		ofs << this->myHomework[i].get_unpaidHomework() << endl;
	}
	ofs.close();
}

void Course::uploadHomenwork() {
	//���ļ�
	ifstream ifs;
	ifs.open(this->homework_filename, ios::in);
	//���û���ļ�,��ɾ�������߻�û������
	if (!ifs.is_open()) {
		return;
	}
	//������ҵ����
	ifs >> this->homework_num;
	for (int i = 0; i < this->homework_num; i++)
	{
		char C[100];
		ifs >> C;
		this->myHomework[i].set_unpaidHomework(C);
	}
	//�ر��ļ�
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