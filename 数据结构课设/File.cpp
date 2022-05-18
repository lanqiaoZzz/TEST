#include"File.h"
bool File::checkDuplicate(File b) {
	if (this->size != b.size)
		return false;

	else {
		ifstream A, B;
		A.open(this->path, ios::in);
		B.open(b.path, ios::in);
		unsigned char chA, chB;

		for (int i = 0; i < this->size&&i<b.size&&i<100; i++)
		{
			A >> chA;
			B >> chB;
			if (chA != chB)
				return false;
		}
		A.close();
		B.close();
		return true;
	}
}