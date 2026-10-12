#include<iostream>
using namespace std;
#include<stack>
#include<queue>

//二叉树的抽象定义

//顺序二叉树要用一个数组，有一个标志位，一个数据位，为1标志的可以放数据
//会很浪费空间，先不写

//链式二叉树
typedef struct BTNode
{
	char data;
	BTNode* lchild;
	BTNode* rchild;
}*BiTree;

//遍历二叉树，先中后序
void PreOrderTraverse(BiTree root)
{
	
	//递归退出条件放前面
	if (!root)return;
	cout << root->data << endl;
	PreOrderTraverse(root->lchild);
	PreOrderTraverse(root->rchild);
}

//中序
void InOrderTraverse(BiTree root)
{
	if (!root)return;

	InOrderTraverse(root->lchild);
	cout << root->data << endl;
	InOrderTraverse(root->rchild);
}

//后序
void PostOrderTraverse(BiTree root)
{
	if (!root)return;

	PostOrderTraverse(root->lchild);
	PostOrderTraverse(root->rchild);
	cout << root->data << endl;
}

//不用递归实现中序
void InOrderTraverse_NRecursion(const BiTree &root)
{
	//递归靠栈实现，那非递归就要模拟栈过程

	//栈，存储经过但暂不访问的结点
	stack<BTNode*>Nodes;
	//遍历需要迭代器
	BTNode* p = root;
	//条件：栈为空是起始和完成工作，p为空是走到死路或起始为空，
	// 结合才能覆盖全部范围
	while (!Nodes.empty()||p)
	{
		if(p)
		{
			Nodes.push(p);
			p = p->lchild;
		}
		else 
		{
			p = Nodes.top();
			cout << p->data << " ";
			Nodes.pop();
			p = p->rchild;
		}
	}
}

//先序
void PreOrderTraverse_NRecursion(const BiTree& root)
{
	stack<BTNode*>Nodes;
	BTNode* p = root;
	while (!Nodes.empty() || p)
	{
		if (p)
		{
			cout << p->data << " ";
			Nodes.push(p);
			p = p->lchild;
		}
		else
		{
			p = Nodes.top();
			Nodes.pop();
			p = p->rchild;
		}
	}
}

//后序
void PostOrderTraverse_NRecursion(const BiTree &root)
{
	stack<BTNode*>Nodes;
	BTNode* p = root;
	BTNode* lastVisited = NULL;
	while (!Nodes.empty() || p)
	{
		if (p)
		{
			Nodes.push(p);
			p = p->lchild;
		}
		else
		{
			//后序存在一个问题，最后访问根
			//对于叶子，访问根的条件是右孩子为空
			//对于分支结点，访问条件是右孩子访问完毕，且其右孩子不一定为空
			//所以用一个标志变量，标志着已经访问完
			p = Nodes.top();
			if (p->rchild && p->rchild != lastVisited)
			{
				p = p->rchild;
			}
			else
			{
				cout << p->data << " ";
				lastVisited = p;
				Nodes.pop();
				//p指向的元素已完成使命，置空，否则影响后续
				p = NULL;
			}
		}
	}
}

//层次遍历
void LevelOrderTraverse(const BiTree &root)
{
	//按层次就是一行一行的，从上到下，从左到右，符合队列，可以思考一下

	//在访问指针所指之前确保其自身存在
	//对于空树，p一开始可能就为空，函数中加一些判断条件，如果单独处理会简单
	if (!root)return;
	queue<BTNode* >Nodes;
	Nodes.push(root);
	while (!Nodes.empty())
	{
		//输出根结点，并出队
		BTNode* p = Nodes.front();
		cout << p->data << " ";
		Nodes.pop();
		
		//确认孩子存在后入队
		if(p->lchild)
		{
			Nodes.push(p->lchild);
		}
		if(p->rchild)
		{
			Nodes.push(p->rchild);
		}
		
		
	}
}

//二叉树遍历算法应用

//建立二叉树
//描述：仅根据一个序列建立完整二叉树，由于序列只有一个，序列中空位置用字符'#'填充
void CreatBiTree(BiTree& root)
{
	char val;
	cin >> val;

	if (val != '#')
	{
		root = new BTNode;
		root->data = val;
		CreatBiTree(root->lchild);
		CreatBiTree(root->rchild);
	}
	else root = NULL;
}

//复制二叉树
void CopyBiTree(const BiTree& root,BiTree &newRoot)
{

	if (root)
	{
		//以下5行应当是正常的变量初始化：定义，赋初值（为每一个成员）
		newRoot = new BTNode ;
		newRoot->data = root->data;
		//防止孩子出现野指针
		newRoot->lchild = NULL;
		newRoot->rchild = NULL;
		//复制粘贴注意左右孩子对应的上
		CopyBiTree(root->lchild, newRoot->lchild);
		CopyBiTree(root->rchild, newRoot->rchild);

	}
	//使叶子的孩子不为野指针
	else newRoot = NULL;	
}

//深度
int Depth(const BiTree& root)
{
	//深度取决于最深的分支，再加上自己，计算最深的分支又是递归

	if (!root)return 0;
	
	int dep_l = Depth(root->lchild);
	int dep_r = Depth(root->rchild);
	return (dep_l > dep_r ? dep_l : dep_r) + 1;
	
}

//计算结点个数
int CountNodes(const BiTree& root)
{
	if (!root)return 0;

	return CountNodes(root->lchild) + CountNodes(root->rchild) + 1;
}

//计算叶子总数
int Count0Nodes(const BiTree& root)
{
	//相较于计算结点数多了判断是否是叶子，是叶子才加1
	if (!root)return 0;
	if (!root->lchild && !root->rchild)
	{
		return 1;
	}
	return Count0Nodes(root->lchild) + Count0Nodes(root->rchild);
}


void test01()
{
	BiTree firstT;
	CreatBiTree(firstT);
	PreOrderTraverse(firstT);
	BiTree secondT;
	CopyBiTree(firstT,secondT );
	PreOrderTraverse(secondT);
}
int main()
{
	test01();


	return 0;
}
 //\b(?!if|for|return)(\w+)\s*\(
//ABC##DE#G##F###