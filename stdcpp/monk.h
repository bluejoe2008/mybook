#include "actor.h"

#ifndef __MONK__
#define __MONK__

class Monk : public Actor
{
private:
	string _monkName; //����
public:
	void setName(string name);
	Monk(string name, string monkName);
	~Monk();
	void say(); //���к�
	void patter(); //�
};

#endif