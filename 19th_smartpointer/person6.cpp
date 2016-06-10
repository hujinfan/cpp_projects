#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:
	int count;
public:
	void incStrong(){count++;}
	void decStrong(){count--;}
	int getStrongCount(){return count;}
	
	Person():count(0)
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
		p->incStrong();
	}
	
	sp(const sp &other)
	{
		cout<<"sp(const sp &other)"<<endl;
		p = other.p;
		p->incStrong();
	}
	
	~sp()
	{
		cout<<"~sp()"<<endl;
		if(p)
		{
			p->decStrong();
			if(p->getStrongCount() == 0)
			{
				delete p;
				p = NULL;
			}
		}
	}
	Person *operator->()
	{
		return p;
	}
};
void test_func(sp &other)
{
	sp s = other;

	cout<<"In test_func: "<<s->getStrongCount()<<endl;
	
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

	
	cout<<"Before call test_func: "<<other->getStrongCount()<<endl;
	
	for(i=0; i<2; i++)
	{
		test_func(other);
		cout<<"After call test_func: "<<other->getStrongCount()<<endl;
	}
	return 0;
}

/*
Person()
sp(Person *other)
Before call test_func: 1
sp(const sp &other)
In test_func: 2
just a test function
~sp()
After call test_func: 1
sp(const sp &other)
In test_func: 2
just a test function
~sp()
After call test_func: 1
~sp()
~Person()
*/

