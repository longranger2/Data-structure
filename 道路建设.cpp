#include <iostream>
#include <string>
#include <vector>
using namespace std;
bool go_on(int *visit,int n)
{
    for(int i=0;i<n;i++)
        if(visit[i]==0)
            return 1;
    return 0;
}
void prim(int **m,int n) //n为村庄数
{
    int *visit=new int[n];
    for(int i=0;i<n;i++)
        visit[i]=0;
    int q,t1,t2;
    cin>>q;
    while(q--)
    {
        cin>>t1>>t2;
        m[t1-1][t2-1]=0;//将原本就有路的顶点的值设为0
        m[t2-1][t1-1]=0;
    }
    struct{
        int point;
        int lowcost;
    }closedge[n];
 
    int temp;
    for(int i=0;i<n;i++)//初始化，每个顶点都找到离他最近的那个点
    {
        closedge[i].lowcost=5000;
        closedge[i].point=n+1;
        for(int j=0;j<n;j++)
        {
            if(visit[j]==0 && closedge[i].lowcost>m[i][j])
            {
                closedge[i].lowcost=m[i][j];
                closedge[i].point=j;
            }
        }
    }
    int mmin,loc;
    int last=0;
    visit[0]=1;
    while(go_on(visit,n))//只要一个村庄没通路就一直下去
    {
        mmin=5000;
        for(int j=0;j<n;j++)
        {
            if(visit[j]==0)
                continue;
            else
            {
                if(mmin>closedge[j].lowcost&&closedge[j].point != n+1)
                {
                    mmin=closedge[j].lowcost;
                    loc=j;
                }
            }
        }
        last+=mmin;
        visit[closedge[loc].point]=1;
        m[loc][closedge[loc].point]=10000;
        m[closedge[loc].point][loc]=10000;
        for(int i=0;i<n;i++)//重新初始化一遍
        {
            closedge[i].lowcost=5000;
            closedge[i].point=n+1;
            for(int j=0;j<n;j++)
            {
                if(visit[j]==0 && closedge[i].lowcost>m[i][j])
                {
                    closedge[i].lowcost=m[i][j];
                    closedge[i].point=j;
                }
            }
        }
    }
    cout<<last<<endl;
    delete []visit;
}
void test(int n)
{
    int k;
    int **m;
    m=new int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            cin>>m[i][j];
            if(m[i][j]==0)
                m[i][j]=100000;//若是自己则将其值设为无限大，后面就不会影响后面的操作
        }
    }
    prim(m,n);
    delete []m;
}
int main()
{
    int t;
    while(cin>>t)
    {
        test(t);
    }
    return 0;
}