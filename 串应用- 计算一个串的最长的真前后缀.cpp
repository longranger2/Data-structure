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
		//cout<<p.length()<<" "<<p.size()<<endl;
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
		string p,pos,change;
		cin>>p>>pos>>change;
		cout<<p<<endl;
		myString ms;
		ms.SetVal(p);
		flag=ms.KMPFindSubstr(pos,0);
		int n=p.length();
		int m=pos.length();
		if(flag!=0)
		{
			for(int i=0;i<flag-1;i++)
				cout<<p[i];
			cout<<change;
			for(int i=flag+m-1;i<n;i++)
				cout<<p[i];
			cout<<endl;
		}
		else
			cout<<p<<endl;
	}
	return 0;
}