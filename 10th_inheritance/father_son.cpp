#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Father
{
private:
	int money;
public:
	void it_skill()
	{
		cout<<"father's it skill"<<endl;
	}
	int getMoney()
	{
		return money;
	}
	void setMoney(int money)
	{
		this->money = money;
	}
};

class Son : public Father
{
private:
	int toy;
public:
	void play_game(void)
	{
		int m;
		cout<<"son play game"<<endl;

		/* money = -1;
		 * ������ֱ���ø��׵�˽��Ǯ
		 */

		/* 
		 * ���ǿ�������Ҫ��ͨ�����׵Ĺ��к���
		 */
		m = getMoney();
		m--;
		setMoney(m);
	}

};

int main(int argc, char **argv)
{
	Son s;
	s.it_skill();
	s.play_game();

	s.setMoney(10);
	cout<<s.getMoney()<<endl;
	return 0;
}
