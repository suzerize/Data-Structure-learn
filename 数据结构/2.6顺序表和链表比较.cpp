#include<iostream>
using namespace std;
#define MAX 100

struct List__0206
{
	int data[100];
	int length;

	List__0206()
	{
		
		length = 0;
	}

	List__0206(int l, int* a)
	{
		length = l;
		
		for (int i = 0; i < length; i++)
		{
			data[i] = a[i];
		}
	}


	void print__0206()
	{
		cout << "顺序表数据如下：" << endl;
		for (int i = 0; i < length; i++)
		{
			cout << data[i] << " ";
		}
		cout << endl;
	}

	void DestroyList__0206(List__0206& l)
	{
		delete[]l.data;
		l.length = 0;
	}
	//线性表合并
	void MergeList_Sq__0206(List__0206& b)
	{
		List__0206 c;
		c.length = length + b.length;
		int i = 0, j = 0;

		while (i != length && j != b.length)
		{
			if (data[i] > b.data[j])
			{
				c.data[c.length++] = b.data[j];
				j++;
			}
			else
			{
				c.data[c.length++] = data[i];
				i++;
			}
		}

		if (i < length)
		{
			for (int k = i; k < length; k++)
			{
				c.data[c.length++] = data[k];
			}
		}
		if (j < b.length)
		{
			for (int k = j; k < b.length; k++)
			{
				c.data[c.length++] = b.data[k];
			}
		}

		//将c赋值到a
		
		
		length = c.length;
		for (int i = 0; i < length; i++)
		{
			data[i] = c.data[i];
		}


		//c赋值到a后就没用了，需要释放掉
		//DestroyList__0206(c);
		//如果固定数组大小就不用释放了
	}

	bool GetElem__0206(int i, int& e)
	{
		if (i<1 || i>length)
		{
			return false;
		}
		e = data[i - 1];
		return true;
	}

	int LocateElem__0206(int &e)
	{
		for (int i = 0; i < length; i++)
		{
			if (data[i] == e)
				return i+1;
		}
		return 0;
	}

	bool InsertElem__0206(int i, int e)
	{

		//判断插入位置是否合法
		if (i<1 || i>length + 1)
		{
			return false;
		}
		//容量已满
		if (length == MAX)
		{
			return false;
		}

		for (int j = length - 1; j >= i - 1; j--)
		{
			data[j + 1] = data[j];
		}
		data[i - 1] = e;
		length++;
		return true;
	}
	void UnionList__0206(List__0206& b)
	{
		int e;
		for(int i=0;i<b.length;i++)
		{
			b.GetElem__0206(i+1, e);
			if (!LocateElem__0206(e))
			{
				InsertElem__0206(length + 1, e);
				//每个函数各自完成所有工作，外面只考虑用，像这里如果外面还想着length++就错了
			}
		}
		
	}

	//4 6  7 5 3 11  3 5 7 9 10 23
};

typedef  struct Lnode__0206
{
	int data;
	Lnode__0206* next;
} *LinkList__0206, Lnode__0206;


 
	void  InitLinkList__0206(LinkList__0206&l)
	 {
		l = new Lnode__0206;
		l->next = NULL;

	 }

	//表长
	int LinkListLength__0206(LinkList__0206& l)
	{
		Lnode__0206* p = l;
		int j = 0;
		while (p)
		{
			j++;
			p = p->next;
		}

		return j;
	}
	 void FoundList_B__0206(LinkList__0206&l)
	 {
		 Lnode__0206* p = l;
		 int n;
		 cout << "请输入元素个数：" << endl;
		 cin >> n;
		 cout << "请依次输入元素：" << endl;
		 for (int i = 0; i < n; i++)
		 {
			 int e;
			 cin >> e;
			 Lnode__0206* newLnode = new Lnode__0206;
			 newLnode->data = e;
			 newLnode->next =NULL;
			 p->next = newLnode;
			 p = p->next;
		 }
	 }
	 bool LocateElem__0206(LinkList__0206&l,int e,int &i)
	 {
		 Lnode__0206* p = l->next;
		 int j = 1;
		 //Lnode__0206* p = l->next;
		 while (p)
		 {
			 if (p->data == e)
			 {
				 i = j;
				 return true;
			 }
			 p = p->next;
			 j++;
		 }
		 return false;
	 }
	 bool GetElem__0206(LinkList__0206&l,int i, int& e)
	 {
		 Lnode__0206* p = l->next;
		 int j = 0;
		 while (p && j < i )
		 {
			 p = p->next;
			 j++;
		 }
		 if (!p || j > i )
		 {
			 return false;
		 }
		 e = p->data;
		 return true;

	 }

	 bool GetElem__0206(Lnode__0206* p,int&e)
	 {
		 if (!p)
		 {
			 return false;
		 }
		 e = p->data;
		 return true;
	 }
	 bool InsertList__0206(LinkList__0206&l,int i, int e)
	 {
		 Lnode__0206* p = l;
		 int j = 0;

		 while (p || j < i - 1)
		 {
			 j++;
			 p = p->next;
		 }
		 if (!p || j > i - 1)
		 {
			 return false;
		 }

		 Lnode__0206* newLnode = new Lnode__0206;
		 newLnode->data = e;
		 newLnode->next = p->next;
		 p->next = newLnode;
		 return true;
	 }
	
	 void print__0206(LinkList__0206 &l)
	 {
		 Lnode__0206* p = l->next;
		 while (p)
		 {
			 cout << p->data << " ";
			 p = p->next;
		 }
		 cout << endl;
	 }
 
 
 void MergeList__0206(LinkList__0206&a,LinkList__0206&b)
 {
	 Lnode__0206* p = a->next, * q = b->next;
	 LinkList__0206 newone;
	 newone = a;

	 int i = 1, j = 1;
	 cout << "循环时a长这样：" << endl;
	 while (p && q) 
	 {
		 int e1, e2;
		 //如果用第几位找值，因为链表在变，所以不可能找到，所以用迭代器找值
		 //GetElem__0206(a, i, e1);
		 //GetElem__0206(b, j, e2);
		 
		 //e1 = p->data;
		 //e2 = q->data;

		 //重载函数也可以实现迭代器找值
		 GetElem__0206(p,e1);
		 GetElem__0206(q,e2);
		 if ( e1> e2)
		 {

			 newone->next = q;
			 q = q->next;
			 j++;
			 newone = newone->next;
		 }
		 else
		 {
			 newone->next = p;
			 p = p->next;
			 i++;
			 newone = newone->next;

		 }

		 print__0206(a);
	 }
	 while (p)
	 {
		 newone->next = p;
		 p = p->next;
	 }
	 while (q)
	 {
		 newone->next = q;
		 q = q->next;
	 }

	 delete b;
 }
