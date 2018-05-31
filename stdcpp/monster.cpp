#include "monster.h"

Monster::Monster(string name, bool gender, string place)
	: Actor(name, gender), _place(place)
{
}

void Monster::say()
{
	//���˳�ɽ��������Ҳ...
	Actor::say("����" + _place + _name + "��Ҳ...");
}

void Monster::eat(Actor * & food)
{
	cout << _name << "�Ե�" << food->_name << "..." << endl;

	//���ٵ�actor����
	delete food;
	food = 0;
}

NativeMonster::NativeMonster(string name, bool gender, string place)
	: Monster(name, gender, place)
{
}

ExoticMonster::ExoticMonster(string name, bool gender, string place)
	: Monster(name, gender, place)
{
}

void ExoticMonster::say()
{
	Actor::say("���������·�" + _name + "��Ҳ...");
}
