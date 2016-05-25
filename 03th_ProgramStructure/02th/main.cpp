#include <stdio.h>
#include "person.h"
int main(int argc, char **argv)
{
	Person person;
	person.setName("zhangsan");
	person.setAge(200);
	person.printInfo();
	return 0;
}
