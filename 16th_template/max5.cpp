#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

/*
int& max(int& a, int& b)
{
	return (a < b) ? b : a; 
}

float& max(float& a, float& b)
{
	return (a < b) ? b : a; 
}

double& max(double& a, double& b)
{
	return (a < b) ? b : a; 
}
*/

template<typename T>
const T& mymax(const T& a, const T& b)
{
	cout<<__PRETTY_FUNCTION__<<endl;
	return (a < b) ? b : a; 
}

template<typename T>
const T* mymax2(const T* a, const T* b)
{
	cout<<__PRETTY_FUNCTION__<<endl;
	return (a < b) ? b : a; 
}

template<typename T>
void test_func(T f)
{
	cout<<__PRETTY_FUNCTION__<<endl;
}

int f1(int a, int b)
{
	return 0;
}

/* ����ת��Ϊָ�� */
int main(int argc, char **argv)
{
	char a[] = "ab";
	char b[] = "cd";
	
	mymax(a, b);  /* [with T = char [3] */
	mymax2(a, b); /* [with T = char] */

	char a2[] = "abc";
	char b2[] = "cd";
	//mymax(a2, b2);  /* mymax(char [4], char [3]),�޷��Ƶ���T:mymax(char& [4], char& [3]),��Ϊ�����������Ͳ�һ�� */
	mymax2(a2, b2); /* mymax2(char [4], char [3])���Ƶ�:const T* mymax2(const T*, const T*) [with T = char]*/
	
	test_func(f1);  /* void test_func(T) [with T = int (*)(int, int)] */
	test_func(&f1); /* void test_func(T) [with T = int (*)(int, int)] */
	return 0;
}

