 //#include<stdio.h>
 //#include<stdlib.h>

 //#define ERROR 0
 //#define OK 1
 //typedef struct Lnode//声明节点的类型和指向节点的指针类型
 //{

 //	//这里用了两个Lnode，第一个是因为在抽象类内已经使用了还没定义完的抽象类，需要提前说明我有这样一个抽象类
 //	//第二个是将我定义的抽象类命名为Lnode
 //	int data;//数据域
 //	struct Lnode* next;//指针域
 //	//typedef让我可以在抽象类的定义结束后不用再写struct，但在抽象类内还不行，这个struct还去不掉

 //}Lnode,*LinkList;//LinkList为指向结构体Lnode的指针类型 

 //void InitLnode___020501()
 //{
 //	LinkList L = (LinkList)malloc(sizeof(Lnode));//这里用一个头结点的大小初始化，不是头指针的大小
 //	L->next = NULL;
 //}

 //int IsEmpty___020501(LinkList L)
 //{
 //	return L->next == NULL;
 //}

 //void DeleteLnode___020501(LinkList* pL)//(*pL)是链表的头指针
 //{
 //	Lnode* p;
 //	while ((*pL) != NULL)//用头指针就不用初始化p了，如果初始化p则有重复语句冗余
 //	{
 //		 p= (*pL);
 //		 (*pL) = (*pL)->next;
 //		 free(p);
 //	}
 //}

 //void ClearLnode___020501(LinkList* pL)
 //{
 //	//除了头指针全都释放，还原成空表
 //	Lnode* p=(*pL), * r;
 //	while (p != NULL)
 //	{
 //		r = p->next;
 //		free(p);
 //		p = r;
 //	}
 //}

 //int LnodeLength___020501(LinkList L)
 //{
 //	Lnode* p = L->next;
 //	int length = 0;//不能写为1，数了一个才能加一，这还没开始，初始就是0
 //	while (p != NULL)
 //	{
 //		length++;
 //		p = p->next;
 //	}
 //	return length;
 //}

 //int GetElem___020501(LinkList L,int i,int *pElem)
 //{
 //	int j = 1;//这里用1，因为一开始就从第一个元素开始比较
 //	Lnode* p = L->next;
 //	while (p != NULL || j < i)
 //	{
 //		j++;
 //		p = p->next;
 //	}

 //	if (j > i || p == NULL)
 //	{
 //		return ERROR;
 //	}
 //	*pElem = p->data;
 //	return OK;
 //}

 //int FindElem___020501(LinkList L, int elem)//按值查找—返回第几位
 //{
 //	Lnode* p = L->next;
 //	int local = 1;//这里用1，第一次进入条件就是判断第一位符不符合
 //	while (p != NULL&&p->data!=elem)
 //	{
 //		p = p->next;
 //		local++;
 //	}
 //	if (!p)
 //	{
 //		return ERROR;
 //	}
	//

 //	return local;
 //}

 //int* FindpElem___020501(LinkList L, int elem)
 //{
 //	Lnode* p = L->next;
 //	while (p && p->data != elem)
 //	{
 //		p = p->next;
 //	}
 //	return p;//若没找到p也到了最后，也为空
 //}

 //int InsertLnode___020501(LinkList* pL, int i, int elem)
 //{
 //	Lnode* p = (*pL);
 //	int j = 0;
 //	while(p || j < i-1)//与删除不同，p后面可以有节点，也可以没有，所以保证p存在即可
 //	{
 //		p = p->next;
 //		j++;
 //	}

 //	if (!p || j > i-1)
 //	{
 //		return ERROR;
 //	}

 //	Lnode *newLnode=(Lnode*)malloc(sizeof(Lnode));
 //	newLnode->data = elem;

 //	//链接新结点
 //	newLnode->next = (p->next);
 //	p->next = newLnode;
 //	return OK;
 //}

 //int DeleteLnode___020501(LinkList* pL, int i)
 //{
 //	Lnode* p = (*pL);
 //	int j = 0;
 //	while (p->next || j < i-1)//要删除的是p的下一个，他得存在，故判断p.next是否为空，与前面都不同
 //	{
 //		p = p->next;
 //		j++;
 //	}
 //	if (!p->next || j > i-1)
 //	{
 //		return ERROR;
 //	}
 //	Lnode* oldLnode = p->next;//指向删除结点的指针
 //	p->next = oldLnode->next;//将要删除的结点后的结点链接到前面，使该结点孤立
 //	free(oldLnode);
 //	return OK;
 //}

 //void FoundLnode_head___020501()
 //{
 //	//建立一个空表
 //	LinkList L = (LinkList)malloc(sizeof(Lnode));
 //	L->next = NULL;

 //	//要初始化的结点个数
 //	int n;
 //	scanf("%d", &n);

 //	for(int i=n;i>0;i--)
 //	{
 //		Lnode* newLnode = (Lnode*)malloc(sizeof(Lnode));
 //		scanf("%d", &newLnode->data);

 //		newLnode->next = L->next;//新结点与后面链接
 //		L->next = newLnode;//新结点与前面链接，前面是头结点
 //	}
 //}

 //void FoundLnode_back___020501()
 //{
 //	//建立一个空表
 //	LinkList L = (LinkList)malloc(sizeof(Lnode));
 //	L->next = NULL;

 //	//创建尾指针
 //	Lnode* r = L;

 //	//要初始化的结点个数
 //	int n;
 //	scanf("%d", &n);
 //	for (int i = 0; i < n; i++)
 //	{
 //		//初始化新结点
 //		Lnode* newLnode = (Lnode*)malloc(sizeof(Lnode));
 //		scanf("%d", &newLnode->data);
 //		newLnode->next = NULL;

 //		r->next = newLnode;//链接新结点
 //		r = newLnode;//更新尾指针
 //	}
 //}

 //void test01___020501()
 //{
 //	Lnode test1, test2;
 //	test1.data = 1;
 //	test2.data = 2;
 //	test1.next = &test2;
 //	printf("test2.data=%d", test1.next->data);
 //}
 //int main___020501()
 //{
 //	//test01___020501();

 //	return 0;
 //}