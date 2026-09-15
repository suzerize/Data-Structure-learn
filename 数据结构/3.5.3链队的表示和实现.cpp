#include<iostream>
using namespace std;
#define UNDERFLOW -3

//结点抽象类定义
typedef struct Qlnode
{
	int data;
	Qlnode* next;

}Qlnode,*rear,*front;


//链队抽象类定义
struct QLink
{
	//一个链队有头指针和尾指针
	Qlnode* front;
	Qlnode* rear;

	QLink()
	{
		front = new Qlnode;
		if (!front)
		{
			exit(OVERFLOW);
		}
		front->next = NULL;
		rear = front;
	}

	//创建一个链队
	void FoundQLink()
	{
		int n;
		cout << "输入链队大小：" << endl;
		cin >> n;
		cout << "输入元素" << endl;
		while (n--)
		{
			Qlnode* newLnode = new Qlnode;
			if (!newLnode)
			{
				exit(OVERFLOW);
			}
			cin>>newLnode->data;
			rear->next = newLnode;
			newLnode->next = NULL;
			//莫忘记尾指针更新
			rear = rear->next;
		}
	}

	//打印全部元素
	void print()
	{
		//因为front不存在，访问front.next也是非法的
		if (!front)
		{
			cout << "链队已销毁" << endl;
			//因为非法所以下面的操作都做不了，需要跳过
			return;
		}
		//链队为空和已销毁不一样
		if (front == rear)
		{
			cout << "链队为空" << endl;
			return;
		}
		Qlnode* p = front->next;

		while (p )
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}

	//销毁
	void DeleteQL()
	{
		while(front)
		{
			rear = front->next;
			delete front;
			front = rear;


		}
		//别忘记置空，否则if用不了
		front = rear = NULL;
	}

	//入队，尾插法，因为链式所以基本不会上溢
	void QL_Push_back(int e)
	{
		Qlnode* newLnode = new Qlnode;
		if (!newLnode)
		{
			exit(OVERFLOW);
		}
		newLnode->data = e;
		newLnode->next = NULL;
		rear->next = newLnode;
		rear = rear->next;
	}

	//出队
	bool QL_Pop_head()
	{
		if (front == rear)
		{
			cout << "链队为空，出队失败" << endl;
			//抛出错误就结束运行了
			exit(UNDERFLOW);
		}
		Qlnode* deleteone = front->next;
		front->next = deleteone->next;
		delete deleteone;
		if (!front->next)
		{
			rear = front;
		}
		return true;
	}
};

//void test02()
//{
//	rear r3;
//	rear r2;
//	rear r3;
//	front f1;
//	front f2;
//	front f3;
//	QLink q1;
//	q1.front;
//	q1.rear;
//}
void test01()
{
	QLink ql;
	ql.FoundQLink();
	ql.print();
	//ql.DeleteQL();

	int e;
	cout << "输入入队元素" << endl;
	cin >> e;
	ql.QL_Push_back(e);

	ql.QL_Pop_head();
	ql.print();
	
	ql.QL_Pop_head();
	ql.print();
	
	ql.QL_Pop_head();
	ql.print();
	
	

}
int main()
{
	test01();


	return 0;
}
 //\b(?!if|for|return)(\w+)\s*\(