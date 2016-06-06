#include "English.h"
#include "Chinese.h"
#include "Human.h"

void test_eating(Human *h)
{
	h->eating();
}
int main(int argc, char **argv)
{
	English e;
	Chinese c;

	Human *h[2] = {&e, &c};
	int i;
	for(i=0; i<2; i++)
		test_eating(h[i]);
	return 0;
}

