#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Furniture
{
private:
	int weight;
public:
	Furniture(){cout<<"Furniture()"<<endl;}
	void setWeight(int weight)
	{
		this->weight = weight;
	}
	int getWeight(void)
	{
		return weight;
	}
};

class Vertification3C
{
public:
	Vertification3C(){cout<<"Vertification3C"<<endl;}
};

class Sofa : virtual public Furniture, virtual public Vertification3C
{
private:
	int a;
public:
	void watchTV(void)
	{
		cout<<"watch TV"<<endl;
	}
	Sofa(){cout<<"Sofa()"<<endl;}
};

class Bed : virtual public Furniture, virtual public Vertification3C
{
private:
	int b;
public:
	void sleep()
	{
		cout<<"sleep"<<endl;
	}
	Bed(){cout<<"Bed()"<<endl;}
};

class SofaBed : public Sofa, public Bed
{
private:
	int c;
public:
	SofaBed(){cout<<"SofaBed()"<<endl;}
};

class LightRightCom
{
public:
	LightRightCom(){cout<<"LightRightCom()"<<endl;}
};

class Date
{
public:
	Date(){cout<<"Date()"<<endl;}
};

class Type
{
public:
	Type(){cout<<"Type()"<<endl;}
};

class LightRightSofaBed : public SofaBed, public LightRightCom{
private:
	Date date;
	Type type;
public:
	LightRightSofaBed(){cout<<"LightRightSofaBed()"<<endl;}
};

int main(int argc, char **argv)
{
	LightRightSofaBed s;
	
	return 0;
}

/*
Furniture()
Vertification3C
Sofa()
Bed()
SofaBed()
LightRightCom()
Date()
Type()
LightRightSofaBed()
*/
