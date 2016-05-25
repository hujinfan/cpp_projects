#include <stdio.h>
#include "person.h"
#include "dog.h"

/* global namespace */

/* ��A::Person����global namespace,�Ժ����ʹ��Person����ʾA::Person */
using namespace A;

/* ��C::Dog����global namespace,�Ժ����ʹ��Dog����ʾC::Dog */
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
