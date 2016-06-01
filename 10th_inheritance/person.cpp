#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:
	static int count;
	char *name;
	int age;
	
public:

	static int getCount(void);
	
	Person()
	{
		//cout<<"Person()"<<endl;
		name = NULL;
		count++;
	}
	
	Person(char *name)
	{
		//cout<<"Person(char *)"<<endl;
		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);
		count++;
	}

	Person(char *name, int age)
	{
		cout<<"Person(char *, int), name="<<name<<", age="<<age<<endl;
		this->age = age;

		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);
		
		count++;
	}

	Person(Person &per)
	{
		cout<<"Person(Person &)"<<endl;
		this->age = per.age;

		this->name = new char[strlen(per.name)+1]; /* allocate memory */
		strcpy(this->name, per.name);
		
		count++;
	}
	
	~Person()
	{
		cout<<"~Person()"<<endl;
		if(this->name)
		{
			cout<<"name = "<<name<<endl;
			delete this->name;
		}
	}
	
	void setName(char *name)
	{
		if(this->name)
		{
			delete this->name;
		}
		this->name = new char[strlen(name)+1];
		strcpy(this->name, name);
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
		//printf("name = %s, age = %d\n", name, age);
		cout<<"name = "<<name<<", age = "<<age<<endl;
	}
};
int Person::count = 0;

int Person::getCount(void)
{
	return count;
}

class Student : public Person{

};
int main(int argc, char **argv)
{
	Student s;

	s.setName("zhangsan");
	s.setAge(16);
	s.printInfo();
	
	return 0;
}

