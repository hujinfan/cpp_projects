#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human
{
public:
	void eating(void){cout<<"use hand to eat"<<endl;}
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

void test_eating(Human &h)
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
	return 0;
}

/*
use hand to eat
use hand to eat
use hand to eat
*/
