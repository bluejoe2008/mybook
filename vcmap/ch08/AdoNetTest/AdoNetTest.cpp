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
	IDbConnection ^ conn = gcnew OleDbConnection ("Provider=Microsoft.Jet.OLEDB.4.0;Data Source=E:\\study\\keys\\ch08\\hotel.mdb");
	//��������
	IDbCommand ^ comm = conn->CreateCommand();
	comm->CommandText = "select ID,NAME,AGE,GENDER,WORDS from PERSON";

	conn->Open();
	//���������Ķ���
	IDataReader ^ reader = comm->ExecuteReader();

	//�������
	while(reader->Read())
	{
		Console::Write(reader->GetInt32(0));
		Console::Write("\t");
		Console::Write(reader->GetString(1));
		Console::Write("\t");
		Console::Write(reader->GetInt32(2));
		Console::Write("\t");
		Console::Write(reader->GetString(3));
		Console::Write("\t");
		Console::WriteLine(reader->GetString(4));
	}

	return 0;
}
