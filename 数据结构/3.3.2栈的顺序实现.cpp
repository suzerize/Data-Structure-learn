#include<iostream>
using namespace std;

#define MAXSIZE 100
#define OVERFLOW -1

struct SqStack
{
	int* top;
	int* base;
	int stacksize;

	//初始化栈，写在类内，就不用手动写了
	SqStack(int n)
	{
		stacksize = n;
		base = new int[stacksize];
		if (!base)
		{
			cerr << "初始化失败" << endl;
			exit(OVERFLOW);
		}
		top = base;
	}
};

//判空
bool SqStackisEmpty(SqStack& s)
{
	if (s.base == s.top)
		return true;
	return false;
}

//求长
int SqStackLength(SqStack& s)
{
	
		return s.top - s.base;
}
//15min

//清空
void SqStackClear(SqStack& s)
{
	s.top = s.base;
}

//销毁
void SqStackDestroy(SqStack& s)
{
	if (s.base)
	{
		//头尾指针共享空间，不用重复释放
		delete[] s.base;
		s.stacksize = 0;
		s.top = s.base = NULL;
	}

}

//入栈
bool SqStackPush(SqStack& s,int e)
{
	if (s.top - s.base == s.stacksize)
	{
		cout << "上溢" << endl;
		return false;
	}
	//*s.top = e;
	//s.top++;
	*s.top++ = e;
	return true;
}
//15min,并且测试了入栈，判空函数

bool SqStackPop(SqStack& s, int& e)
{
	if (s.top - s.base == 0)
	{
		cout << "下溢" << endl;
		return false;
	}
	
	//s.top--;
	//e = *s.top;
	e = *--s.top;
	return true;
}
void test01()
{
	SqStack s1( MAXSIZE);
	for (int i = 0; i < MAXSIZE; i++)
	{
		SqStackPush(s1, i);
	}
	//SqStackClear(s1);
	//SqStackDestroy(s1);
	//SqStackisEmpty(s1);
	//cout<<SqStackLength(s1)<<endl;
	//int e;
	//SqStackPop(s1,e);
	//cout << "出栈元素为" << endl;
	//cout << e << endl;

	//cout << "输入入栈元素" << endl;
	//cin >> e;
	//SqStackPush(s1, e);

	//SqStackPop(s1, e);
	//cout << "出栈元素为" << endl;
	//cout << e << endl;

	//SqStackPop(s1, e);
	//cout << "出栈元素为" << endl;
	//cout << e << endl;
}
int main__030302()
{
	
	test01();


	return 0;
}