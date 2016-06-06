#include <iostream>
#include <string.h>
#include <unistd.h>

/* ���麯��-- ������  ����ʵ�������� */

using namespace std;

class Human
{
private:
	int a;
public:
	virtual void eating(void) = 0;
	virtual void wearing(void) = 0;
	virtual void driving(void) = 0;
	virtual ~Human(){cout<<"~Human()"<<endl;}
	void test(void){cout<<"Human'test"<<endl;}
};

class English : public Human
{
public:
	void eating(void){cout<<"use knife to eat"<<endl;}
	void wearing(void){cout<<"wear english style"<<endl;}
	void driving(void){cout<<"drive english car"<<endl;}
	virtual ~English(){cout<<"~English()"<<endl;}
	int test(void){cout<<"English'test"<<endl; return 1;}
};

class Chinese : public Human
{
public:
	void eating(void){cout<<"use chopsticks to eat"<<endl;}
	void wearing(void){cout<<"wear chinese style"<<endl;}
	void driving(void){cout<<"drive chinese car"<<endl;}
	virtual ~Chinese(){cout<<"~Chinese()"<<endl;}
	int test(void){cout<<"Chinese'test"<<endl; return 1;}
};

int main(int argc, char **argv)
{
	//Human h;
	English e;
	Chinese c;

	return 0;
}

