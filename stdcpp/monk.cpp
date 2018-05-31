#include "monk.h"

Monk::Monk(string name, string monkName)
	:Actor(name, true), _monkName(monkName)
{
}

Monk::~Monk()
{
	Actor::say("�����ӷ�ƶɮȥҲ...");
}

void Monk::say()
{
	Actor::say("�����ӷ�ƶɮ��" + _monkName + "��Ҳ...");
}

void Monk::patter()
{
	cout << _name << ": �����ذ����..." << endl;
}

void Monk::setName(string name)
{
	_name  = name;
	cout << "Monk::setName()... " << endl;
	cout << "_name: " << _name << endl;
}
