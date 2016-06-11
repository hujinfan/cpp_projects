#include <iostream>
#include <string.h>
#include <unistd.h>
#include <utils/RefBase.h>

using namespace std;
using namespace android;

class Person : public RefBase{
private:
	char *name;
	wp<Person> father;
	wp<Person> son;
public:	
	Person()
	{
		cout<<"Person()"<<endl;
	}
	Person(char *name)
	{
		cout<<"Person(char *name)"<<endl;
		this->name = name;
	}
	~Person()
	{
		cout<<"~Person()"<<endl;
	}

	void setFather(sp<Person> &father)
	{
		this->father = father;
	}
	void setSon(sp<Person> &son)
	{
		this->son = son;
	}

	char *getName(void)
	{
		return name;
	}
	void printInfo(void)
	{
		sp<Person> f = father.promote();
		sp<Person> s = son.promote();

		cout<<"I am "<<name<<endl;
		if(f != 0)
			cout<<"My father is "<<f->getName()<<endl;
		if(s != 0)
			cout<<"My son is "<<s->getName()<<endl;
	}
};

/*
��������ﺬ��������Ա����
����ʱ:�ȹ���������Ա�����ٹ��������
����ʱ:˳��պ��෴
*/

void test_func()
{
	/*
	1.����new Person()
	1.1 Person�����father�ȱ�����
	1.2 Person�����son������
	1.3 Person����������
	2. Person�����ָ�봫��"sp<Person> father"
	   ����:sp(T* other)������
	   �����������Person��������ü���(���ڴ�ֵ����1)
	*/
	sp<Person> father = new Person("liyishi");

	/*
	1.����new Person()
	1.1 Person�����father�ȱ�����
	1.2 Person�����son������
	1.3 Person����������
	2. Person�����ָ�봫��"sp<Person> son"
	   ����:sp(T* other)������
	   �����������Person��������ü���(���ڴ�ֵ����1)
	*/
	sp<Person> son = new Person("liershi");

	/*
	����һ��"=" : this->son = son;
	"="�����أ������ٴ����Ӹ�Person��������ü���
	����son��Ӧ��Person��������ü�������Ϊ2
	*/
	father->setSon(son);

	/*
	����һ��"=" : this->father = father;
	"="�����أ������ٴ����Ӹ�Person��������ü���
	����father��Ӧ��Person��������ü�������Ϊ2
	*/
	son->setFather(father);

	father->printInfo();

	son->printInfo();

	/*
	��test_funcִ���꣬father��son������
	1.�ȿ�father:
	  ~sp():decStrong������Ὣ����ֵ��1��father��Ӧ��Person�ļ���ֵ����1����û�е���0������û�б�delete��
	2.����son:
	  ~sp():decStrong������Ὣ����ֵ��1��son��Ӧ��Person�ļ���ֵ����1����û�е���0������û�б�delete��
	*/
}
int main(int argc, char **argv)
{
	test_func();
	
	return 0;
}

/*
Person(char *name)
Person(char *name)
I am liyishi
My son is liershi
I am liershi
My father is liyishi
~Person()
~Person()
*/

