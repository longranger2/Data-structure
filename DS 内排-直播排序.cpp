#include<iostream>
using namespace std;
void insertSort(int a[], int n)
{
   for(int i = 1; i < n; i++) //第一个元素作为基准元素，从第二个元素开始把其插到正确的位置
   {
	  if(a[i] < a[i-1]) //如果第i个元素比前面的元素小
	  {
	    int j = i-1;     //需要判断第i个元素与前面的多个元素的大小，换成j继续判断
        int x = a[i]; //将第i个元素复制为哨兵
	    while(j >= 0 && x < a[j]) //找哨兵的正确位置，比哨兵大的元素依次后移
	    {
           	a[j+1] = a[j]; 
	        j--;
	    }
	    a[j+1] = x;  //把哨兵插入到正确的位置
	  }   
	  for(int t=0;t<n;t++)
	  	cout<<a[t]<<" ";
	  cout<<endl;
   }
}

int main()
{
	int n;
	cin>>n;
	int shuzu[n];
	for(int i=0;i<n;i++)
		cin>>shuzu[i];
	insertSort(shuzu,n);
	return 0;
}