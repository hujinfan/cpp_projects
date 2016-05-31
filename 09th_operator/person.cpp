#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Person{
private:
	static int count;
	char *name;
	int age;
	char *work;
	
public:

	static int getCount(void);
	
	Person()
	{
		//cout<<"Person()"<<endl;
		name = NULL;
		work = NULL;
		count++;
	}
	
	Person(char *name)
	{
		//cout<<"Person(char *)"<<endl;
		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);
		this->work = NULL;
		count++;
	}

	Person(char *name, int age, char *work = "NULL")
	{
		//cout<<"Person(char *, int)"<<endl;
		this->age = age;

		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);

		this->work = new char[strlen(work)+1]; /* allocate memory */
		strcpy(this->work, work);
		count++;
	}

	Person(const Person &per)
	{
		cout<<"Person(Person &)"<<endl;
		this->age = per.age;

		this->name = new char[strlen(per.name)+1]; /* allocate memory */
		strcpy(this->name, per.name);

		this->work = new char[strlen(per.work)+1]; /* allocate memory */
		strcpy(this->work, per.work);
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
		if(this->work)
		{
			cout<<"work = "<<work<<endl;
			delete this->work;
		}
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
	
	void printInfo(void) const
	{
		//printf("name = %s, age = %d, work = %s\n", name, age, work);
		cout<<"name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
	}

	Person& operator=(const Person &p)
	{
		cout<<"operator=(Person &p)"<<endl;

		if(this == &p)
			return *this;
		this->age = p.age;

		if(this->name)
		{
			delete this->name;
		}
		if(this->work)
		{
			delete this->work;
		}

		this->name = new char[strlen(p.name)+1]; /* allocate memory */
		strcpy(this->name, p.name);

		this->work = new char[strlen(p.work)+1]; /* allocate memory */
		strcpy(this->work, p.work);

		return *this;
	}
	
};
int Person::count = 0;

int Person::getCount(void)
{
	return count;
}
int main(int argc, char **argv)
{
	Person p1("zhangsan", 10);

	cout<<"Person p2 = p1"<<endl;
	Person p2 = p1;

	cout<<"p3=p1"<<endl;
	Person p3;
	p3 = p1;

	p1.printInfo();
	p2.printInfo();
	p3.printInfo();
	
	return 0;
}

