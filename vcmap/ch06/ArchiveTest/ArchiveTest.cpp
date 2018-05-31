#include "stdafx.h"
#include "mfc-person.h"
#include "ArchiveTest.h"

int main()
{
	setlocale(LC_ALL, "chs");

	//����������д��Ķ���
	CPerson tong(_T("١����"), 28, false);
	tong.setWords(_T("�����..."));

	CPerson bai(_T("��չ��"), 27, true);
	bai.setWords(_T("������Ѩ�֣�"));

	//׼��д��
	CFile oFile(_T("persons.archive"), CFile::modeCreate | CFile::modeWrite);
	CArchive oar(&oFile, CArchive::store);

	//���л���ȥ��
	oar << &tong << &bai;
	//oar.WriteObject(&tong);
	//oar.WriteObject(&bai);

	oar.Close();
	oFile.Close();

	//׼����ȡ
	CFile iFile(_T("persons.archive"), CFile::modeRead);
	CArchive iar(&iFile, CArchive::load);

	//���л�������
	CPerson *p1, * p2;

	iar >> p1 >> p2;
	//p1 = iar.ReadObject(RUNTIME_CLASS(CPerson));
	//p2 = iar.ReadObject(RUNTIME_CLASS(CPerson));

	//���������ǲ��ǻ��*_*ii
	p1->say();
	p2->say();

	delete p1;
	delete p2;
}
