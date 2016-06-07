
#include <iostream>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

void C(int i)
{
	int a = 1;
	double b = 1.2;
	float c = 1.3;

	if(i == 0)
	{
		cout<<"In C, it is OK"<<endl;
	}
	else if(i == 1)
		throw a;
	else if(i == 2)
		throw b;
	else
		throw c;
}

void B(int i)
{
	cout<<"call C ..."<<endl;
	C(i);
	cout<<"After call C"<<endl;
}

void A(int i)
{
	try{
		B(i);
	}catch(int j){
		cout<<"catch exception "<<j<<endl;
	}
}


int main(int argc, char** argv)
{
	int i;
	if(argc != 2)
	{
		cout<<"Usage: "<<endl;
		cout<<argv[0]<<" <0|1|2|3>"<<endl;
		return -1;
	}
	i = strtoul(argv[1], NULL, 0);
	A(i);
	return 0;
}

/*
18th_exception# ./a.out 
Usage: 
./a.out <0|1|2|3>
18th_exception# ./a.out 0
call C ...
In C, it is OK
After call C
18th_exception# ./a.out 1
call C ...
catch exception 1
18th_exception# ./a.out 2
call C ...
terminate called after throwing an instance of 'double'
Aborted (core dumped)
*/

