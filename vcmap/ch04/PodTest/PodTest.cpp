#include "stdafx.h"
#include <cstring>

//PERSONΪPOD
struct PERSON
{
	char _name[16];
	int _age;
	bool _gender;
};

void print(PERSON * p)
{
	printf("%s,%d,%s\r\n", p->_name, p->_age, (p->_gender ? "��" : "Ů"));
}

int main()                              
{
	//POD�������ʹ�ó�ʼ���б�
	PERSON p1 = {"١����", 28, false};
	PERSON p3 = {"��չ��", 26, true};
	print(&p1);
	print(&p3);

	//��p1ת��Ϊchar����
	char bytes[sizeof(PERSON)];
	memcpy(bytes, &p1, sizeof(PERSON));

	PERSON p2;
	memset(&p2, 0, sizeof(PERSON));
	print(&p2);

	//��char���黹ԭΪp2
	memcpy(&p2, bytes, sizeof(PERSON));
	print(&p2);

	//��p3������p2
	memcpy(&p2, &p3, sizeof(PERSON));
	print(&p2);

	return 0;
}
