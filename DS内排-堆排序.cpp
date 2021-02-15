#include <iostream>
using namespace std;
void heapify(int *nums,int loc,int n)    //对长度为n的堆的第loc个结点进行维护
{   
    int left = 2*loc+1;
    int right = 2*loc+2;
    if(left < n)
    {
        if(right <n)
        {
            if(nums[left] > nums[right])
            {
                if(nums[right] < nums[loc])    //若右孩子为最小值，则交换右孩子与父节点的值，然后重新维护右孩子的子树的父子大小关系
                {
                    swap(nums[right],nums[loc]);
                    heapify(nums,right,n);
                }
            }
            else
            {
                if(nums[left] < nums[loc])    //若左孩子为最小值，则交换左孩子与父节点，然后重新维护左孩子的子树的父子大小关系
                {
                    swap(nums[left],nums[loc]);//只交换值
                    heapify(nums,left,n);
                }
            }
        }
        else
        {
            if(nums[left] < nums[loc])    //若左孩子为最小值，则交换左孩子与父节点，然后重新维护左孩子的子树的父子大小关系
            {
                swap(nums[left],nums[loc]);
                heapify(nums,left,n);
            }
        }
    }  
    /*int j=2*loc;//对长度为n的堆的第loc个结点进行维护
    while(j<n)
    {
        if(j<n-1&&nums[j]>nums[j+1])
            j++;
        if(nums[j]<nums[loc])
        {
            swap(nums[j],nums[loc]);
        }
        loc=j;
        j=2*loc;
    }*/


}
void heap_sort(int n)
{
    int *nums;
    nums = new int[n];
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    for(int i = n/2; i >= 0; i--)    //建堆过程：从第n/2个结点开始递减到第1个结点，依次维护结点的父子大小关系
    {
        heapify(nums,i,n);
    }
 
    cout<<n<<' ';
    for(int i = 0; i < n; i++)    //输出堆
    {
        cout<<nums[i];
        if(i != n-1)
            cout<<' ';
    }
    cout<<endl;
    for(int t = n-1; t >= 1; t--)
    {
        swap(nums[0],nums[t]);    //将第1个结点与最后一个结点交换
        heapify(nums,0,t);        //然后维护第1个结点的父子关系
        cout<<n<<' ';
        for(int i = 0; i < n; i++)  //输出堆
        {
            cout<<nums[i];
            if(i != n-1)
                cout<<' ';
        }
        cout<<endl;
    }
}
int main()
{
    int t;
    cin>>t;
    heap_sort(t);
}