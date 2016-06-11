#include <iostream>
#include <string.h>
#include <unistd.h>
#include "RefBase.h"

using namespace std;
using namespace android::RSC;

class Person : public LightRefBase<Person>{
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


template<typename T>
void test_func(sp<T> &other)
{
	sp<T> s = other;

	cout<<"In test_func: "<<s->getStrongCount()<<endl;
	
	s->printInfo();
	
	//Person *p = new Person();
	//p->printInfo();
	//delete p;
}
int main(int argc, char **argv)
{
	int i;

	/* 少用"Person *",用 "sp" 来代替 "Person *"
	 * Person *per;
	 * 有两种操作: per->xxxx, (*per).xxx
	 * sp也应该有这2种操作:
	 *             sp->xxx, (*sp).xxx        
	 */
	sp<Person> other = new Person();

	(*other).printInfo();
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
just a test function
Before call test_func: 1
In test_func: 2
just a test function
After call test_func: 1
In test_func: 2
just a test function
After call test_func: 1
~Person()
*/

