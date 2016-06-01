#include <iostream>
#include <string.h>
#include <unistd.h>

using namespace std;

class Father
{
private:
	int money;
protected:
	int room_key;
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

class Son_pub : public Father
{
private:
	int toy;
public:
	using Father::room_key;
	
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

		room_key = 1;
	}

};

class Son_pro : protected Father
{
private:
	int toy;
public:
	using Father::room_key;
	
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

		room_key = 1;
	}

};

class Son_pri: private Father
{
private:
	int toy;
public:
	using Father::room_key;
	
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

		room_key = 1;
	}

};



int main(int argc, char **argv)
{
	Son_pub son_pub;
	Son_pro son_pro;
	Son_pri son_pri;

	son_pub.play_game();
	son_pro.play_game();
	son_pri.play_game();

	son_pub.it_skill();
	//son_pro.it_skill(); //error
	//son_pri.it_skill(); //error
	return 0;
}
