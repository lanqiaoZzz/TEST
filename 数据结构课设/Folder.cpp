#include"Folder.h"
//构造函数:根据容量初始化文件夹
Folder::Folder() {
	this->fileNumber = 0;
}
void Folder::addFile() {
	char filename[50];
	char filepath[100];
	this->input_path(filepath);
	cout << "请输入文件名称" << endl;
	cin >> filename;
	File new_file(filepath, filename);
	this->files[this->fileNumber] = new_file;
	//更新文件数量
	this->fileNumber++;
	cout << "文件添加成功！" << endl;
}

void Folder::print_info() {
	File file;
	if (this->fileNumber == 0) {
		cout << "当前目录为空"<< endl;
		return;
	}
	for (int i = 0; i < this->fileNumber; i++)
	{
		file = this->files[i];
		cout << "序号:\t\t" << i + 1 << endl
			<< "文件名:\t\t" << file.getname() << endl
			<< "文件路径:\t" << file.getpath() << endl
			<< endl;
	}
}

void Folder::add_homework_file(char*& student_id, char*& homework_id) {
	////生成文件名
	//char* filename = this->get_homework_filename(student_id, homework_id);
	////读入文件路径
	//char filepath[100];
	//cout << "请输入文件路径" << endl;
	//cin >> filepath;
	////输入检测
	//ifstream ifs;
	//ifs.open(filepath,ios::in);
	//while (!ifs.is_open()) {
	//	cout << "文件不存在，请重新输入路径" << endl;
	//	cin >> filepath;
	//	ifs.open(filepath, ios::in);
	//}
	//ifs.close();
	////为新文件分配内存
	//File new_file = new File(filepath,filename);
	////释放空间
	//delete filename;
	//this->file[this->fileNumber] = new_file;
	////更新文件数量
	//this->fileNumber++;
}

void Folder::deleteFile() {
	int n = this->getFile();

	if (n == -1) {
		cout << "删除失败!" << endl;
		return;
	}
		
	for (int i = n; i < this->fileNumber; i++) {
		this->files[i] = this->files[i + 1];
	}
	this->fileNumber--;
	cout << "删除成功!" << endl;
}

void Folder::modifyFile() {
	int n = this->getFile();

	if (n == -1) {
		cout << "修改失败！" << endl;
		return;
	}

	char filename[50];
	char filepath[100];
	cout << "下面请输入新文件的信息" << endl;
	cout << "请输入文件名称" << endl;
	cin >> filename;
	this->input_path(filepath);
	this->files[n].setname(filename);
	this->files[n].setpath(filepath);
	this->files[n].refreshtime();
	cout << "修改成功！" << endl;
}

int Folder::getFile() {
	if (this->fileNumber == 0) {
		cout << "当前目录为空！" << endl;
		return -1;
	}
	this->print_info();
	cout << "请输入文件序号:" << endl;
	int n;
	cin >> n;
	if (n<1 || n>this->fileNumber) {
		cout << "输入非法!请重新输入：";
		cin >> n;
	}
	return n-1;
}

void Folder::input_path(char* path) {
	cout << "请输入文件路径" << endl;
	cin >> path;
	//输入检测
	ifstream ifs;
	ifs.open(path, ios::in);
	while (!ifs.is_open()) {
		cout << "文件不存在，请重新输入路径" << endl;
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
			cout << "文件 " << this->files[i].getname() << " 和该文件疑似相同！" << endl;
			return;
		}
	}
	cout << "没有文件与该文件相同！" << endl;
}

void Folder::queryFileByName(char name[]) {


}

//按照不同关键字对文件进行排序：1.上传时间（由早到晚 由晚到早）
void Folder::sortFileByTime() {

}