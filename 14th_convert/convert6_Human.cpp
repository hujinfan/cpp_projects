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
	English *pe;
	Chinese *pc;
	Hubeiman *ph;

	h.eating();

	/* 想分辨这个"人"是英国人还是中国人 */
	if(pe = dynamic_cast<English *>(&h))
		cout<<"This Human is English"<<endl;
	if(pc = dynamic_cast<Chinese *>(&h))
		cout<<"This Human is Chinese"<<endl;
	if(ph = dynamic_cast<Hubeiman *>(&h))
	cout<<"This Human is Hubeiman"<<endl;
	
}

void test_return(Human& h)
{
	h.test();
}
int main(int argc, char **argv)
{
	//Human h;
	//English e;
	//Chinese c;
	Hubeiman h;

	//test_eating(h);
	//test_eating(e);
	//test_eating(c);
	test_eating(h);
	return 0;
}

/*
use chopsticks to eat, I'am from hubei
This Human is Chinese
This Human is Hubeiman
~Chinese()
~Human()
*/
