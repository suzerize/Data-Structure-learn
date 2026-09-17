## 记录暴力搜索主串中的子串顺便实现一些串的功能

## 顺序串抽象类定义
我实现的顺序串是第一个元素为空，故串长限制为MAXSIZE-1
```cpp
struct SString
{
	char ch[MAXSIZE];
	//len就是串的长度，和空的首元素无关
	int len;
};
```
## 链串抽象类定义
与链表完全一样，只是元素固定是char类型
```cpp
//链串抽象类定义
typedef struct SLnode
{
	char data;
	SLnode* next;
}SLnode,*SLink;
```
但是空间密度极低，一个char对比一个指针而言很小
解决方法是提高一个结点所容的char

## 块链抽象类定义
块链就是将一个结点有一个char扩展到有一个char数组，这样很多个char对比一个指针就不算小了  
而链的定义也很灵活，可以有头尾指针，长度（我没写），头结点
```cpp
//块链抽象类定义

typedef struct SuperSLnode
{
	char data[50];
	SuperSLnode* next;
}SuperSLnode;

typedef struct SuperSLink
{
	SuperSLnode* head,*tail;
	
};
```

## 判空函数与求长函数
对于顺序表来说很容易实现
```cpp
int length()
{
	return len;
}

bool empty()
{
	return this->len == 0;
}
```

## 重载输入输出函数
因为用char*再输入给自定义string很麻烦，所以重载一下，不是重点，也不难
```cpp
istream& operator >>(istream& i, SString& s)
{
	cout << "输入字符串长度" << endl;
	i >> s.len;
	if (s.len+1 > MAXSIZE)
	{
		cout << "字符串过长，换一个" << endl;
	}
	for (int j = 1; j <= s.len; j++)
	{
		i >> s.ch[j];
	}
	return i;
}
ostream& operator <<(ostream& o, SString& s)
{
	for (int i = 1; i < s.len; i++)
	{
		o << s.ch[i];
	}
	return o;
}
```

## BF
重点就是回溯的思想，因为我之前做过，（用双指针，并且套两层循环，时间复杂度更高）  
这里回溯就使得不用再套循环
```cpp
int BF(SString &s,SString &t)
{
	
	int i, j;
	//假指针，从第一个有元素的位置开始
	i = j = 1;
	int len_s = s.length();
	int len_t = t.length();
	while (i < len_s + 1 && j < len_t + 1)
	{
		//若相等则从此位置开始向后判断
		if (s.ch[i] == t.ch[j])
		{
			i++;
			j++;
		}
		//否则回溯
		else
		{
			i = i - j + 2;
			//注意两个都要回溯，忘记回溯j了
			j = 1;
		}
	}

	//若j判断到头了则正确
	if (!t.empty() && j >= len_t + 1)
	{
		return i-j+1;
	}
	else
	{
		return 0;
	}
}
```

