#include<iostream>
using namespace std;
//快速排序（从小到大）
void quickSort(int left, int right, int arr[],int n)
{
	if(left >= right)
		return;
	int i, j, base, temp;
	i = left, j = right;
	base = arr[left];  //取最左边的数为基准数
	while (i < j)
	{
		while (arr[j] >=base && i < j)//向前找到第一个关键字的值小于基准数
			j--;
		arr[i]=arr[j];
		while (arr[i] <=base && i < j)//向后找到第一个关键字的值大于基准数
			i++;
		arr[j]=arr[i];
	}
	//基准数归位
	arr[i]=base;
	for(int i=0;i<n;i++)
    {
      if(i!=n-1)
		cout<<arr[i]<<" ";
      else
        cout<<arr[i];
    }
	cout<<endl;
	quickSort(left, i - 1, arr,n);//递归左边
	quickSort(i + 1, right, arr,n);//递归右边
}
int main()
{
	int t,n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		int shuzu[n];
		for(int i=0;i<n;i++)
			cin>>shuzu[i];
		quickSort(0,n-1,shuzu,n);
		cout<<endl;
	}
	return 0;
}
