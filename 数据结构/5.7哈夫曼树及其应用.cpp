#include<iostream>
using namespace std;
#include<algorithm>

//抽象类定义
//哈夫曼树本质是个数组
//权重和指针类型一样，千万别搞混
typedef struct HuffTreeNode
{
	int weight;
	int parent;
	int lchild, rchild;
}HTNode,*HTree;

//构造哈夫曼树

//选出两个最小结点的下标
void Select(const HTree& ht,int n,int &first,int &second)
{
	//不能用排序后找前两个，排序是一个结点整个交换，但是结点本身存储的双亲左右孩子的指针都不会跟着变，会乱
	for (int i = 1; i <= n; i++)
	{
		if (ht[i].parent)continue;
		
		if (!first || ht[i].weight < ht[first].weight)
		{
			second = first;
			first = i;
		}
		else if (!second || ht[i].weight < ht[second].weight)
		{
			second = i;
		}
	}
	
}
void CreateHuffmanTree(HTree  &origin,int n)
{
	//给的是初始数组，需要我初始化n个元素
	origin = new HTNode[2*n];
	cout << "输入" << n << "个元素的权重" << endl;
	for (int i = 1; i <= n; i++)
	{
		
		cin >> origin [i].weight;
		origin[i].parent = origin[i].rchild = origin[i].lchild = 0;
		
	}

	//，然后在构造过程中添加n-1个元素
	for (int i = 1; i <= n-1 ; i++)
	{
		int first=0, second=0;
		//first second是下标，不要混成weight
		Select(origin, n-1+i, first, second);
		
		//初始化一个新结点
		int newNode = i + n;
		origin[newNode].weight = origin [first].weight+origin [second].weight;
		origin[newNode].lchild = first;
		origin[newNode].rchild = second;
		origin[newNode].parent = 0;
		//修改两结点为孩子
		origin[first].parent = newNode;
		origin[second].parent = newNode;
	}
}
void CreateHuffmanTree(HTree  &origin,int wei[],int n)
{
	//给的是初始数组，需要我初始化n个元素
	origin = new HTNode[2*n];
	for (int i = 1; i <= n; i++)
	{
		origin[i].weight = wei[i];
		origin[i].parent = origin[i].rchild = origin[i].lchild = 0;
		
	}

	//，然后在构造过程中添加n-1个元素
	for (int i = 1; i <= n-1 ; i++)
	{
		int first=0, second=0;
		//first second是下标，不要混成weight
		Select(origin, n-1+i, first, second);
		
		//初始化一个新结点
		int newNode = i + n;
		origin[newNode].weight = origin [first].weight+origin [second].weight;
		origin[newNode].lchild = first;
		origin[newNode].rchild = second;
		origin[newNode].parent = 0;
		//修改两结点为孩子
		origin[first].parent = newNode;
		origin[second].parent = newNode;
	}
}

//哈夫曼编码
//code我要填充，不确定原来是什么，故初始化
void CreateHaffCode(char **&ch, int weight[], int n)
{
	//存放n个编码，0号不用
	ch = new char*[n+1];
	
	HTree ht;
	CreateHuffmanTree(ht, weight,n);
	for (int i = 1; i <= n; i++)
	{
		//初始化为全空
		ch[i] = new char[n + 1]();

		//pos用于从后向前迭代
		int pos = n;
		//j为了不改变i，同时从i追溯到根
		int j = i;
		//f是双亲，简化书写
		int f = ht[i].parent;
		while (f)
		{
			if (ht[f].lchild == j)
			{
				ch[i][pos] = '0';
			}
			else ch[i][pos] = '1';
			j = f;
			f = ht[f].parent;
			pos--;
		}
	}
}
void test01()
{

}
int main()
{
	test01();


	return 0;
}
 //\b(?!if|for|return)(\w+)\s*\(