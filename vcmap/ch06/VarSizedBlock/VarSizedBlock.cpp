#include "stdafx.h"

//д���ַ���
void WriteString(CFile & file, CString & s)
{
	int len = s.GetLength();
	//д���ַ����ĳ���
	file.Write(&len, sizeof(int));
	//д���ַ���
	file.Write((LPCTSTR)s, len);
}

//��ȡ�ַ���
bool ReadString(CFile & file, CString & s)
{
	//�ȶ�ȡ�ַ�������
	int len;
	if(file.Read(&len, sizeof(int)) == sizeof(int))
	{
		TRACE("�ַ�������: %d bytes\r\n", len);
	
		char * sp = new char[len + 1];
		sp[len] = 0;
		if(file.Read(sp, len) == len)
		{
			s = sp;
			delete [] sp;
			return true;
		}
		delete [] sp;
	}

	return false;
}

//��ȡָ���������ַ���
bool ReadString(CFile & file, CString & s, int index)
{
	//�Ƚ��鷳�������ͷ��ʼ��
	file.SeekToBegin();
	int i = 0;
	while(i < index)
	{
		//��ȡ��¼����
		int len;
		if(file.Read(&len, sizeof(int)) != sizeof(int))
			return false;

		//��λ�ļ�ָ��
		file.Seek(len, CFile::current);
		i++;
	}

	return ReadString(file, s);
}

int main()
{
	CFile file;
	file.Open("test.out", CFile::modeWrite | CFile::modeCreate);
	
	CString s1 = "bluejoe";
	CString s2 = "jerry";
	CString s3 = "even";

	//д��
	WriteString(file, s1);
	WriteString(file, s2);
	WriteString(file, s3);

	file.Close();
	//��ȡ
	file.Open("test.out", CFile::modeRead);
	printf("�ļ���С: %d bytes\r\n", file.GetLength());

	int i = 0;
	while(true)
	{
		CString s;
		if(!ReadString(file, s))
			break;

		printf("[%d]: %s\r\n", i, s);
		i++;
	}

	CString s;
	if(ReadString(file, s, 1))
		printf("[%d]: %s\r\n", 1, s);

	return 0;
}

