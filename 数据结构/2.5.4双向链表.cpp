#include<iostream>
using namespace std;
#define MAX 5

 struct DLnode__020504
{
	int data;
	struct DLnode__020504* prior;
	struct DLnode__020504* next;
};

struct DLinkList__020504
{
	DLnode__020504* head;

	DLinkList__020504()
	{
		head= new DLnode__020504;
		head->next = NULL;
		head->prior = NULL;

	}

	//头插法会使首元结点和其他结点的处理不同，建议不用
	//DLinkList& FoundDLinkpush_H__020504(DLinkList DL)
	//{
	//	DLnode__020504 *p = DL;
	//	for(int i=0;i<MAX;i++)
	//	{
	//		DLnode__020504* newLnode = new DLnode__020504;
	//		cin >> newLnode->data;
	// 
	//		//类似于双向链表插入的操作
	//		newLnode->next = p->next;
	//		p->next = newLnode;
	//		newLnode->prior = p; 
	//	}
	//
	//}

	void FoundLinkpush_B__020504()
	{
		DLnode__020504* p = head;
		cout << "请输入5个数据元素" << endl;

		int i = 0;
		while (i < 5)
		{
			DLnode__020504* newLnode = new DLnode__020504;
			cin >> newLnode->data;
			newLnode->next = NULL;
			newLnode->prior = p;
			p->next = newLnode;
			p = p->next;

			i++;
		}
		
	}

	void printDLink__020504()
	{
		DLnode__020504* p = head->next;

		cout << "双向链表内数据如下" << endl;
		while (p)
		{
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
	
	bool InsertDLink__020504(int i,int e)
	{
		DLnode__020504* p = head;//不能用引用，引用无法移动
		int j = 0;
		while (p->next && j < i - 1)
		{
			j++;
			p = p->next;
		}

		if (!p || j > i - 1)//保证插入位置之前不是空，不用管插入位置是否为空
		{
			return false;
		}

		DLnode__020504* newLnode = new DLnode__020504;
		
		newLnode->data = e;
		newLnode->next = p->next;
		//p->next->prior = newLnode;//最后一个结点的next是空的，访问会出错，需要单独判断
		if (p->next)
		{
			p->next->prior = newLnode;
		}

		newLnode->prior = p;
		p->next = newLnode;

		return true;
	}

	bool DeleteDLink__020504(int i)
	{
		DLnode__020504* p = head;
		int j = 0;
		while (p && j < i)
		{
			j++;
			p = p->next;
		}

		if (!p || j > i)
		{
			return false;
		}

		(p->prior)->next = p->next;
		if(p->next)
			(p->next)->prior = p->prior;

		delete p;
		return true;
	}

};


void test01__020504()
{
	DLinkList__020504 DL;
	DL.FoundLinkpush_B__020504();
	DL.printDLink__020504();

	if(DL.InsertDLink__020504(6, 10))
		DL.printDLink__020504();

	if (DL.DeleteDLink__020504(6))
	{
		DL.printDLink__020504();
	}
}
int main__020504()
{
	test01__020504();


	return 0;
}