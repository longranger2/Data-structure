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
		int low=1,high=n;
		int mid=(low+high)/2;
		while(low<=high)
		{
			if(num==shuzu[mid])
			{
				cout<<mid<<endl;
				break;
			}
			else if(num<shuzu[mid])
			{
				high=mid-1;
				mid=(high+low)/2;
			}
			else if(num>shuzu[mid])
			{
				low=mid+1;
				mid=(high+low)/2;
			}
		}
		if(low>high)
			cout<<"error"<<endl;

	}
}
int main()
{
	int n;
	cin>>n;
	test(n);
	return 0;
}