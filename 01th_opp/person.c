#include <stdio.h>

struct person{
	char *name;
	int age;
	char *work;
	
	void(*printInfo)(struct person *per);
};

void printInfo(struct person *per)
{
	printf("name = %s, age = %d, work = %s\n", per->name, per->age, per->work);
}

int main(int argc, char **argv)
{
	struct person persons[] = {
		{"zhangsan", 10, "teacher", printInfo},
		{"lisi", 16, "doctor", printInfo},
	};

	persons[0].printInfo(&persons[0]);
	persons[1].printInfo(&persons[1]);
	
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
