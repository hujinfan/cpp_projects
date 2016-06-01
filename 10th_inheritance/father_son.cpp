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
		 * 错，不能直接拿父亲的私房钱
		 */

		/* 
		 * 但是可以问他要，通过父亲的共有函数
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
