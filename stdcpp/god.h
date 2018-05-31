#include "monk.h"

/////////////////////����/////////////////////

class God : public Actor  
{
public:
	void printName();
	void fly(); //���ɿ��Է�����ȥ
	God(string name, bool gender);
};

//////////////////////��//////////////////////

class Buddha : public Actor
{
private:
	God _god;
	Monk _monk;
public:
	Buddha(string name, string monkName)
		: Actor(name, true), _monk(name, monkName), _god(name, true)
	{
	}

	void patter()
	{
		_monk.patter();
	}

	void fly()
	{
		_god.fly();
	}
};
