#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:
	char *name;
	int age;
	char *work;
	
public:
	Person()
	{
		cout<<"Person()"<<endl;
	}
	~Person()
	{
		cout<<"~Person()"<<endl;
	}
	void printInfo(void)
	{
		cout<<"just a test function"<<endl;
	}
};


class sp
{
private:
	Person *p;
public:
	sp():p(0){}
	sp(Person *other)
	{
		cout<<"sp(Person *other)"<<endl;
		p =  other;
	}
	~sp()
	{
		cout<<"~sp()"<<endl;
		if(p)
			delete p;
	}
	Person *operator->()
	{
		return p;
	}
};
void test_func(void)
{
	sp s = new Person();
	s->printInfo();
	//Person *p = new Person();
	//p->printInfo();
	//delete p;
}
int main(int argc, char **argv)
{
	int i;
	for(i=0; i<2; i++)
		test_func();
	return 0;
}

