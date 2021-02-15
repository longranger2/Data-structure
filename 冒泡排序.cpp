#include<iostream>
using namespace std;
void Judge(int n)
{
	int shuzu[n],num,count=0;
	for(int i=0;i<n;i++)
	{
		cin>>shuzu[i];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n-i-1;j++)
		{
			if(shuzu[j]>shuzu[j+1])
			{
				num=shuzu[j];
				shuzu[j]=shuzu[j+1];
				shuzu[j+1]=num;
				count++;
			}
		}
	}
	cout<<count<<endl;
}
int main()
{
	int n;
	while(cin>>n)
	{
		Judge(n);
	}
	
	return 0;
}