void test01__0206()
{
	int num1, num2;
	cout << "请输入两个顺序表的长度：" << endl;
	cin >> num1 >> num2;
	int* n1 = new int[num1];
	int* n2 = new int[num2];

	
	cout << "请输入第一个表的数据：" << endl;
	for (int i = 0; i < num1; i++)
	{
		cin >> n1[i];
	}
	cout << "请输入第二个表的数据：" << endl;
	for (int i = 0; i < num2; i++)
	{
		cin >> n2[i];
	}

	List__0206 l1(num1, n1);
	List__0206 l2(num2, n2);

	l1.MergeList_Sq__0206(l2);
	l1.print__0206();
}

void test02__0206()
{
	int num1, num2;
	cout << "请输入两个顺序表的长度：" << endl;
	cin >> num1 >> num2;
	int* n1 = new int[num1];
	int* n2 = new int[num2];


	cout << "请输入第一个表的数据：" << endl;
	for (int i = 0; i < num1; i++)
	{
		cin >> n1[i];
	}
	cout << "请输入第二个表的数据：" << endl;
	for (int i = 0; i < num2; i++)
	{
		cin >> n2[i];
	}

	List__0206 l1(num1, n1);
	List__0206 l2(num2, n2);

	l1.UnionList__0206(l2);
	l1.print__0206();
}

void test03__0206()
{
	LinkList__0206 a, b;
	InitLinkList__0206(a);
	InitLinkList__0206(b);
	FoundList_B__0206(a);
	FoundList_B__0206(b);

	cout << "a长这样：" << endl;
	print__0206(a);
	cout << endl << "b长这样：" << endl;
	print__0206(b);
	cout << endl;
	MergeList__0206(a,b);
	print__0206(a);

	//4 3 5 6 7  5 1 2 3 5 10
}


//测试链表GetElem可以是p=l,j=0吗
void test04()
{
	LinkList__0206 l;
	InitLinkList__0206(l);
	FoundList_B__0206(l);

	//int i, e;
	//cout << "请输入数据位置" << endl;
	//cin >> i;
	//if (GetElem__0206(l, i, e))
	//{
	//	cout << "数据为" << e << endl;
	//}

}
//测试链表LocateElem可以是p=l,j=0吗
void test05()
{
	LinkList__0206 l;
	InitLinkList__0206(l);
	FoundList_B__0206(l);

	int i, e;
	cout << "请输入数据" << endl;
	cin >> e;
	if (LocateElem__0206(l, e,i))
	{
		cout << "数据在" << i << endl;
	}

}
//测试链表LengthLink可以是p=l,j=0吗
void test06()
{
	LinkList__0206 l;
	InitLinkList__0206(l);
	FoundList_B__0206(l);

	//cout << "表长为" << LinkListLength__0206(l) << endl;
	//结论：不可以，应为p=l.next,j=0

	//比较GetElem与Length，分析为什么length特殊
	int i, e;
	cout << "请输入元素位置" << endl;
	cin >> i;
	GetElem__0206(l, i, e);
	cout << "元素为" << e << endl;
}
int main/*__0206*/ ()
{
	
	//test01__0206();
	//test02__0206();
	//test03__0206();
	//test04();
	//test05();
	test06();
	return 0;
}