#include <iostream>
using namespace std;
void test(int *shuzu,int n,int gap)
{
    int k,i,j,temp;
    for(k=0;k<n;k++) //希尔排序
    {
        for (i = k; i < n; i+=gap )//插入排序
        {
            temp = shuzu[i];//存放当前值
            for (j = i; j > k; j-=gap) 
            {
                if (temp > shuzu[j - gap])
                    shuzu[j] = shuzu[j - gap]; //往后移
                else
                    break;
            }
            shuzu[j] = temp; 
        }
    }
    for(i=0;i<n;i++) 
    {
        cout << shuzu[i];
        if(i!=n-1)
            cout<<' ';
    }
    cout<<endl;
}
int main() 
{
    int t;
    cin>>t;
    while (t--) 
    {
        int n;
        int *shuzu;
        cin >> n;
        shuzu = new int[n];
        for(int i=0;i<n;i++)
            cin>>shuzu[i];
        int gap=n/2;
        while (true)
        {
            test(shuzu,n,gap);
            if(gap==1)
                break;
            gap/=2;
        }
        cout<<endl;
    }
    return 0;
}