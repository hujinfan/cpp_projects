#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human
{
private:
	int a;
public:
	virtual void eating(void){cout<<"use hand to eat"<<endl;}
	virtual ~Human(){cout<<"~Human()"<<endl;}
};

class English : public Human
{
public:
	void eating(void){cout<<"use knife to eat"<<endl;}
	virtual ~English(){cout<<"~English()"<<endl;}
};

class Chinese : public Human
{
public:
	void eating(void){cout<<"use chopsticks to eat"<<endl;}
	virtual ~Chinese(){cout<<"~Chinese()"<<endl;}
};

void test_eating(Human h)
{
	h.eating();
}
int main(int argc, char **argv)
{
	Human *h = new Human;
	English *e = new English;
	Chinese *c = new Chinese;

	Human *p[3] = {h, e, c};
	int i;
	for(i=0; i<3; i++)
	{
		p[i]->eating();
		delete p[i];
	}
	return 0;
}

/*
use hand to eat
~Human()
use knife to eat
~English()
~Human()
use chopsticks to eat
~Chinese()
~Human()
*/
