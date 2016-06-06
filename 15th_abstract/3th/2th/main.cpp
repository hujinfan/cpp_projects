#include "English.h"
#include "Chinese.h"


int main(int argc, char **argv)
{
	English e;
	Chinese c;

	e.setName("Bill");
	c.setName("zhangsan");

	e.eating();
	c.eating();
	return 0;
}

