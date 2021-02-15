#include <iostream>
using namespace std;

void Sort(int i, int n, int *shuzu)//建立最小堆 i是当前结点
{
    int j = 2*i;
    while(j<=n)
    {
        if(j<n && shuzu[j]>shuzu[j+1])//左子树大于右子树
            j++;//将j指向右子树
        if(shuzu[j]<shuzu[i])//只有右子树也小于当前结点时才交换
        {
            shuzu[0] = shuzu[i];//shuzu[0]是用于存放零时变量
            shuzu[i] = shuzu[j];
            shuzu[j] = shuzu[0];
        }
        i = j;//往下重新调整排序
        j = 2*i;
    }
}

void PostOrder(int i, int n, int *shuzu)
{//数组存储的后序遍历和树存储其实是一样的
    if(i<=n)
    {
        PostOrder(2*i, n, shuzu);
        PostOrder(2*i+1, n, shuzu);
        cout<<shuzu[i]<<' ';
    }
}

int main()
{
    int i, n;
    cin>>n;
    int shuzu[n+1];
    for(i=1; i<=n; i++)
        cin>>shuzu[i];
    for(i=n/2; i>=0; i--)//这里只需要建立初始堆就行了，没有把根和最后一个交换的操作（用堆排序才会用到）
        Sort(i, n, shuzu);//从树的中间高度开始排序，从下往上将最小的往上推
    PostOrder(1, n, shuzu);
}