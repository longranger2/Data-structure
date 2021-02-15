#include <iostream>
#include <string>
using namespace std;

int* GetNext (string str)
{
	int j=0,k=-1;
	int len=(int)str.size();
	int *next=new int[len+1];
	next[j]=k;
	while(j<=len)
	{
		if(k==-1||str[j]==str[k])
			next[++j]=++k;
		else
			k=next[k];
	}
	return next;
}
int matched_Prefix_Postfix(string str)
{
	int *next=GetNext(str);
	int len=(int)str.size(); 
	int max=-1;
	for(int i=0;i<=len;i++)
		if(max<next[i])
			max=next[i];
	delete []next;
	if(max<=0) 
		return -1;
	else 
		return max;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<matched_Prefix_Postfix(s)<<endl;
	}
}