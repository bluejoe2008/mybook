// CPropertiesReader.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "PropertiesReader.h"
#include "Properties.h"
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	CProperties ps;
	ifstream in("sample.properties");
	ps.loadFrom(in);

	CString hotelName = ps.getProperty("hotelName")->getString();
	CString boss = ps.getProperty("boss")->getString();
	int maxClients = ps.getProperty("maxClients")->getInteger();
	bool isOpen = ps.getProperty("isOpen")->getBoolean();

	printf("�Ƶ�: %s\r\n�ϰ�: %s\r\n���˿���: %d\r\n״̬: %s\r\n", hotelName, boss, maxClients, isOpen ? "����" : "����"); 
}
