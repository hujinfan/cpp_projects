#include <iostream>
#include <string.h>
#include <unistd.h>

/* when call the de-constructor func */

using namespace std;

class Person{
private:
	char *name;
	int age;
	char *work;
	
public:
	Person()
	{
		//cout<<"Person()"<<endl;
		name = NULL;
		work = NULL;
	}
	
	Person(char *name)
	{
		//cout<<"Person(char *)"<<endl;
		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);
		this->work = NULL;
	}

	Person(char *name, int age, char *work = "NULL")
	{
		//cout<<"Person(char *, int)"<<endl;
		this->age = age;

		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);

		this->work = new char[strlen(work)+1]; /* allocate memory */
		strcpy(this->work, work);
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
	
	void printInfo(void)
	{
		//printf("name = %s, age = %d, work = %s\n", name, age, work);
		//cout<<"name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
	}
};

void test_func()
{
	Person per("zhangsan", 16);
	
	Person *per7 = new Person("lisi", 18, "student");
	//delete per7;
}

int main(int argc, char **argv)
{
	test_func();
	cout<<"run test_func() end"<<endl;
	sleep(10);
	return 0;
}

