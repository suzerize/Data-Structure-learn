#include<iostream>
using namespace std;
#include<vector>
#include<stack>


//由于排序对象是类型的数组或链表，类型不影响操作
//首元素为空，哨兵
struct SqList
{
	int* arr;
	int len;
};

//直接插入排序
void InsertSort(SqList& s)
{
	
	//要从第二个有效元素开始整理
	for (int i = 2; i <=s.len; i++)
	{
		//判断是否需要重新整理位置
		if (s.arr[i] < s.arr[i - 1])
		{
			//哨兵
			s.arr[0] = s.arr[i];
			int j;
			for (j = i-1; s.arr[j]>s.arr[0]; j--)
			{
				//每一次比较就跟着一次移动，并不分开写
				s.arr[j+1] = s.arr[j];
			}
			s.arr[j+1] = s.arr[0];
		}
	}
}

//折半插入
void BinsertSort(SqList& s)
{
	for (int i = 2; i <= s. len; i++)
	{
		if (s.arr[i] < s.arr[i - 1])
		{
			int low = 1, high = i - 1;
			s.arr[0] = s.arr[i];
			while (low<=high)
			{
				//可以有重复元素
				int mid = (low + high) / 2;
				if (s.arr[i] > mid)low = mid + 1;
				else high = mid - 1;
			}
			for (int j = i - 1; j >= high+1; j--)
			{
				s.arr[j + 1] = s.arr[j];
			}
			s.arr[high + 1] = s.arr[0];
		}
	}
}

//希尔排序

//不同跨度的直接排序
void InsertSort_Shell(SqList& s, int dlda)
{
	//把元素分为dlda组，开始位置为第一组的第二个元素，因为第一个元素不用排
	//范围是要排完每一组的最后一个元素，也就是到数组长
	for (int i = 1+dlda; i <= s.len; i++)
	{
		if (s.arr[i] < s.arr[i - dlda])
		{
			s.arr[0] = s.arr[i];
			int j;
			for (j = i - dlda; j>0&&s.arr[j] > s.arr[0]; j-=dlda)
			{
				s.arr[j + dlda] = s.arr[j];
			}
			s.arr[j + dlda] = s.arr[0];
		}
	}
}
//主体函数
void ShellSort(SqList& s)
{
	//生成增量序列
	stack<int>dlda;
	for(int k=1;k<=s.len;k++)
	{
		dlda.push(2*k-1);		
		k++;
	}
	while(!dlda.empty())
	{
		InsertSort_Shell(s, dlda.top());
		dlda.pop();
	}
}


//冒泡
void BubbleSort(SqList& s)
{
	//外层操作趟数
	for (int i = 1; i <= s.len - 1; i++)
	{
		//若一趟下来没有发生交换说明有序可以退出
		int flag = 0;
		//内层负责元素
		for (int j = 1; j <= s.len - i; j++)
		{
			if (s.arr[j] > s.arr[j + 1])
			{
				swap(s.arr[j], s.arr[j + 1]);
				flag = 1;
			}

		}
		if (!flag)break;
	}
}

//快速排序

//分隔函数，用于以特定元素的大小分隔开数组
int Partition(SqList& s, int low, int high)
{
	s.arr[0] = s.arr[low];
	//退出条件：low==high
	//循环补充拿走的元素
	while (low < high)
	{
		//从高处找一个比哨兵小的补充到低处
		while ( low<high && s.arr[high] > s.arr[0])
			high--;
		s.arr[low] = s.arr[high];

		//反之
		while (low < high && s.arr[low] < s.arr[0])
			low++;
		s.arr[high] = s.arr[low];

	}
	//放回哨兵
	s.arr[low] = s.arr[0];
	return high;
}
//主体函数
void QuickSort(SqList& s,int low,int high)
{
	if (low == high)return;
	
	//pivot:枢纽，partition:分隔
	//枢纽即分隔的元素
	int pivotloc = Partition(s, low, high);
	
	QuickSort(s, low, pivotloc-1);
	QuickSort(s, pivotloc + 1,high);
}

//选择
void SelectSort(SqList& s)
{
	for (int i = 1; i <= s.len-1; i++)
	{
		//擂台
		int k = i;
		for (int j = i + 1; j <= s.len; j++)
		{
			if (s.arr[j] < s.arr[k])
				k = j;
		}
		if (k != i)
			swap(s.arr[k], s.arr[i]);
	}
}

//堆排序

//堆调整
//begin和end是可以调整的位置
void HeapAdjust(SqList& s, int begin,int end)
{
	
	int dad = begin;
	//i遍历孩子，遍历孩子的孩子
	for (int i = 2 * begin; i <= end; i*=2)
	{
		//比较begin的两个孩子，取较小者
		//首先确定存在
		if (i+1<=end&&s.arr[i] > s.arr[i + 1])i++;

		//有孩子比begin小，那么互换值，并且调整这个孩子结点
		if (s.arr[i] < s.arr[dad])
		{
			swap(s.arr[i], s.arr[dad]);
			dad = i;
		}
		//若没有比begin小的孩子，说明不需要再调
		else break;
	}
}
void HeapSort(SqList& s)
{

	//创建一个堆，小根
	for (int i = s.len/2; i >=1; i--)
	{
		//创建时从最后一个非叶子开始，
		//完全创建好之前任何一个元素都可能变位置，不应该被排除
		HeapAdjust(s, i,s.len );
	}

	for (int i = 1; i <= s.len; i++)
	{
		
		swap(s.arr[1], s.arr[s.len]);
		//开始位置固定是顶部，调整后底部的元素就相当于删除了，不应该调整
		HeapAdjust(s, 1,i-1);
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