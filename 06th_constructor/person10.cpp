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
		cout<<"Person(char *, int), name = "<<name<<", age = "<<age<<endl;
		this->age = age;

		this->name = new char[strlen(name)+1]; /* allocate memory */
		strcpy(this->name, name);

		this->work = new char[strlen(work)+1]; /* allocate memory */
		strcpy(this->work, work);
	}

	Person(Person &per)
	{
		cout<<"Person(Person &)"<<endl;
		this->age = per.age;

		this->name = new char[strlen(per.name)+1]; /* allocate memory */
		strcpy(this->name, per.name);

		this->work = new char[strlen(per.work)+1]; /* allocate memory */
		strcpy(this->work, per.work);
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
		cout<<"name = "<<name<<", age = "<<age<<", work = "<<work<<endl;
	}
};

Person per_g("per_g", 10);

void func()
{
	Person per_func("per_func", 12);
	static Person per_func_s("per_func_s", 12);
}

int main(int argc, char **argv)
{
	Person per_main("per_main", 11);
	static Person per_main_s("per_main_s", 11);

	for(int i = 0; i < 2; i++)
	{
		func();
		Person per_for("per_for", i);
	}
	return 0;
}


/*
 * # ./a.out 
 * Person(char *, int), name = per_g, age = 10
 * Person(char *, int), name = per_main, age = 11
 * Person(char *, int), name = per_main_s, age = 11
 * Person(char *, int), name = per_func, age = 12
 * Person(char *, int), name = per_func_s, age = 12
 * ~Person()
 * name = per_func
 * work = NULL
 * Person(char *, int), name = per_for, age = 0
 * ~Person()
 * name = per_for
 * work = NULL
 * Person(char *, int), name = per_func, age = 12
 * ~Person()
 * name = per_func
 * work = NULL
 * Person(char *, int), name = per_for, age = 1
 * ~Person()
 * name = per_for
 * work = NULL
 * ~Person()
 * name = per_main
 * work = NULL
 * ~Person()
 * name = per_func_s
 * work = NULL
 * ~Person()
 * name = per_main_s
 * work = NULL
 * ~Person()
 * name = per_g
 * work = NULL
*/
