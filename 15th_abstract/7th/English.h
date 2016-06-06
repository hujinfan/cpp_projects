#ifndef _ENGLISH_H
#define _ENGLISH_H

#include <iostream>
#include <string.h>
#include <unistd.h>

#include "Human.h"

using namespace std;

class English : public Human
{
private:
	char address[100];
	int age;
public:
	void eating(void);
	void wearing(void);
	void driving(void);
	English();
	English(char *name, int age, char *address);
    ~English();
};

#endif
