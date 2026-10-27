#include<iostream>
using namespace std;

using KeyType = string;
//顺序表的定义
struct Person
{
	KeyType name;
	int age;
	string score;
};
//Sequential Search Table：顺序表
//0号位置不放元素，用于哨兵
struct SSTable
{
	Person *person_list;
	int len;
};
//顺序查找(哨兵
int Sequential_Search(SSTable& ST, KeyType key)
{
	ST.person_list[0].name = key;
	int i = ST.len ;
	while (ST.person_list[i].name != key)
	{
		i--;
	}
	return i;
}

//折半查找
int BinSearch(SSTable& ST, KeyType key)
{
	//假设st已排好序
	int low = 1, high = ST.len;
	//这里要用等号，因为当二者到同一位置时这一位置还没有检查
	//不如说只有二者都到一个位置才能检查这一位置
	while (low <= high)
	{
		int half = (low + high) / 2;
		if (key == ST.person_list[half].name)
		{
			return half;
		}
		else if (key > ST.person_list[half].name)
		{
			//half已检查过
			low = half + 1;
		}
		else
		{
			high = half - 1;
		}
	}
	return 0;
}

//二分递归版本
int BinSearch_Recursion(SSTable& ST, KeyType key,int low,int high)
{
	//出口，分别是找到了和没找到
	if (low > high)return 0;
	int half = (low + high) / 2;
	if (key == ST.person_list[half].name)return half;

	else if (key > ST.person_list[half].name)
		return BinSearch_Recursion(ST, key, half + 1, high);
	else 		
		return BinSearch_Recursion(ST, key, low,half - 1);
}

//二叉排序树
struct BSTNode
{
	Person data;
	BSTNode* lchild;
	BSTNode* rchild;
};
using BSTree = BSTNode*;
//插入结点
bool InsertBSTNode(BSTree &node,Person data)
{
	//函数内执行：判断根是否为空，若为空则可以插入成功，相等失败
	// 不为空判断不相等后比大小看传给左或右孩子

	//退出条件：找到位置或已有此元素
	if(!node)
	{
		node = new BSTNode;
		node->lchild = node->rchild = NULL;
		node->data = data;
		return true;
	}
	if (node->data.name == data.name)return false;


	if (data.name < node->data.name)
	{
		InsertBSTNode(node->lchild, data);
	}
	else
	{
		InsertBSTNode(node->rchild, data);
	}
}

//创建二叉排序树
void CreateBSTree(BSTree& node,SSTable table)//名单
{
	node = NULL;
	for (int i = 1; i <= table.len; i++)
	{
		InsertBSTNode(node, table.person_list[i]);
	}
}

//查找的实现
BSTree BSTSearch(BSTree& node, KeyType key)
{
	//先判断结点存在再判断其指向，防止访问野指针
	if (!node||key == node->data.name)return node;
	if (key > node->data.name)BSTSearch(node->rchild, key);
	else BSTSearch(node->lchild, key);
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