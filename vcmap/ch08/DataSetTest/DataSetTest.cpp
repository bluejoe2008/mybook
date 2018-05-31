// DataSetTest.cpp: ����Ŀ�ļ���

#include "stdafx.h"

#include "stdafx.h"

#using <mscorlib.dll>
#using <system.dll>
#using <system.data.dll>

using namespace System;
using namespace System::Data;
using namespace System::Data::Common;
using namespace System::Data::OleDb;
using namespace System::ComponentModel;

int main(array<System::String ^> ^args)
{
	//��ȡ����
	OleDbConnection ^ conn = gcnew OleDbConnection ("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\\study\\keys\\ch08\\hotel.mdb");
	//��������
	OleDbCommand ^ comm = conn->CreateCommand();
	comm->CommandText = "select ID,NAME,AGE,GENDER,WORDS from PERSON";

	conn->Open();
	IDataAdapter ^ adapter = gcnew OleDbDataAdapter(comm);

	DataSet ^ ds = gcnew DataSet();
	adapter->Fill(ds);

	//ע�⣺���ݿ������Ѿ��رգ���
	conn->Close();

	//ö�����б�
	for(int i = 0; i < ds->Tables->Count; i++)
	{
		DataTable ^ table = ds->Tables[i];
		Console::WriteLine(table->TableName);

		//����ֶ�
		for(int j = 0; j < table->Columns->Count; j++)
		{
			DataColumn ^ column = table->Columns[j];
			Console::Write("\t");
			Console::WriteLine(column->Caption);
		}
	}

	//�г�PERSON������м�¼
	DataTable ^ persons = ds->Tables[0];
	for(int i = 0; i < persons->Rows->Count; i++)
	{
		DataRow ^ row = persons->Rows[i];
		Console::Write(row["ID"]);
		Console::Write("\t");
		Console::Write(row["NAME"]);
		Console::Write("\t");
		Console::Write(row["AGE"]);
		Console::Write("\t");
		Console::Write(row["GENDER"]);
		Console::Write("\t");
		Console::Write(row["WORDS"]);
		Console::WriteLine();
	}

	return 0;
}
