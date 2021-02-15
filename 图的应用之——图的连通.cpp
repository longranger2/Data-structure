#include<iostream>
using namespace std;
#define Maxlen 50
/*bool Judge(int n,int m[Maxlen][Maxlen])
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(m[i][j]==0&&m[i][k]==1&&m[k][j]==1)
                    m[i][j]=1;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            else
            {
                if(m[i][j]!=1||m[j][i]!=1)
                    return false;
            }
        }
    }
    return true;
}*/
int Judge(int n,int m[Maxlen][Maxlen])
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(m[i][j]==1)
            {
                for(int k=0;k<n;k++)
            {
                    if(m[j][k]==1&&m[i][k]!=1)//借助j为跳板，连接到其他点
                        m[i][k]=1;
            }
            }
            
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<m[i][j]<<" ";
        cout<<endl;
    }
        
    for(int i=0;i<n;i++) 
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
                continue;
            else
            {
                if(m[i][j]==0)
                {
                    //cout<<"No"<<endl;
                    return 0;
                }
            }
        }
    }
    return 1;
}
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int n;
        cin>>n;
        int m[Maxlen][Maxlen];
        for(int i=0;i<Maxlen;i++)
            for(int j=0;j<Maxlen;j++)
                m[i][j]=0;
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>m[i][j];
        if(Judge(n,m))
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}