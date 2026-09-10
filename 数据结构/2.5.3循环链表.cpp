#include<iostream>
using namespace std; 

typedef class Lnode
{
public:
	int data;
	Lnode* next;
}Lnode,*LinkList;

LinkList& InitCList__020503()
{
	//正常创建一个空表
	LinkList T = new Lnode;
	T->next = NULL;

	return T;
}

void FoundCList__020503(LinkList& L)
{

	LinkList p = L;
	//使用尾插法
	printf("请输入数据元素：");
	
	for (int i = 0; i < 5;i++)
	{
		Lnode* newLnode = new Lnode;
		cin>>newLnode->data;

		newLnode->next = NULL;
		L->next = newLnode;
		L = newLnode;
	}
	L->next = p;
}

//这里想用头插法构建循环链表，然后发现麻烦多了，建议用尾插法即可
//void FoundCLinkH__020503(LinkList& L)
//{
//	int n;
//	cout << "请输入链表长度" << endl;
//	cin >> n;
//
//	LinkList p = L;
//	//使用尾插法
//	printf("请逆序输入数据元素：");
//	int Elem;
//	cin >> Elem;
//	
//	for (int i = n-1; i > 0; i--)
//	{
//		Lnode* newLnode = new Lnode;
//		cin >> newLnode->data;
//
//		newLnode->next = NULL;
//		L->next = newLnode;
//		L = newLnode;
//	}
//	L->next = p;
//}

LinkList& ConnectCLink__020503(LinkList A, LinkList B)//将两个循环链表连接起来
{
	Lnode* pA = A->next;//记录A的头指针，否则会丢失

	A->next = (B->next)->next;//A尾连B首元结点

	delete B->next;//释放B头结点

	B->next = pA;//B尾连A头结点

	A = B;//更新尾指针
	return A;//返回尾指针
}

void printCLink__020503(LinkList L)
{
	Lnode* p = L->next->next;

	printf("链表数据如下：");
	while (p!=L->next)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void test01__020503()
{
	LinkList La = InitCList__020503();
	FoundCList__020503(La);

	LinkList Lb = InitCList__020503();
	FoundCList__020503(Lb);

	
	printCLink__020503(ConnectCLink__020503(La, Lb));
}


int main__020503()
{
	test01__020503();
	
	return 0;
}