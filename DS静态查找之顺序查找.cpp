#include<iostream>
#include<queue>
using namespace std;
void test(int n)
{
	int shuzu[n+1];
	int num,t;
	shuzu[0]=500;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		shuzu[i]=num;
	}
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int j;
		cin>>num;
		for(j=n;j>0;j--)
		{
			if(shuzu[j]==num)
				break;
		}
		if(j==0)
			cout<<"error"<<endl;
		else
			cout<<j<<endl;

	}
}
int main()
{
	int n;
	cin>>n;
	test(n);
	return 0;
}