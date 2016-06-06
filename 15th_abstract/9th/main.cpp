//#include "English.h"
//#include "Chinese.h"
#include "Human.h"

void test_eating(Human *h)
{
	h->eating();
}
int main(int argc, char **argv)
{
	Human &e = CreateEnglish("Bill", 10, "adbadfadf");
	Human &c = CreateChinese("zhangsan", 16, "jinijiojojong");

	Human *h[2] = {&e, &c};
	int i;
	for(i=0; i<2; i++)
		test_eating(h[i]);

	delete &e;
	delete &c;
	
	return 0;
}

/*
指定动态链接库路径: LD_LIBRARY_PATH=./ ./Human
*/

