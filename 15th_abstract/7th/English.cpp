#include "English.h"

void English::eating(void)
{
	cout<<"use knife to eat test..."<<endl;
}
void English::wearing(void)
{
	cout<<"wear english style"<<endl;
}
void English::driving(void)
{
	cout<<"drive english car"<<endl;
}

English:: ~English()
{
	cout<<"~English()"<<endl;
}

English::English()
{

}

English:: English(char * name, int age, char * address)
{
	setName(name);
	this->age = age;
	memset(this->address, 0 ,100);
	strcpy(this->address, address);
}

