#include <stdio.h>

int main(int argc, char **argv)
{
	char *names[] = {"zhangsan", "lisi"};
	char ages[]  = {10, 16};
	int i;
	
	for(i=0; i<2; i++)
	{
		printf("name = %s, age = %d\n", names[i], ages[i]);
	}
	return 0;
}
