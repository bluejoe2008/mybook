#include "actor.h"

class Monster : public Actor
{
private:
	string _place; //ס��
public:
	Monster(string name, bool gender, string place);

	void say(); //���к�
	void eat(Actor * & food); //���ֳ���
};

class NativeMonster : public Monster
{
private:
	long _days; //����ʱ��
public:
	NativeMonster(string name, bool gender, string place);
};

class ExoticMonster : public Monster
{
private:
	string _home; //������
public:
	void say();
	ExoticMonster(string name, bool gender, string place);
};