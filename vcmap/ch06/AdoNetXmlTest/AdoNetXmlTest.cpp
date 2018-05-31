#include "stdafx.h"

#using <mscorlib.dll>
#using <system.dll>
#using <system.data.dll>

using namespace System;
using namespace System::Data;

//���ָ������һ����¼
void AddRow(DataTable ^ dt, String ^ name, int age, bool gender, String ^ words)
{
	//������¼
	DataRow ^ dr = dt->NewRow();

	dr["NAME"] = name;
	dr["AGE"] = age;
	dr["GENDER"] = gender;
	dr["WORDS"] = words;

	//��Ӽ�¼
	dt->Rows->Add(dr);
}

//����һ�����ݼ�
DataSet ^ CreateDataSet()
{
	DataSet ^ ds = gcnew DataSet();

	//�������ݱ�
	DataTable ^ dt = gcnew DataTable();
	dt->TableName = "PERSONS";

	//�����
	dt->Columns->Add("NAME", (gcnew String(""))->GetType());
	dt->Columns->Add("AGE", (gcnew Int32())->GetType());
	dt->Columns->Add("GENDER", (gcnew Boolean())->GetType());
	dt->Columns->Add("WORDS", (gcnew String(""))->GetType());

	//������ݱ�
	ds->Tables->Add(dt);

	//���������
	AddRow(dt, "١����", 28, false, "����񰡡�");
	AddRow(dt, "��չ��", 27, true, "������Ѩ�֣�");
	AddRow(dt, "��ܽ��", 22, false, "��ɽ��������ɽ�ٵ�������ɽ�����ٵ�����");
	AddRow(dt, "�����", 24, true, "������Ի����");
	AddRow(dt, "������", 30, true, "���͵����͵�����");
	AddRow(dt, "ĪС��", 12, false, "ɩ��~~~~~");

	return ds;
}

void SaveDataSet()
{
	DataSet ^ ds = CreateDataSet();
	ds->WriteXml("dataset.xml");
	ds->WriteXmlSchema("dataset.xsd");
}

void LoadDataSet()
{
	DataSet ^ ds = gcnew DataSet();
	ds->ReadXmlSchema("dataset.xsd");
	ds->ReadXml("dataset.xml");

	//ö�����б�
	for(int i = 0; i < ds->Tables->Count; i++)
	{
		DataTable ^ table = ds->Tables[i];
		Console::WriteLine(table->TableName);

		//����ֶ�
		for(int j = 0; j < table->Columns->Count; j++)
		{
			DataColumn ^ column = table->Columns[j];
			Console::WriteLine("\t{0}\t{1}", column->Caption, column->DataType->FullName);
		}
	}

	//�г�PERSON������м�¼
	DataTable ^ persons = ds->Tables["PERSONS"];
	for(int i = 0; i < persons->Rows->Count; i++)
	{
		DataRow ^ row = persons->Rows[i];
		Console::WriteLine("{0}\t{1}\t{2}\t{3}", row["NAME"], row["AGE"], row["GENDER"], row["WORDS"]);
	}
}

int main(array<System::String ^> ^args)
{
	SaveDataSet();
	LoadDataSet();

	return 0;
}
