#include <iostream>
#include <string.h>
#include <unistd.h>

/* 将test_eating()的引用传参改为值传参 */

using namespace std;

class Human
{
private:
	int a;
public:
	virtual void eating(void){cout<<"use hand to eat"<<endl;}
};

class English : public Human
{
public:
	void eating(void){cout<<"use knife to eat"<<endl;}
};

class Chinese : public Human
{
public:
	void eating(void){cout<<"use chopsticks to eat"<<endl;}
};

void test_eating(Human h)
{
	h.eating();
}
int main(int argc, char **argv)
{
	Human h;
	English e;
	Chinese c;

	test_eating(h);
	test_eating(e);
	test_eating(c);

	cout<<"sizeof(Human) = "<<sizeof(h)<<endl;
	cout<<"sizeof(English) = "<<sizeof(e)<<endl;
	cout<<"sizeof(Chinese) = "<<sizeof(c)<<endl;
	return 0;
}

/*
use hand to eat
use hand to eat
use hand to eat
sizeof(Human) = 16
sizeof(English) = 16
sizeof(Chinese) = 16
*/
