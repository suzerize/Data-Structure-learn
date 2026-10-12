#include<iostream>
using namespace std;
#define MAXSIZE 100

//顺序串
struct SString 
{
	char ch[MAXSIZE];
	//len就是串的长度，和空的首元素无关
	int len;
	SString ()
	{
		len = 0;
		ch[0] = ' ';
	}
	SString (char* str)
	{
		int i = 0;
		//空首元素位置，可能有用
		ch[0] = ' ';
		len = 0;
		while (*str)
		{
			ch[i+1] = str[i];
			len++;
			i++;
		}
	}
	
	int length ()
	{
		return len;
	}

	bool empty ()
	{
		return this->len == 0;
	}
};

//链串抽象类定义
typedef struct SLnode 
{
	char data;
	SLnode * next;
}SLnode ,*SLink ;

//块链抽象类定义

typedef struct SuperSLnode 
{
	char data[50];
	SuperSLnode * next;
}SuperSLnode ;

typedef struct SuperSLink 
{
	SuperSLnode * head,*tail;
	
};
istream& operator >>(istream& i, SString & s)
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
ostream& operator <<(ostream& o, SString & s)
{
	for (int i = 1; i < s.len; i++)
	{
		o << s.ch[i];
	}
	return o;
}


int BF (SString &s,SString &t)
{
	
	int i, j;
	//假指针，从第一个有元素的位置开始
	i = j = 1;
	int len_s = s.length ();
	int len_t = t.length ();
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
	if (!t.empty () && j >= len_t + 1)
	{
		return i-j+1;
	}
	else
	{
		return 0;
	}
}

void test01 ()
{
	SString  s, t;
	cin >> s >> t;
	//测试输入字符串是否正确
	//cout << s << endl << t << endl;

	int wei = BF (s, t);
	if(wei)
	{
		cout <<  wei<< endl;
	}
	else
	{
		cout << "s里没有t" << endl;
	}
}
int main ()
{
	test01 ();

	return 0;
}
 //\b(?!if|for|return)(\w+)\s*\(

//7aaaaaab 
//4aaab