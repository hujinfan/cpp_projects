#include <stdio.h>
#include "person.h"
#include "dog.h"

/* global namespace */

/* 把A::Person放入global namespace,以后可以使用Person来表示A::Person */
using namespace A;

/* 把C::Dog放入global namespace,以后可以使用Dog来表示C::Dog */
using namespace C;

int main(int argc, char **argv)
{
	/* local namespace */
	Person per;
	per.setName("zhangsan");
	per.setAge(16);
	per.printInfo();

	Dog dog;
	dog.setName("wangcai");
	dog.setAge(2);
	dog.printInfo();
	
	A::printVersion();
	C::printVersion();
	return 0;
}
