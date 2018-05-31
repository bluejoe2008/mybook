#include "stdafx.h"

#define STRING_LENGTH 20

//д���ַ���
void WriteString(CFile & file, char s[])
{
	file.Write(s, STRING_LENGTH);
}

//��ȡ�ַ���
bool ReadString(CFile & file, char s[])
{
	return file.Read(s, STRING_LENGTH) == STRING_LENGTH;
}

//��ȡָ���������ַ���
bool ReadString(CFile & file, char s[], int index)
{
	//��λ�ļ�ָ��
	file.Seek(index * STRING_LENGTH, CFile::begin);
	return file.Read(s, STRING_LENGTH) == STRING_LENGTH;
}

int main()
{
	CFile file;
	file.Open("test.out", CFile::modeWrite | CFile::modeCreate);
	
	char s1[STRING_LENGTH] = "bluejoe";
	char s2[STRING_LENGTH] = "jerry";
	char s3[STRING_LENGTH] = "even";

	//д��3�������ַ���
	WriteString(file, s1);
	WriteString(file, s2);
	WriteString(file, s3);

	file.Close();
	//��ȡ
	file.Open("test.out", CFile::modeRead);
	printf("�ļ���С: %d\r\n", file.GetLength());

	int i = 0;
	while(true)
	{
		char s[STRING_LENGTH];
		if(!ReadString(file, s))
			break;

		printf("[%d]: %s\r\n", i, s);
		i++;
	}

	char s[STRING_LENGTH];
	//��ȡ��1����¼
	if(ReadString(file, s, 1))
		printf("[%d]: %s\r\n", 1, s);

	return 0;
}

