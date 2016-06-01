#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Sofa
{
public:
	void watchTV(void)
	{
		cout<<"watch TV"<<endl;
	}
};

class Bed
{
public:
	void sleep()
	{
		cout<<"sleep"<<endl;
	}
};

class SofaBed : public Sofa, public Bed
{

};

int main(int argc, char **argv)
{
	SofaBed s;
	s.watchTV();
	s.sleep();
	return 0;
}

