#include <stdio.h>

struct person{
	char *name;
	int age;
	char *work;
	
	void printInfo(void)
	{
		printf("name = %s, age = %d, work = %s\n", name, age, work);
	}
};

int main(int argc, char **argv)
{
	struct person persons[] = {
		{"zhangsan", 10, "teacher"},
		{"lisi", 16, "doctor"},
	};

	persons[0].printInfo();
	persons[1].printInfo();
	
	/*
	int i = 0;
	for(i=0; i<2; i++)
	{
		printf("name = %s, age = %d, work = %s\n", persons[i].name, 
			persons[i].age, persons[i].work);
	}
	*/
	return 0;
}
