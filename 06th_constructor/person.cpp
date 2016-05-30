#include <iostream>

using namespace std;

class Person{
private:
	char *name;
	int age;
	char *work;
	
public:
	Person(){}
	
	Person(char *name)
	{
		this->name = name;
	}

	Person(char *name, int age)
	{
		this->name = name;
		this->age  = age;
	}
	void setName(char *name)
	{
		this->name = name;
	}

	int setAge(int age)
	{
		if(age < 0 || age > 150)
		{
			this->age = 0;
			return -1;
		}
		this->age = age;
		return 0;
	}
	
	void printInfo(void)
	{
		//printf("name = %s, age = %d, work = %s\n", name, age, work);
		cout<<"name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
	}
};

int main(int argc, char **argv)
{
	Person person("zhangsan", 16);
	person.printInfo();
	return 0;
}
