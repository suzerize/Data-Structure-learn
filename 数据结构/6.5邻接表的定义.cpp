#include<iostream>
using namespace std;
//该词代表顶点类型
using VertexType = char;
//该词代表弧类型，即弧权值类型为int
using ArcType = int;

#define MAXSIZE 100
//边结点
struct ArcNode
{
	//存放本结点的下标(在头结点数组中的）
	int loc;
	ArcNode *next;
	//存放权
	ArcType info;
};
using ArcList = ArcNode*;
//顶点 头结点
 struct VexNode
{
	 //存放定点值
	VertexType vex;
	//存放与其邻接的边
	 ArcList arc;
};
 //邻接表类型
struct ALGraph
{
	VexNode v[MAXSIZE];
	int vexnum, arcnum;

	bool directed;
	bool weighted;
};

int Local(VertexType v,const ALGraph &G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		
		if (v == G.v[i].vex)
		{
			return i;
		}
	}
	return -1;
}
void CreateALGraph(ALGraph& G,bool directed,bool weighted)
{
	int ve;
	cin >> ve;
	G.vexnum = ve;
	G.directed = directed;
	G.weighted = weighted;
	for (int i = 0; i < G.vexnum; i++)
	{
		cin >> G.v[i].vex;
		G.v[i].arc = NULL;
	}

	//输入边数
	int a;
	cin >> a;
	G.arcnum = a;
	for (int i = 0; i < G.arcnum; i++)
	{
		VertexType v1, v2;
		cin >> v1 >> v2;
		//根据权值
		int weight = 1;
		if (G.weighted)cin >> weight;

		int loc1 = Local(v1, G);
		int loc2=Local(v2,G);

		//若返回-1说明输入错误，跳过后续步骤
		if (loc1 == -1 || loc2 == -1)
			continue;
		ArcNode *newNode = new ArcNode;
		newNode->info = weight;
		newNode->loc = loc2;
		//头插法
		newNode->next = G.v[loc1].arc;
		G.v[loc1].arc = newNode;

		//根据向
		if (!G.directed)
		{
			ArcNode* newNode = new ArcNode;
			newNode->info = weight;
			newNode->loc = loc1;
			//头插法
			newNode->next = G.v[loc2].arc->next;
			G.v[loc2].arc = newNode;
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