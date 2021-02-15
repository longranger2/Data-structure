#include<iostream>
using namespace std;
#define Maxlen 20
void test(int n)
{
	int *visit=new int[n];
	int flag;
	int shuzu[Maxlen][Maxlen];
	for(int i=0;i<n;i++)
		visit[i]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			shuzu[i][j]=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>shuzu[i][j];
	for(int t=0;t<n;t++)//最多执行n次
	{
		for(int j=0;j<n;j++)//行向量
		{
			if(!visit[j])
			{
				flag=0;
				for(int i=0;i<n;i++)//找到入度为0的点
				{
					if(shuzu[i][j]==1)
					{
						flag=1;
						break;
					}
				}
				if(flag==0)
				{
					visit[j]=1;
					for(int i=0;i<n;i++)
						shuzu[j][i]=0;
					cout<<j<<" ";
				}
			}
			
		}
	}
	cout<<endl;
}

int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		test(n);
	}
	return 0;
}