#include <iostream> 
#include <string> 
using namespace std;

#ifndef __WEAPON__
#define __WEAPON__

/////////////////////����/////////////////////
class Weapon
{
private:
	string _name; //������
	int _power; //����
public:
	Weapon();
	Weapon(string name, int power);
	friend class Actor;
};

/////////////////////��ɫ/////////////////////
class Actor
{
protected:
	string _name; //����
	bool _gender; //�Ա�
private:
	Weapon _weapon; //�������
public:
	Actor();
	virtual ~Actor();
	Actor(string name, bool gender);
	void operator += (Weapon & weapon);

	inline virtual void say();
	void say(string message);
	void showWeapon();
	string getName() const {return _name;}
	bool getGender() const {return _gender;}

	Actor::Actor(string name)
	:_name(name), _gender(true)
{
	cout << _name << "����..." << endl;
}

	friend class Monster;
	//friend ostream & operator<<(ostream & os, const Actor & actor);
};

#endif