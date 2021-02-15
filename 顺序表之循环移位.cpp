#include<iostream>
using namespace std;
int main()
{
	int n,flag,dist;
	cin>>n;
	int shuzu[n];
	for(int i=0;i<n;i++)
		cin>>shuzu[i];
	for(int i=0;i<n;i++)
		cout<<shuzu[i]<<" ";
	cout<<endl;
	for(int t=0;t<2;t++)
	{
		cin>>flag>>dist;
		int *temp=new int[n];
		for(int i=0;i<n;i++)
			temp[i]=shuzu[i];
		if(flag==0)
		{
			int j=0;
			int begin=dist%5;
			for(int i=begin;i<n;i++)
				shuzu[j++]=temp[i];
			for(int i=0;i<begin;i++)
				shuzu[j++]=temp[i];
		}
		else
		{
			int j=0;
			int begin=(n-dist)%5;
			for(int i=begin;i<n;i++)
				shuzu[j++]=temp[i];
			for(int i=0;i<begin;i++)
				shuzu[j++]=temp[i];
		}
		for(int i=0;i<n;i++)
			cout<<shuzu[i]<<" ";
		cout<<endl;

	}
	
	return 0;
}