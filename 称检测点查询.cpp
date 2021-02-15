#include<iostream>
using namespace std;

int main()
{
	int n,x,y,x1,y1,flag;
	float dist,min=9999999;
	cin>>n>>x>>y;
	float shuzu[n];
	for(int i=0;i<n;i++)
	{
		cin>>x1>>y1;
		dist=(x-x1)*(x-x1)+(y-y1)*(y-y1);
		shuzu[i]=dist;
	}
	for(int j=0;j<3;j++)
	{
		for(int i=0;i<n;i++)
	{
		if(min>shuzu[i])
		{
			flag=i;
			min=shuzu[i];
		}
	}
		shuzu[flag]=99999;
		min=99999;
		cout<<flag+1<<endl;
	}
	
	return 0;
}