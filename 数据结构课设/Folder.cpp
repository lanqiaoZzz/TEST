#include"Folder.h"
//���캯��:����������ʼ���ļ���
Folder::Folder() {
	this->fileNumber = 0;
}
void Folder::addFile() {
	char filename[50];
	char filepath[100];
	this->input_path(filepath);
	cout << "�������ļ�����" << endl;
	cin >> filename;
	File new_file(filepath, filename);
	this->files[this->fileNumber] = new_file;
	//�����ļ�����
	this->fileNumber++;
	cout << "�ļ���ӳɹ���" << endl;
}

void Folder::print_info() {
	File file;
	if (this->fileNumber == 0) {
		cout << "��ǰĿ¼Ϊ��"<< endl;
		return;
	}
	for (int i = 0; i < this->fileNumber; i++)
	{
		file = this->files[i];
		cout << "���:\t\t" << i + 1 << endl
			<< "�ļ���:\t\t" << file.getname() << endl
			<< "�ļ�·��:\t" << file.getpath() << endl
			<< endl;
	}
}

void Folder::add_homework_file(char*& student_id, char*& homework_id) {
	////�����ļ���
	//char* filename = this->get_homework_filename(student_id, homework_id);
	////�����ļ�·��
	//char filepath[100];
	//cout << "�������ļ�·��" << endl;
	//cin >> filepath;
	////������
	//ifstream ifs;
	//ifs.open(filepath,ios::in);
	//while (!ifs.is_open()) {
	//	cout << "�ļ������ڣ�����������·��" << endl;
	//	cin >> filepath;
	//	ifs.open(filepath, ios::in);
	//}
	//ifs.close();
	////Ϊ���ļ������ڴ�
	//File new_file = new File(filepath,filename);
	////�ͷſռ�
	//delete filename;
	//this->file[this->fileNumber] = new_file;
	////�����ļ�����
	//this->fileNumber++;
}

void Folder::deleteFile() {
	int n = this->getFile();

	if (n == -1) {
		cout << "ɾ��ʧ��!" << endl;
		return;
	}
		
	for (int i = n; i < this->fileNumber; i++) {
		this->files[i] = this->files[i + 1];
	}
	this->fileNumber--;
	cout << "ɾ���ɹ�!" << endl;
}

void Folder::modifyFile() {
	int n = this->getFile();

	if (n == -1) {
		cout << "�޸�ʧ�ܣ�" << endl;
		return;
	}

	char filename[50];
	char filepath[100];
	cout << "�������������ļ�����Ϣ" << endl;
	cout << "�������ļ�����" << endl;
	cin >> filename;
	this->input_path(filepath);
	this->files[n].setname(filename);
	this->files[n].setpath(filepath);
	this->files[n].refreshtime();
	cout << "�޸ĳɹ���" << endl;
}

int Folder::getFile() {
	if (this->fileNumber == 0) {
		cout << "��ǰĿ¼Ϊ�գ�" << endl;
		return -1;
	}
	this->print_info();
	cout << "�������ļ����:" << endl;
	int n;
	cin >> n;
	if (n<1 || n>this->fileNumber) {
		cout << "����Ƿ�!���������룺";
		cin >> n;
	}
	return n-1;
}

void Folder::input_path(char* path) {
	cout << "�������ļ�·��" << endl;
	cin >> path;
	//������
	ifstream ifs;
	ifs.open(path, ios::in);
	while (!ifs.is_open()) {
		cout << "�ļ������ڣ�����������·��" << endl;
		cin >> path;
		ifs.open(path, ios::in);
	}
	ifs.close();
}

void Folder::checkDuplicate() {
	int index = this->getFile();
	for (int i = 0; i < this->fileNumber; i++)
	{
		if (this->files[index].checkDuplicate(this->files[i]) && index != i) {
			cout << "�ļ� " << this->files[i].getname() << " �͸��ļ�������ͬ��" << endl;
			return;
		}
	}
	cout << "û���ļ�����ļ���ͬ��" << endl;
}

void Folder::queryFileByName(char name[]) {


}

//���ղ�ͬ�ؼ��ֶ��ļ���������1.�ϴ�ʱ�䣨���絽�� �����磩
void Folder::sortFileByTime() {

}