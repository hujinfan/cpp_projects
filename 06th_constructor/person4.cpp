#include <iostream>
#include <string.h>

using namespace std;

class Person{
private:
	char *name;
	int age;
	char *work;
	
public:
	Person(){cout<<"Person()"<<endl;}
	
	Person(char *name)
	{
		cout<<"Person(char *)"<<endl;
		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);
	}

	Person(char *name, int age, char *work = "null")
	{
		cout<<"Person(char *, int)"<<endl;

		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);

		this->work = new char[strlen(work)+1]; /* allocate memory */
		strcpy(this->work, work);
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
	Person per("zhangsan", 16);
	Person per2;    /* �����޲ι��췽�� */
	//Person per3();  /* ���������������������� int func(); */

	Person *per4 = new Person;
	Person *per5 = new Person();

	Person *per6 = new Person[2]; /* ���ö����޲ι��췽�� */

	Person *per7 = new Person("lisi", 18, "student");
	Person *per8 = new Person("wangwu", 18);

	per.printInfo();
	per7->printInfo();
	per8->printInfo();

	delete per4;
	delete per5;
	delete []per6;
	delete per7;
	delete per8;
	return 0;
}
