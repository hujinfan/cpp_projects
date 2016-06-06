#include <stdio.h>

/* C++显示类型转换，reinterpret_cast相当于C中的() */
int main(int argc, char **argv)
{
	double d = 100.1;
	int i = d;   //double convert to int

	const char *str = "hujinfan";
	char *str2 = const_cast<char *>(str);
	int *p = reinterpret_cast<int *>(str2); // char* convert to int*

	printf("i = %d, str = 0x%x, p = 0x%x\n", i, reinterpret_cast<unsigned int>(str), reinterpret_cast<unsigned int>(p));
	
	return 0;
}

/*
无警告
*/
