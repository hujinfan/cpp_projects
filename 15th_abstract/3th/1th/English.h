#ifndef _ENGLISH_H
#define _ENGLISH_H

#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class English
{
private:
	char *name;
public:
	void setName(char *name);
	char *getName(void);
	void eating(void);
	void wearing(void);
	void driving(void);
    ~English();
};

#endif
