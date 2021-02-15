//法1
/*#include<iostream>
#include<string>
using namespace std;

class myString
{
	private:
		string mainstr;
		int size;
		void GetNext(string p,int next[])//设置next数组 
		{
			int j=0;
			next[0]=-1;
			next[1]=0;
			int m=p.length();
			int k=0;
			for(int j=2;j<m;j++)
			{
				while(k>0&&p[k]!=p[j-1])
				{
					k=next[k];
				}
				if(p[k]==p[j-1])
					++k;
				next[j]=k;
			}
		
		int KMPFind(string p,int pos,int next[])
		{
			int j=0;
			int i=pos;
			int m=p.length();
			for(int i=0;i<size;i++)
			{
				while(j>0&&mainstr[i]!=p[j])
				{
					j=next[j-1]+1;
				}
				if(mainstr[i]==p[j])
					j++;
				if(j==m)
					return i-m+2;
			}
			return 0;
		}
	public:
		myString()
		{
			size=0;
			mainstr="";
		}
		~myString()
		{
			size=0;
			mainstr="";
		}
		void SetVal(string sp)
		{
			mainstr="";
			mainstr.assign(sp);
			size=mainstr.length();
		}
		int KMPFindSubstr(string p,int pos)
		{
			int i;
			int L=p.length();
			int *next=new int[L];
			GetNext(p,next);
			for(i=0;i<L;i++)
				cout<<next[i]<<' ';
			cout<<endl;
			int v=-1;
			v=KMPFind(p,pos,next);
			delete []next;
			return v;	
		}
};
int main()
{
	int t,outcome;
	cin>>t;
	while(t--)
	{
		string s1,s2;
		cin>>s1>>s2;
		myString str;
		str.SetVal(s1);
		outcome=str.KMPFindSubstr(s2,0);
		cout<<outcome<<endl;
	}
}
*/

#include<iostream>
using namespace std;
class  myString
{
private:
	string mainstr;
	int size;
	void GetNext(string p,int next[])
	{//将模式串p的next函数值存入数组next
		int i=0,j=-1;
		next[i]=j;
		while(i<p.length())
		{
			if(j==-1||p[i]==p[j])
			{
				next[++i]=++j;
			}
			else
				j=next[j];
		}
	}
	int KMPFind(string p,int pos,int next[])//p是模式串
	{
		cout<<p.length()<<" "<<p.size()<<endl;
		int t=p.length();
		int i=pos,j=0;
		while(i<size&&j<t)//注意这里p的长度必须赋值给另一个中间变量，不能直接用j<p.length()，否则会出问题
		{
			if(j==-1||mainstr[i]==p[j])
			{
				++i;
				++j;
			}
			else 
				j=next[j];
		}
		if(j==p.length())
			return i-j+1;//传回匹配的是起始位置
		else
			return 0;//没有则传回0
	}
public:
	 myString();
	~ myString();
	void SetVal(string sp);
	int KMPFindSubstr(string p,int pos);
};
myString::myString()
{
	size=0;
	mainstr="";
}
myString::~myString()
{
	size=0;
	mainstr="";
}
void myString::SetVal(string sp)
{
	mainstr="";
	mainstr.assign(sp);
	size=mainstr.length();
}
int myString::KMPFindSubstr(string p,int pos)
{
	int i;
	int L=p.length();
	int *next=new int[L];
	GetNext(p,next);
	for(i=0;i<L;i++)
	{
		if(i!=L-1)
			cout<<next[i]<<" ";
		else
			cout<<next[i];
	}
	cout<<endl;
	int v=-1;
	v=KMPFind(p,pos,next);
	delete []next;
	return v;
}
int main()
{
	int t,flag;
	cin>>t;
	while(t--)
	{
		string p,pos;
		cin>>p>>pos;
		myString ms;
		ms.SetVal(p);
		flag=ms.KMPFindSubstr(pos,0);
		cout<<flag<<endl;
	}
	return 0;
}


//法3
/*
#include <iostream>
#include <string>
using namespace std;

class myString{
    string S;
    string T;
    int *next;
    void getNext();
public:
    myString();
    ~myString();
    int KMP();
    void output();
};

myString::myString() {
    cin>>S>>T;
    next = new int[T.size()];
}

myString::~myString() {
    delete []next;
}

int myString::KMP() {
    int i,j;

    for(i=0,j=0;i<S.size() && j<(int)T.size();)
    {
        if(j==-1 || S[i] == T[j])
            i++,j++;
        else
            j = next[j];
    }
    if(j == T.size())
        return i-j+1;
    return 0;
}

void myString::getNext() {
    int i,j;
    i=0,j=-1;
    next[i] = j;
    while (i<T.size())
    {
        if(j==-1 || T[i] == T[j])
            next[++i] = ++j;
        else
            j = next[j];
    }
}

void myString::output() {
    getNext();
    for(int i=0;i<(int)T.size();i++)
        cout<<next[i]<<' ';
    cout<<endl;
    cout<<KMP()<<endl;
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        myString s;
        s.output();
    }
    return 0;
}*/

