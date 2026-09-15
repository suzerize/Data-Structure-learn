#include<iostream>
using namespace std;

#define MAXSIZE 4
//定义抽象类
struct Queue
{
	int* data;
	int front;
	int rear;

	Queue()
	{
		data = new int[MAXSIZE];
		if (!data)
		{
			cout << "分配空间失败" << endl;
			exit(OVERFLOW);
		}

		front = rear = 0;
	}

	//求长
	int length()
	{
		return (rear - front + MAXSIZE) % MAXSIZE;
	}

	//入队
	bool Push(int& e)
	{
		//队满
		//经过画图验证，空的那个结点并非不变的
		if ((rear + 1)%MAXSIZE == front)
		{
			cout << "队已满" << endl;
			return false;
		}
		data[rear] = e;
		//使其加一，并且形成循环
		rear = (rear + 1) % MAXSIZE;
		//cout << "rear：" << rear << endl;
		return true;
	}

	//出队
	bool Pop()
	{
		//队空
		if (rear == front)
		{
			cout << "队空无法出队" << endl;
			return false;
		}

		//使其加一，并且形成循环
		front = (front + 1) % MAXSIZE;
		return true;
	}
	void print()
	{
		int f = front, r = rear;
		if (f == r)
		{
			cout << "队为空" << endl;
			return;
		}
		while (f != r)
		{
			cout << data[f] << " ";
			f = (f + 1) % MAXSIZE;

		}
		cout << endl;
	}


};

//测试队列函数
void test01()
{
	Queue q;
	//cout<<"队列长度为" << q.length() << endl;
	int e;
	cin >> e;
	q.Push(e);
	q.Push(e);
	q.Push(e);
	q.Push(e);
	//cout << "q的rear" << q.rear << endl;
	q.print();
	cout<<"队列长度为" << q.length() << endl;
	
	q.Pop();
	q.print();

	q.Pop();
	q.print();

	q.Pop();
	q.print();

	q.Pop();
	q.print();
	cout << "队列长度为" << q.length() << endl;


}
int main()
{
	test01();


	return 0;
}
 //\b(?!if|for|return)(\w+)\s*\(