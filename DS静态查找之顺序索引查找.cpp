#include<iostream>
using namespace std;
void test()
{
	int n,t,time,num,count;
	cin>>n;
	int shuzu[n];
	for(int i=0;i<n;i++)
	{
		cin>>shuzu[i];
	}
	cin>>t;
	int flag[t];
	for(int i=0;i<t;i++)
	{
		cin>>flag[i];
	}
	cin>>time;
	while(time--)
	{
		int j,Flag=0;
		count=0;
		cin>>num;
		for(j=0;j<t;j++)  //找到num的范围
		{
			count++;
			if(num<=flag[j])
			{
				break;
			}
		}
		int k;
		if(j==0)
		{
			k=0;
			while(shuzu[k]<=flag[j])
			{
				count++;
				if(shuzu[k]==num)
				{
					Flag=1;
					break;				
				}
				k++;
			}
		}
		else if(j==t-1)
		{
			for(k=0;k<n;k++)
			{
				if(shuzu[k]>flag[j-1])
					break;
			}
			for(;k<n;k++)
			{
				count++;
				if(shuzu[k]==num)
				{
					Flag=1;
					break;				
				}
			}
		}
		else 
		{
			for(k=0;k<n;k++)
			{
				if(shuzu[k]>flag[j-1])
					break;
			}
			while(shuzu[k]<=flag[j+1])
			{
				count++;
				if(shuzu[k]==num)
				{
					Flag=1;
					break;				
				}
				k++;
			}
		}
		if(Flag==0)
			cout<<"error"<<endl;
		else
			cout<<k+1<<"-"<<count<<endl;
	}


}
int main()
{
	test();
	return 0;
}