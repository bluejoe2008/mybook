#include "stdafx.h"

using namespace System;
using namespace System::IO;

int main(array<System::String ^> ^args)
{
	String^ path = "test.out";

	//д�ļ�
	StreamWriter^ sw = File::CreateText(path);
	sw->WriteLine("���㶹����");
	sw->Close();

	//���ļ�
	StreamReader^ sr = File::OpenText(path);
	String^ s = "";
	if (s = sr->ReadLine())
	{
		Console::WriteLine(s);
	}
}