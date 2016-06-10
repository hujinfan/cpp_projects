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

void test_func(void)
{
	//Person *p = new Person();
	Person per;
	per.printInfo();
}
int main(int argc, char **argv)
{
	int i;
	for(i=0; i<2; i++)
		test_func();
	return 0;
}

