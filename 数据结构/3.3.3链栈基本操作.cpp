#include<iostream>
using namespace std;

typedef struct StackLnode
{
	int data;
	StackLnode* next;
}StackLnode,*StackLink;

//初始化，因为没有头结点，所以连空间都不用分配
void InitStackLink(StackLink& s)
{
	s = NULL;
}

//判空函数
bool IsEmpty_StackLink(StackLink& s)
{
	return s == NULL;
}

//入栈
void StackLink_push_back(StackLink& s, int e)
{
	StackLnode* p = new StackLnode;
	p->data = e;
	p->next = s;
	s = p;

}

//输出所有数据
void printStack(StackLink& s)
{
	StackLnode* p = s;
	if (IsEmpty_StackLink (p))
	{
		cout << "链栈为空" << endl;
		return;
	}
	while (p)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

bool StackLink_pop_back(StackLink& s)
{
	if (s)
	{
		StackLnode* p = s;
		s = s->next;
		delete p;
		return true;
	}
	cout << "链表为空，无法出栈" << endl;
	return false;
}
//获取栈顶元素
bool GetElem_StackLink(StackLink& s, int& e)
{
	if (s)
	{
		e = s->data;
		return true;
	}
	return false;
}


//测试函数功能
void test01()
{
	StackLink p;
	InitStackLink(p);
	if (IsEmpty_StackLink(p))
	{
		cout << "链栈为空" << endl;
	}

	//测试入栈
	int e;
	cout << "输入入栈数据" << endl;
	cin >> e;
	StackLink_push_back(p, e);
	StackLink_push_back(p, e);
	printStack(p);

	StackLink_pop_back(p);
	printStack(p);
	StackLink_pop_back(p);

	//全部元素出栈，测试边界
	printStack(p);
	StackLink_pop_back(p);
	printStack(p);

	cout << "输入4个元素,将入栈" << endl;
	cin >> e;
	StackLink_push_back(p, e);
	cin >> e;
	StackLink_push_back(p, e);
	cin >> e;
	StackLink_push_back(p, e);
	cin >> e;
	StackLink_push_back(p, e);

	int e1;
	if(GetElem_StackLink(p, e1))
	{
		cout << "栈顶元素为：" << e1 << endl;
	}
}

int main()
{
	test01();


	return 0;
}
 //\b(?!if|for|return)(\w+)\s*\(