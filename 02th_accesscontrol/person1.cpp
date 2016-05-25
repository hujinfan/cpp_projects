#include <stdio.h>

class Person{
private:
	char *name;
	int age;
	char *work;
	
public:
	void setName(char *n)
	{
		name = n;
	}

	int setAge(int a)
	{
		if(a < 0 || a > 150)
		{
			age = 0;
			return -1;
		}
		age = a;
		return 0;
	}
	
	void printInfo(void)
	{
		printf("name = %s, age = %d, work = %s\n", name, age, work);
	}
};

int main(int argc, char **argv)
{
	Person person;
	person.setName("zhangsan");
	person.setAge(200);
	person.printInfo();
	return 0;
}
