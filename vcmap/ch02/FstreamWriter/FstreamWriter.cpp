#include "stdafx.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	//д���ļ�
	ofstream out("test.out");
	out << "���㶹����";
	out.close();

	//��ȡ�ļ�
	ifstream in("test.out");
	char line[256];
	in.getline(line, 256);
	cout << line << endl;

	return 0;
}
