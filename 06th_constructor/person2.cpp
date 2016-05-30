#include <iostream>

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
		this->name = name;
	}

	Person(char *name, int age, char *work = "null")
	{
		cout<<"Person(char *, int)"<<endl;
		this->name = name;
		this->age  = age;
		this->work = work;
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
	Person per2;    /* 调用无参构造方法 */
	Person per3();  /* 这样仅仅是声明，类似于 int func(); */
	per.printInfo();
	return 0;
}
