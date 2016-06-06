#include <stdio.h>

/* 显示类型转换 */
int main(int argc, char **argv)
{
	double d = 100.1;
	int i = d;   //double convert to int

	char *str = "hujinfan";
	int *p = (int *)str; // char* convert to int*

	printf("i = %d, str = 0x%x, p = 0x%x\n", i, (unsigned int)str, (unsigned int)p);
	
	return 0;
}

/*
convert2.c:In function ‘main’:
convert2.c:12:46: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
convert2.c:12:65: warning: cast from pointer to integer of different size [-Wpointer-to-int-cast]
*/
