#include <iostream>
#include <string>
#include <vector>
using namespace std;
void prim(int **m,string *s,int n,string start_point)//s是顶点集合的数组
{
    int *visit=new int[n];         //用一个数组visit表示结点是否被访问过，初始化为0表示没有访问
    for(int i=0;i<n;i++)
        visit[i]=0;
    struct
    {                 //用一个结构体数组表示每个结点的最小权值和最小权值边所连着的结点
        string adj;         //最小权值边所连着的结点
        int lowcost;        //结点的最小权值
    }closedge[n];
    int temp;
    for(int i=0;i<n;i++)        //初始化所有结点的最小权值边所连着的结点和最小权值
    {
        temp=m[i][0];//临时变量用于存放结点的最小权值
        closedge[i].adj=s[0];
        closedge[i].lowcost=temp;
        for(int j=1;j<n;j++)
        {
            if(temp>m[i][j])
            {
                temp=m[i][j];
                closedge[i].adj=s[j];
                closedge[i].lowcost=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]==start_point)
        {
            visit[i]=1;             //将开始结点的visit值置为1表示从开始结点开始生成树
            break;
        }
    }
    int mmin,loc;
    string t;
    vector<string> v_one;           //用于存输出的第一个结点
    vector<string> v_two;           //用于存输出的第二个结点
    vector<int> the_min;            //用于存每次的最小值
    for(int i=0;i<n-1;i++)          //外循环，要循环n-1次才能找到最小生成树
    {
        mmin=100000000;
        for(int j=0;j<n;j++)
        {
            if(visit[j]!=1)         //每次要找的是visit为1的结点的最小权值，所以遇到visit不为1的结点，就直接跳过
                continue;
            else//结点为1
            {
                if(mmin>closedge[j].lowcost)           //更新每次要找的是visit为1的结点的最小权值
                {
                    mmin=closedge[j].lowcost;           //记录下最小权值
                    t=closedge[j].adj;                 //记录下最小权值连的结点
                    loc=j;                              //记录是由第几个结点找到最小权值的
                }
            }
        }
        v_one.push_back(s[loc]);
        v_two.push_back(t);
        the_min.push_back(mmin);            
        for(int i=0;i<n;i++)
        {
            if(s[i]==t)//最小权值连的结点
            {
                visit[i]=1;                //找最小权值边后，需要将最小权值边所连的结点的visit置为1，表示结点已经访问过
                m[loc][i]=10000000;         //找到后，要2个结点之间的权值更新成无穷大，这里用一个较大的数表示无穷大就可以了
                m[i][loc]=10000000;
                break;
            }
        }
        for(int i=0;i<n;i++)               //更新所有结点的最小权值边所连着的结点和最小权值，因为前面找到最小全值时对m数组进行了修改
        {
            temp=m[i][0];
            closedge[i].adj=s[0];
            closedge[i].lowcost=temp;
            for(int j=1;j<n;j++)
            {
                if(temp>m[i][j]&&visit[j]!=1)
                {
                    temp=m[i][j];
                    closedge[i].adj=s[j];
                    closedge[i].lowcost=temp;
                }
            }
        }
    }
    int last=0;
    for(int i=0;i<v_one.size();i++)
        last+=the_min[i];
    cout<<last<<endl;
    cout<<"prim:"<<endl;
    for(int i=0;i<v_one.size();i++)
    {
        cout<<v_one[i]<<' '<<v_two[i]<<' '<<the_min[i]<<endl;
    }
    delete []visit;
}
void kruskal(int **m,string *s,int n)
{
    cout<<"kruskal:"<<endl;
    int *father=new int[n];         //用一个父节点数组表示结点所在树的阵营，初始话为1到n，表示一开始有n个阵营
    for(int i=0;i<n;i++)
        father[i]=i;
    int temp_min;
    string s1,s2;
    int loc1,loc2;
    for(int i=0;i<n-1;i++)  //外循环，要循环n-1次才能找到最小生成树
    {
        temp_min=10000000;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(father[j]==father[k])        //如果所要加入边的2个点所在的阵营一样，则加如边会导致成环，所以跳过
                    continue;
                else
                {
                    if(temp_min>m[j][k])        //找到非同一阵营的最短的边
                    {
                        temp_min=m[j][k];
                        loc1=j;                 //loc1和loc2表示边所连的2个结点
                        loc2=k;
                    }
                }
            }
        }
        cout<<loc1<<" "<<loc2<<endl;
        for(int i=0;i<n;i++)
            cout<<father[i]<<" ";
        cout<<endl;
        m[loc1][loc2]=10000000;             //找到后，将2个结点之间的距离置为无穷大
        m[loc2][loc1]=10000000;
        if(loc1>loc2)                       //按照结点的先后顺序，升序输出结点，最后输出最小权值
        {
            cout<<s[loc2]<<' '<<s[loc1]<<' '<<temp_min<<endl;
            for(int i=0;i<n;i++)            //当每加入一条边后，要把这条边所在的树更新为同一个阵营
            {
                if(father[i]==father[loc1] &&i!=loc1)
                    father[i]=father[loc2];
            }
            father[loc1]=father[loc2];
        }
        else
        {
            cout<<s[loc1]<<' '<<s[loc2]<<' '<<temp_min<<endl;
            for(int i=0;i<n;i++)            //当每加入一条边后，要把这条边所在的树更新为同一个阵营
            {
                if(father[i]==father[loc2] && i!=loc2)
                    father[i]=father[loc1];
            }
            father[loc2]=father[loc1];
        }
    }
    delete []father;
}
void test(int n)
{
    int k;
    string *s=new string[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int **m,**m1;
    m=new int*[n];
    m1=new int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new int[n];
        m1[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            m[i][j]=10000000;
            m1[i][j]=10000000;
        }
    }
    cin>>k;
    string temp1,temp2;
    int flag1,flag2,cost;
    for(int i=0;i<k;i++)
    {
        cin>>temp1>>temp2>>cost;
        for(int p=0;p<n;p++)
        {
            if(s[p]==temp1)
                flag1=p;
            if(s[p]==temp2)
                flag2=p;
        }
        m[flag1][flag2]=cost;
        m[flag2][flag1]=cost;
        m1[flag1][flag2]=cost;
        m1[flag2][flag1]=cost;
    }
    string start_point;
    cin>>start_point;
    prim(m,s,n,start_point);
    kruskal(m1,s,n);
    delete []m;
    delete []m1;
    delete []s;
}
int main()
{
    int t;
    cin>>t;
    test(t);
    return 0;
}
/*
#include <iostream>
#include <string>
#include <vector>
using namespace std;
void prim(int **m,string *s,int n,string start_point)
{
    int *visit=new int[n];         
    for(int i=0;i<n;i++)
        visit[i]=0;
    struct{                
        string adj;         
        int lowcost;        
    }closedge[n];
    int temp;
    for(int i=0;i<n;i++)       
    {
        temp=m[i][0];
        closedge[i].adj=s[0];
        closedge[i].lowcost=temp;
        for(int j=1;j<n;j++)
        {
            if(temp>m[i][j])
            {
                temp=m[i][j];
                closedge[i].adj=s[j];
                closedge[i].lowcost=temp;
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        if(s[i]==start_point)
        {
            visit[i]=1;             
            break;
        }
    }
    int mmin,loc;
    string t;
    vector<string> v_one;        
    vector<string> v_two;          
    vector<int> the_min;           
    for(int i=0;i<n-1;i++)         
    {
        mmin=100000000;
        for(int j=0;j<n;j++)
        {
            if(visit[j]!=1)         
                continue;
            else
            {
                if(mmin>closedge[j].lowcost)           
                {
                    mmin=closedge[j].lowcost;        
                    t=closedge[j].adj;                 
                    loc=j;                              
                }
            }
        }
        v_one.push_back(s[loc]);
        v_two.push_back(t);
        the_min.push_back(mmin);            
        for(int i=0;i<n;i++)
        {
            if(s[i]==t)
            {
                visit[i]=1;                
                m[loc][i]=10000000;         
                m[i][loc]=10000000;
                break;
            }
        }
        for(int i=0;i<n;i++)              
        {
            temp=m[i][0];
            closedge[i].adj=s[0];
            closedge[i].lowcost=temp;
            for(int j=1;j<n;j++)
            {
                if(temp>m[i][j]&&visit[j]!=1)
                {
                    temp=m[i][j];
                    closedge[i].adj=s[j];
                    closedge[i].lowcost=temp;
                }
            }
        }
    }
    int last=0;
    for(int i=0;i<v_one.size();i++)
        last+=the_min[i];
    cout<<last<<endl;
    cout<<"prim:"<<endl;
    for(int i=0;i<v_one.size();i++)
    {
        cout<<v_one[i]<<' '<<v_two[i]<<' '<<the_min[i]<<endl;
    }
    delete []visit;
}
void kruskal(int **m,string *s,int n)
{
    cout<<"kruskal:"<<endl;
    int *father=new int[n];        
    for(int i=0;i<n;i++)
        father[i]=i;
    int temp_min;
    string s1,s2;
    int loc1,loc2;
    for(int i=0;i<n-1;i++)
    {
        temp_min=10000000;
        for(int j=0;j<n;j++)
        {
            for(int k=0;k<n;k++)
            {
                if(father[j]==father[k])        
                    continue;
                else
                {
                    if(temp_min>m[j][k])        
                    {
                        temp_min=m[j][k];
                        loc1=j;                 
                        loc2=k;
                    }
                }
            }
        }
        m[loc1][loc2]=10000000;             
        m[loc2][loc1]=10000000;
        if(loc1>loc2)                      
        {
            cout<<s[loc2]<<' '<<s[loc1]<<' '<<temp_min<<endl;
            for(int i=0;i<n;i++)            
            {
                if(father[i]==father[loc1] &&i!=loc1)
                    father[i]=father[loc2];
            }
            father[loc1]=father[loc2];
        }
        else
        {
            cout<<s[loc1]<<' '<<s[loc2]<<' '<<temp_min<<endl;
            for(int i=0;i<n;i++)            
            {
                if(father[i]==father[loc2] && i!=loc2)
                    father[i]=father[loc1];
            }
            father[loc2]=father[loc1];
        }
    }
    delete []father;
}
void test(int n)
{
    int k;
    string *s=new string[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int **m,**m1;
    m=new int*[n];
    m1=new int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new int[n];
        m1[i]=new int[n];
        for(int j=0;j<n;j++)
        {
            m[i][j]=10000000;
            m1[i][j]=10000000;
        }
    }
    cin>>k;
    string temp1,temp2;
    int flag1,flag2,cost;
    for(int i=0;i<k;i++)
    {
        cin>>temp1>>temp2>>cost;
        for(int p=0;p<n;p++)
        {
            if(s[p]==temp1)
                flag1=p;
            if(s[p]==temp2)
                flag2=p;
        }
        m[flag1][flag2]=cost;
        m[flag2][flag1]=cost;
        m1[flag1][flag2]=cost;
        m1[flag2][flag1]=cost;
    }
    string start_point;
    cin>>start_point;
    prim(m,s,n,start_point);
    kruskal(m1,s,n);
    delete []m;
    delete []m1;
    delete []s;
}
int main()
{
    int t;
    cin>>t;
    test(t);
    return 0;
}*/