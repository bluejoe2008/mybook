#include "stdafx.h"
#include <cstring>

int main()
{
	char a[11];
	char b[21];

	memset(a, 'A', sizeof(a));
	//������
	a[sizeof(a) - 1] = 0;

	memset(b, 'B', sizeof(b));
	//������
	b[sizeof(b) - 1] = 0;

	//����һ��30�ֽڵ��ַ�����
	char * cp = new char[sizeof(a) + sizeof(b) - 1];

	//�ϲ�
	memcpy(cp, a, sizeof(a) - 1);
	memcpy(cp + sizeof(a) - 1, b, sizeof(b) - 1);

	//������
	cp[sizeof(a) + sizeof(b) - 2] = 0;

	//�ϲ���ϣ����
	printf("%s\r\n", a);
	printf("%s\r\n", b);
	printf("%s\r\n", cp);
}

