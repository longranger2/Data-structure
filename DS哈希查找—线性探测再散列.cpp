#include<iostream>
using namespace std;
int H(int key)
{
	return key%11;
}
void Judge(int b[],int num,int m)
{
	int flag=-1,yu,count=0,pos;//count用来计数，查找的次数
	yu=num%11;
	for(int i=0;i<m;i++)
	{
		count++;
		if(b[yu]==num)
		{
			flag=1;
			pos=yu+1;
			break;
		}
		else if(b[yu]==-1)
		{
			flag=0;
			break;
		}
		yu=(yu+1)%m;
	}
	if(flag==1)
	{
		cout<<flag<<" "<<count<<" "<<pos<<endl;
	}
	else if(flag==0||flag==-1)
	{
		cout<<0<<" "<<count<<endl;
	}
}
void Hash(int a[],int m,int n)//m为表长
{
	int final[m];//标记作用
	for(int i=0;i<m;i++)//初始化
	{
		final[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(final[H(a[i])]==-1)//找到空置的位置
		{
			final[H(a[i])]=a[i];
		}
		else//移位
		{
			int x=H(a[i]);
			while(final[x%m]!=-1)//在final[]数组中循环重复
			{
			x+=1;
			if(final[x%m]==-1)
			{
				final[x%m]=a[i];
				break;
			}
		}
		}
	}
	for(int i=0;i<m;i++)
	{

		if(i!=m-1)
		{
			if(final[i]!=-1)
				cout<<final[i]<<" ";
			else
				cout<<"NULL"<<" ";
		}
		else
		{
			{
			if(final[i]!=-1)
				cout<<final[i]<<endl;
			else
				cout<<"NULL"<<endl;
		}
		}
	}
	int time,num;
	cin>>time;
	while(time--)
	{
		cin>>num;
		Judge(final,num,m);

	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		int shuzu[m];
		for(int i=0;i<n;i++)
			cin>>shuzu[i];
		Hash(shuzu,m,n);
	}
	return 0;
}