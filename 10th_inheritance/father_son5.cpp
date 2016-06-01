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

	int address;
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
	//using Father::room_key;
	
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

class Grandson_pub : public Son_pub
{
public:
	void test(void)
	{
		room_key = 1;  /* room_key is protected */
		address  = 2;  /* address is public */
	}
};

class Grandson_pro : public Son_pro
{
public:
	void test(void)
	{
		room_key = 1;  /* room_key is protected */
		address  = 2;  /* address is protected */
	}
};

class Grandson_pri : public Son_pri
{
public:
	void test(void)
	{
		//room_key = 1;   /* error room_key is private */
		//address  = 2;  /* error address is private */
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

	Grandson_pub gs_pub;
	Grandson_pro gs_pro;
	

	gs_pub.address = 2;
	gs_pro.room_key = 1;
	gs_pro.address = 2;  //error
	return 0;
}
