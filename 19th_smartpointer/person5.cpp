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
	
	sp(const sp &other)
	{
		cout<<"sp(const sp &other)"<<endl;
		p = other.p;
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
void test_func(sp &other)
{
	sp s = other;
	s->printInfo();
	//Person *p = new Person();
	//p->printInfo();
	//delete p;
}
int main(int argc, char **argv)
{
	int i;

	/* 相当于:
	 * 1. Person *p = new Person();
	 * 2. sp tmp(p); ==> sp(Person *other)
	 * 3. 
	 * 3.1 sp other(tmp); ==> sp(sp &other2)
	 *     问题在于: sp &other2 = tmp; //错误语法
	 *               const sp &other2 = tmp; //ok
	 *或
	 *3.2 sp other(tmp ==> Person*); ==>sp(Person *other)
	 */
	sp other = new Person();
	
	for(i=0; i<2; i++)
		test_func(other);
	return 0;
}

