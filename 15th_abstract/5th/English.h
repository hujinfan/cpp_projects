#ifndef _ENGLISH_H
#define _ENGLISH_H

#include <iostream>
#include <string.h>
#include <unistd.h>

#include "Human.h"

using namespace std;

class English : public Human
{
public:
	void eating(void);
	void wearing(void);
	void driving(void);
    ~English();
};

#endif
