#include "stdafx.h"
#include "comutil.h"
#pragma comment( lib, "comsuppw.lib" )

int main()
{
	setlocale(LC_ALL, "chs");

	char s1[] = "����ABC";
	wchar_t s2[] = L"�����⴫";

	//ʹ��xtoyת��
	//s2-->p1
	//��һ�ε��ã�����MBCS�ַ����ֽڳ���
	int len1 = WideCharToMultiByte(		
		CP_ACP,
		0,
		s2,  						// ���ַ���ָ��
		sizeof(s2), 				// ���ַ�������
		NULL,
		0,  						// ����0��ʾ����ת������ַ��ռ�
		NULL,
		NULL);

	char * p1 = new char[len1];

	WideCharToMultiByte(
		CP_ACP,
		0,
		s2,  						// ���ַ���ָ��
		sizeof(s2), 				// ���ַ�������
		p1,  						// ת������ַ���ָ��
		len1, 						// �����ռ��С
		NULL,
		NULL);

	printf("%s\r\n", p1);
	delete [] p1;

	//s1-->p2
	//��һ�ε��ã�������ַ����ֽڳ���
	int len2 = MultiByteToWideChar(		
		CP_ACP,
		0,
		s1,  						// MBCS�ַ���ָ��
		sizeof(s1), 				// MBCS�ַ�������
		NULL,
		0);

	wchar_t * p2 = new wchar_t[len2];

	MultiByteToWideChar(
		CP_ACP,
		0,
		s1,  						// MBCS�ַ���ָ��
		sizeof(s1), 				// MBCS�ַ�������
		p2,  						// ת������ַ���ָ��
		len2);

	printf("%S\r\n", p2);
	delete [] p2;

	//ʹ��BSTR���ת��
	_bstr_t bs1(s1);
	_bstr_t bs2(s2);

	char * bp1 = bs2;
	printf("%s\r\n", bp1);
	wchar_t * bp2 = bs1;
	printf("%S\r\n",bp2);

	return 0;
}