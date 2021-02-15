#include<iostream>
#include<math.h>
using namespace std;
void test(double n)
{
	
		double low=0,high=n;
		double  mid=(low+high)/2;
		while(fabs(mid*mid-n)<0.00001)
		{
			
			if(mid*mid<n)
			{
				low=mid;
				mid=(high+low)/2;
			}
			else if(mid*mid>=n)
			{
				high=mid;
				mid=(high+low)/2;
			}
		}
		printf("%.3lf\n",mid);

	
}
int main()
{
	double n;
	cin>>n;
	test(n);
	return 0;
}