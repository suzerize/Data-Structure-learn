// #include<stdio.h>
// #include<stdlib.h>

// #define MAXSIZE 100
// #define OK 1
// #define ERROR 0
// #define INFEASIBLE -1
// #define OVERFLOW -2
// typedef int Status;//表示函数状态，成功返回1，失败返回0
// typedef char ElemType;

// typedef struct 
// {
// 	ElemType* elem;
// 	int length;
// }SqList;

// Status InitList_Sq__020402(SqList* L)//构造一个空表L
// {
// 	L->elem = (ElemType*)malloc((MAXSIZE) * sizeof(ElemType));//为顺序表分配空间
// 	if (!L->elem)exit(OVERFLOW);//存储分配失败
// 	L->length = 0;//新的空表长度为0
// 	return OK;
	
// }
// void DestroyList__020402(SqList* L)//销毁线性表L
// {
// 	if (L != NULL && L->elem != NULL)
// 	{
// 		free(L->elem);
// 		L->elem = NULL;
// 		L->length = 0;
// 	}
	
// }
// void ClearList__020402(SqList* L)//清空线性表
// {
// 	L->length = 0;
// }
// int GetLength__020402(SqList L)//求线性表长度
// {
// 	return (L.length);
// }
// int IsEmpty__020402(SqList L)//判断线性表是否为空
// {
// 	if (L.length == 0)
// 		return 1;
// 	return 0;
// }
// int GetElem__020402(SqList L, int i, ElemType* e)//取线性表第i个位置的元素
// {
// 	if(i<1||i>L.length)//判断i值是否合理，若不合理，返回ERROR
// 		return ERROR;
// 	e = L.elem[i - 1];//第i-1的单元存储着第i个数据
// 	return OK;
// }
// int LocateElem__020402(SqList L, ElemType e)//按值查找，给定值进行查找
// {
// 	for (int i = 0; i < L.length; i++)
// 	{
// 		if (L.elem[i] == e)
// 		{
// 			return i+1;//查找成功，返回序号__020402(第几个元素)
// 		}
// 	}
// 	return 0;//查找失败，返回0
// }
// Status ListInsert_Sq__020402(SqList* L, int i, ElemType e)//i是想插入的位置
// {
// 	if (i<1 || i>L->length + 1)//插入位置i不合法
// 	{
// 		return ERROR;
// 	}
// 	if (L->length == MAXSIZE)//当前存储空间已满
// 	{
// 		return ERROR;
// 	}
	
// 	for (int j = L->length - 1; j >= i - 1; j--)//插入位置及之后的元素位移
// 	{
// 		L->elem[j + 1] = L->elem[j];

// 	}
// 	L->elem[i - 1] = e;//将新元素e放入第i个位置
// 	L->length++;//表长加一
// 	return OK;
// }
// Status ListDelete_Sq__020402(SqList* L, int i)//i是要删除的元素的位置
// {
// 	if (i<1 || i>L->length)//要删除的位置不合法
// 	{
// 		return ERROR;
// 	}
// 	for (int j = i; j <= L->length-1/*移动包含最后一个元素*/; j++)//被删除的元素之后的元素前移
// 	{
// 		L->elem[j - 1] = L->elem[j];
// 	}
// 	L->length--;//表长减一
// 	return OK;
// }
// int main__020402()
// {


// 	return 0;
// }
// //\b__020402(?!if|for|switch|return)(\w+)\s*\(