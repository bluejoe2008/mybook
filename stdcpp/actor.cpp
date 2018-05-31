#include "actor.h"

//������Ĺ��캯��
Weapon::Weapon()
{
	_name = "���ֿ�ȭ";
	_power = 1;
}


Weapon::Weapon(string name, int power)
	:_name(name), _power(power)
{
}

Actor::Actor()
{
	_name = "������";
	_gender = true;

	cout << _name << "����..." << endl;
}

Actor::~Actor()
{
	cout << _name << "�������˽���..." << endl;
}

Actor::Actor(string name, bool gender)
{
	_name = name;
	_gender = gender;

	cout << _name << "����..." << endl;
}

inline void Actor::say()
{
	cout << _name << ": ����" << _name << "��Ҳ..." << endl;
}

void Actor::say(string message)
{
	cout << _name << "��" << message << endl;
}

void Actor::showWeapon()
{
	cout << "�������: ";
	cout << _weapon._name << "������: " << _weapon._power << endl;
}

void Actor::operator += (Weapon & weapon)
{
	_weapon = weapon;
}