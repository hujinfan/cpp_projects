#include "English.h"

void English::setName(char *name)
{
	this->name = name;
}

char *English::getName(void)
{
	return this->name;
}

void English::eating(void)
{
	cout<<"use knife to eat"<<endl;
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

