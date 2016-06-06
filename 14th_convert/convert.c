#include <stdio.h>

/* 隐式类型转换 */
int main(int argc, char **argv)
{
	double d = 100.1;
	int i = d;   //double convert to int

	char *str = "hujinfan";
	int *p = str; // char* convert to int*

	printf("i = %d, str = 0x%x, p = 0x%x\n", i, str, p);
	
	return 0;
}

/*
convert.c: In function ‘main’:
convert.c:10:11: warning: initialization from incompatible pointer type [enabled by default]
convert.c:12:2: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument 3 has type ‘char *’ [-Wformat]
convert.c:12:2: warning: format ‘%x’ expects argument of type ‘unsigned int’, but argument 4 has type ‘int *’ [-Wformat]

*/
