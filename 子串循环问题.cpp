#include<iostream>
#include<string>
using namespace std;
int *GetNext(string str)
{
	int m=str.length();
	int *next=new int[m+1];
	int i=0;
	next[0]=-1;
	int k=-1;
	while(i<m)
	{
		if(k==-1||str[k]==str[i])
		{
			++i;
			++k;
			next[i]=k;
		}
		else
			k=next[k];
	}
	return next;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string str;
		cin>>str;
		int *next=GetNext(str);
		if(next[str.length()]==str.length()-1)
			cout<<0<<endl;
		else 
		{
			cout<<str.length()-2*next[str.length()]<<endl;
		}
	}
	return 0;
}