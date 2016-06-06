#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Human
{
private:
	int a;
public:
	virtual void eating(void){cout<<"use hand to eat"<<endl;}
	virtual ~Human(){cout<<"~Human()"<<endl;}
	void test(void){cout<<"Human'test"<<endl;}
};

class English : public Human
{
public:
	void eating(void){cout<<"use knife to eat"<<endl;}
	virtual ~English(){cout<<"~English()"<<endl;}
	int test(void){cout<<"English'test"<<endl; return 1;}
};

class Chinese : public Human
{
public:
	void eating(void){cout<<"use chopsticks to eat"<<endl;}
	virtual ~Chinese(){cout<<"~Chinese()"<<endl;}
	int test(void){cout<<"Chinese'test"<<endl; return 1;}
};

class Hubeiman : public Chinese
{
public:
	void eating(void){cout<<"use chopsticks to eat, I'am from hubei"<<endl;}
};

void test_eating(Human& h)
{
#if 1
	//English& pe = dynamic_cast<English&>(h);
	Chinese& pc = dynamic_cast<Chinese&>(h);
	Hubeiman& ph = dynamic_cast<Hubeiman&>(h);
#else
	English& pe = reinterpret_cast<English&>(h);
	Chinese& pc = reinterpret_cast<Chinese&>(h);
	Hubeiman& ph = reinterpret_cast<Hubeiman&>(h);

#endif

	h.eating();
	
}

void test_return(Human& h)
{
	h.test();
}
int main(int argc, char **argv)
{
	Human h;
	//English e;
	//Chinese c;
	Hubeiman hu;

	English *pe;

	pe = static_cast<English *>(&h);

	//English *pe2 = static_cast<English *>(&hu);

	Chinese*pc = static_cast<Chinese*>(&hu);
	return 0;
}


