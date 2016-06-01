#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:
	char *name;
	int age;
	
public:
	int address;
	
	Person()
	{
		//cout<<"Person()"<<endl;
		name = NULL;
	}
	
	Person(char *name)
	{
		//cout<<"Person(char *)"<<endl;
		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);
	}

	Person(char *name, int age)
	{
		cout<<"Person(char *, int), name="<<name<<", age="<<age<<endl;
		this->age = age;

		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);
	}

	Person(Person &per)
	{
		cout<<"Person(Person &)"<<endl;
		this->age = per.age;

		this->name = new char[strlen(per.name)+1]; /* allocate memory */
		strcpy(this->name, per.name);
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
		cout<<"Person "<<"name = "<<name<<", age = "<<age<<endl;
	}
};

class Student : public Person{
private:
	int grade;
	void setGrade(int grade){this->grade = grade;}
	int getGrade(void){return grade;}
public:
	void printInfo(void)
	{
		cout<<"Student ";
		Person::printInfo();
	}

};

void test_func(Person &p)
{
	p.printInfo();
}

int main(int argc, char **argv)
{
	Person p("lisi", 10);
	Student s;

	s.setName("zhangsan");
	s.setAge(16);

	test_func(p);
	test_func(s);   /* Person &p = s里面的Person部分
					 * p引用的是"s 里面的Person部分 "
					 */
	s.printInfo();
	
	return 0;
}

