#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Sofa
{
private:
	int weight;
public:
	void watchTV(void)
	{
		cout<<"watch TV"<<endl;
	}
	void setWeight(int weight)
	{
		this->weight = weight;
	}
	int getWeight(void)
	{
		return weight;
	}
};

class Bed
{
private:
	int weight;
public:
	void sleep()
	{
		cout<<"sleep"<<endl;
	}
	void setWeight(int weight)
	{
		this->weight = weight;
	}
	int getWeight(void)
	{
		return weight;
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

	//s.setWeight(100); //error 有二义性 ambiguous

	s.Sofa::setWeight(100);
	
	cout<<s.Sofa::getWeight()<<endl;
	return 0;
}

