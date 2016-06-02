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
	void test(void){cout<<"Human'test"<<endl;}
};

class English : public Human
{
public:
	void eating(void){cout<<"use knife to eat"<<endl;}
	virtual ~English(){cout<<"~English()"<<endl;}
	int test(void){cout<<"English'test"<<endl; return 1;}
};

class Chinese : public Human
{
public:
	void eating(void){cout<<"use chopsticks to eat"<<endl;}
	virtual ~Chinese(){cout<<"~Chinese()"<<endl;}
	int test(void){cout<<"Chinese'test"<<endl; return 1;}
};

void test_eating(Human& h)
{
	h.eating();
}

void test_return(Human& h)
{
	h.test();
}
int main(int argc, char **argv)
{
	Human h;
	English e;
	Chinese c;

	test_return(h);
	test_return(e);
	test_return(c);
	return 0;
}

/*
Human'test
Human'test
Human'test
~Chinese()
~Human()
~English()
~Human()
~Human()
*/
