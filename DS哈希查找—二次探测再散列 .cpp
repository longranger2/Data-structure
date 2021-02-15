#include<iostream>
#include<math.h>
using namespace std;
int H(int key)
{
	return key%11;
}
void Judge(int b[],int num,int m)
{
	int flag=-1,yu,count=0,pos,d=1;
	yu=num%11;
	/*int dist[m];
	for(int i=0;i<m;i++)
	{
		dist[i]=pow(-1,i)
	}*/
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
		else//发生冲突时
		{	
			yu+=pow(-1,i)*d*d;
			if(i%2==0)
				d++;
			else if(yu>m)
				yu-=m;
			else if(yu<0)
				yu+=m;
			
		}
		
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
	int final[m];
	for(int i=0;i<m;i++)
	{
		final[i]=-1;
	}
	for(int i=0;i<n;i++)
	{
		if(final[H(a[i])]==-1)
		{
			final[H(a[i])]=a[i];
		}
		else
		{
			int x=H(a[i]);
			while(final[x%m]!=-1)
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