#include <iostream>
using namespace std;
//法1
void DFS(int **m,int n,int *visit,int temp) 
{
    int *temp_visit=new int [n];
    for(int i=0;i<n;i++)
        temp_visit[i]=visit[i];   //复制visit的状态，因为在DFS中不能改变原来visit状态
    for(int j=0;j<n;j++)
    {
        if(m[temp][j]==1 && temp_visit[j]==0)       //对所有visit=0且连着的顶点递归调用DFS
        {
            temp_visit[j]=1;
            DFS(m,n,temp_visit,j);
        }
    }
    for(int j=0;j<n;j++)    //DFS完后，更新顶点连通信息，此时所有和顶点连着的顶点都是完美状态
    {
        
        if(m[temp][j]==1)
        {
            for(int k=0;k<n;k++)
            {
                if(m[j][k]==1)
                    m[temp][k]=1;
            }
        }
    }
}
void test(int n)
{
    int **m;
    m=new int*[n];
    for(int i=0;i<n;i++)        //以邻接矩阵格式输入图的信息
    {
        m[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>m[i][j];
    }
    int *visit=new int[n];
    for(int i=0;i<n;i++)        //visit数组初始化为0代表所有顶点都没访问过
        visit[i]=0;
    for(int i=0;i<n;i++)
    {
        if(visit[i]==0)
        {
            visit[i]=1;        //每访问一个顶点，都要把visit变成1
            DFS(m,n,visit,i);
        }
    }
    for(int i=0;i<n;i++)        //输出
    {
        for(int j=0;j<n;j++)
        {
            cout<<m[i][j];
            if(j!=n-1)
                cout<<' ';
        }
        cout<<endl;
    }
    delete []m;
}
int main()
{
    int t;
    cin>>t ;  //每次输入t代表顶点个数
        test(t);
    return 0;
}
/*
//法2
#include <iostream>
using namespace std;
void test(int n)
{
    int **m;
    m=new int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>m[i][j];
    }
    int flag=1;        //flag表示是否有更新，如果有的话，就无限遍历下去
    while(flag)
    {
        flag=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(m[i][j]==1)//j是另一个元素 A->B,则去找B对应的是否有元素与之对应
                {
                    for(int k=0;k<n;k++)
                    {
                        if(m[j][k]==1  && m[i][k]!=1)
                        {
                            m[i][k]=1;
                            flag=1;            //有更新就把flag置为1
                        }
                    }
                }
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<m[i][j];
            if(j!=n-1)
                cout<<' ';
        }
        cout<<endl;
    }
    delete []m;
}
int main()
{
    int t;
    while(cin>>t)
        test(t);
    return 0;
}*/