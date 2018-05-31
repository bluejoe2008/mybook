#include <typeinfo>
#include <iostream> 
using namespace std;

#include "monk.h" 
#include "monster.h" 
#include "god.h" 

void f15_4_2()
{
	Actor * tang = new Actor("������", true);
	Monster bone("�׹Ǿ�", false, "�׹�ɽ");
	
	bone.say();
	bone.eat(tang);
}

void no_rtti()
{
Actor wang("��ĸ����", false);
Actor * ap = &wang;

Monster * mp = (Monster *)&wang;
	Actor * tang = new Monk("������", "������");
mp->eat(tang);
}

void rtti()
{
Actor wang("��ĸ����", false);
Actor * ap = &wang;


Monster * mp = dynamic_cast<Monster *>(ap);
if(mp != NULL)
{
	Actor * tang = new Monk("������", "������");
	mp->eat(tang);
}
else
{
	cout << "ap����һ��Monster *����!" << endl;
}
}

void rtti_ref()
{
Actor wang("��ĸ����", false);

try
{
	Monster & mr = dynamic_cast<Monster &>(wang);

	Actor * tang = new Monk("������", "������");
	mr.eat(tang);
}
catch(exception bc)
{
	cout << "wang����һ��Monster &����!" << endl;
}
}

void rtti_novirtual()
{
class A
{
};

class B
{
};

A a;
//B * bp = dynamic_cast<B *>(&a);
}

void rtti_up()
{
Monster bone("�׹Ǿ�", false, "�׹�ɽ");
Monk * mp = dynamic_cast<Monk *>(&bone);
if(mp != NULL)
{
	mp->say();
}
else
{
	cout << "ap����һ��Monster *����!" << endl;
}
}

void virtual_base()
{
Buddha ru("����", "����Ħ��");
ru.patter();
ru.fly();
	//Actor * ap = &ru;
	//Monk * mp = &ru;
	//ru.say();
	//ru.setName("��������");
	//ru.printName();

}

void rtti_typeid()
{
Actor wang("��ĸ����", false);
Monster bone("�׹Ǿ�", false, "�׹�ɽ");

Actor * ap1 = &wang;
Actor & ar1 = wang;
Actor * ap2 = &bone;
Actor & ar2 = bone;

cout << typeid(ap1).name() << endl;
cout << typeid(ar1).name() << endl;
cout << typeid(*ap1).name() << endl;

cout << typeid(ap2).name() << endl;
cout << typeid(ar2).name() << endl;
cout << typeid(*ap2).name() << endl;
}

void rtti_static()
{
Actor wang("��ĸ����", false);
Monster bone("�׹Ǿ�", false, "�׹�ɽ");

Actor * ap1 = static_cast<Actor *>(&bone); //ok, ��ȫ
Monster * ap2 = static_cast<Monster *>(&wang); //ok, ����ȫ

God chang("�϶�", false);
Actor * ap = static_cast<Actor *>(&chang);
Monster * mp = static_cast<Monster *>(ap);
}

void rtti_static2()
{
God chang("�϶�", false);
Actor * ap = static_cast<Actor *>(&chang); //ok, ��ȫ
Monster * mp = static_cast<Monster *>(ap); //ok, ����ȫ
God * gp = reinterpret_cast<God *>(mp); //error, ��ȫ


}

void rtti_typeid2()
{
class A
{
};

class B : public A
{
};

B b;
A * ap = &b;
A & ar = b;

A a;

cout << typeid(*ap).name() << endl;
cout << typeid(ar).name() << endl;
}

void rtti_const()
{
int const & i = 100;
//i = 200; //error: �����޸�const����
int & m = const_cast<int &>(i);
m = 200;

cout << i << endl;
}

ostream & operator<<(ostream & os, const Actor & actor)
{
	//����������Ա�
	os << "[" << actor.getName() << ", " << (actor.getGender() ? "��" : "Ů") << "]";
	return os;
}

void pstream()
{
Monk tang("������", "������");
Monster bone("�׹Ǿ�", false, "�׹�ɽ");
cout << tang << endl;
cout << bone << endl;
}

void foo1(Actor actor)
{
	actor.say();
}

Actor foo2()
{
	return "�����";
}

void ex()
{
string name = "������";
Actor tang = name; //��ʽ����1
tang.say();

name = "��˽�";
foo1(name); //��ʽ����2

foo2().say(); //��ʽ����3

}

void arr()
{
}

int main()
{
	//rtti();
	//f15_4_2();
	//rtti_up();
	//rtti_ref();
	//rtti_typeid2();

	//rtti_static2();
	virtual_base();

return 0;

}
