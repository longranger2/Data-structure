/*#include <iostream>
using namespace std;
#include <queue>
#include <string>
const int MaxLen =20;
const int MaxDist=9999;

void Sort(int *shuzu,int n)
{
    int num;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(shuzu[j]>shuzu[j+1])
            {
                num=shuzu[j];
                shuzu[j]=shuzu[j+1];
                shuzu[j+1]=num;
            }
        }
    }
}

class Map{
private:
    int Matrix[MaxLen][MaxLen];  //图的邻接矩阵 
    int Vexnum;
public:
    void SetMatrix(int vnum,int mx[MaxLen][MaxLen]);
    void ShortestPath_DIJ(int v0,int r,string *data);//求Vo到其他定点的最短路径 
};
//设置邻接矩阵 
void Map::SetMatrix(int vnum,int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;
    for(i=0;i<MaxLen;i++)
        for(j=0;j<MaxLen;j++)
            Matrix[i][j]=MaxDist;
    for(i=0;i<Vexnum;i++)
        for(j=0;j<Vexnum;j++)
            if(mx[i][j])
                Matrix[i][j]=mx[i][j];
}
void Map::ShortestPath_DIJ(int v0,int r,string *data)
{
    int i,j,v,w,mmin;
    int *dist = new int[Vexnum];    //dist数组存顶点v0到其它顶点的最短距离
    bool *final = new bool[Vexnum];  //final数组用于标志dist数组的距离是否已经是最短距离
    int path[Vexnum][Vexnum];        //path二维数组每行存的是顶点v0到第i个顶点的最短路径（从哪到哪） 
    int len[Vexnum];                //len数组存的是path最短路径的长度（有几个顶点） 
    for(int i = 0; i < Vexnum; i++)        //final和dist初始化
    {
        final[i]=false;
        dist[i]=Matrix[v0][i];
    }
    for(int i=0;i<Vexnum;i++)        //path初始化
    {
        path[i][0]=v0;
        path[i][1]=i;
    }
    for(int i = 0;i<Vexnum;i++)       //len初始化
    {
        len[i]=2;
    }
    dist[v0]=0;                    //dist[v0]初始化为0，表示顶点到本身的距离
    final[v0]=true;                //顶点到本身的距离已经是最小，所以final置为true
    for(int i=0;i<Vexnum;i++)
    {
        mmin=MaxDist;
        for(int j=0;j<Vexnum;j++)   //每次取不是最短距离（即final!=true）的最小距离的那个顶点
        {
            if(!final[j] && mmin > dist[j])
            {
                mmin=dist[j];
                v=j;
            }
        }
        if(mmin==MaxDist)        //如果没取到，证明已经完成了，可以结束了
            break;
        else
        {
            final[v]=true;        //取到的话，要把对应顶点标志为已经最短距离
            for(int j=0;j<Vexnum;j++)       //再依据对应顶点的最短距离更新到其它顶点的最短距离，并更新路径path
            {
                if(!final[j] && Matrix[v][j]+mmin<dist[j])
                {
                    dist[j]=Matrix[v][j]+mmin;
                    for(int p=0;p<len[v];p++)
                    {
                        path[j][p]=path[v][p];
                    }
                    len[j]=len[v]+1;
                    path[j][len[j]-1]=j;
                }
            }
        }
    }
    
    int *shuzu=new int[Vexnum];
    int flag;
    for(int i=0;i<Vexnum;i++)
    {
        shuzu[i]=dist[i];
    }
    Sort(shuzu,Vexnum);
    for(int i=0;i<Vexnum;i++)
        cout<<shuzu[i]<<" ";
    cout<<endl;
    flag=shuzu[r];
    for(int i=0;i<Vexnum;i++)
    {
        if(dist[i]==flag)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    delete []shuzu;
    delete []dist;
    delete []final;
}

int main()
{
    int i,j,k,t,r;
    int vnum,first;
	string v0;
    int mx[MaxLen][MaxLen];
    Map test;
    cin>>t;
    while(t--)
    {
    	
        cin>>vnum;
        string *data=new string[vnum];
		for(i=0;i<vnum;i++)
			cin>>data[i];
        for(i=0;i<MaxLen;i++)
            for(j=0;j<MaxLen;j++)
                mx[i][j]=0;
        for(i=0;i<vnum;i++)        //以邻接矩阵方式读入图的信息
            for(j=0;j<vnum;j++)
                cin>>mx[i][j];
        cin>>v0>>r;                   //读入开始顶点
        for(i=0;i<vnum;i++)
        {
        	if(data[i]==v0)
        		first=i;
		}
        test.SetMatrix(vnum,mx);
        test.ShortestPath_DIJ(first,r,data);
        delete []data;
    }
    return 0;
}
*/


#include <iostream>
using namespace std;
#include <queue>
#include <string>
const int MaxLen =20;
const int MaxDist=9999;
void Sort(int *shuzu,int n)
{
    int num;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(shuzu[j]>shuzu[j+1])
            {
                num=shuzu[j];
                shuzu[j]=shuzu[j+1];
                shuzu[j+1]=num;
            }
        }
    }
}
class Map{
private:
    int Matrix[MaxLen][MaxLen];  //图的邻接矩阵 
    int Vexnum;
public:
    void SetMatrix(int vnum,int mx[MaxLen][MaxLen]);
    void ShortestPath_DIJ(int v0,int r);//求Vo到其他定点的最短路径 
};
//设置邻接矩阵 
void Map::SetMatrix(int vnum,int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum = vnum;
    for(i=0;i<MaxLen;i++)//将Matrix初始化为∞
        for(j=0;j<MaxLen;j++)
            Matrix[i][j]=MaxDist;
    for(i=0;i<Vexnum;i++)
        for(j=0;j<Vexnum;j++)
            if(mx[i][j])//若mx[i][j]为0，则代表两点之间没有路径
                Matrix[i][j]=mx[i][j];
}
void Map::ShortestPath_DIJ(int v0,int r)
{
    int i,j,v,w,mmin;
    int *dist = new int[Vexnum];    //dist数组存顶点v0到其它顶点的最短距离
    bool *final = new bool[Vexnum];  //final数组用于标志dist数组的距离是否已经是最短距离
    int len[Vexnum];                //len数组存的是path最短路径的长度（有几个顶点） 
    for(int i = 0; i < Vexnum; i++)        //final和dist初始化
    {
        final[i]=false;
        dist[i]=Matrix[v0][i];
    }
    for(int i = 0;i<Vexnum;i++)       //len初始化
    {
        len[i]=2;
    }
    dist[v0]=0;                    //dist[v0]初始化为0，表示顶点到本身的距离
    final[v0]=true;                //顶点到本身的距离已经是最小，所以final置为true
    for(int i=0;i<Vexnum;i++)
    {
        mmin=MaxDist;
        for(int j=0;j<Vexnum;j++)   //每次取不是最短距离（即final!=true）的最小距离的那个顶点
        {
            if(!final[j] && mmin > dist[j])
            {
                mmin=dist[j];
                v=j;
            }
        }
        if(mmin==MaxDist)        //如果没取到，证明已经完成了，可以结束了
            break;
        else
        {
            final[v]=true;        //取到的话，要把对应顶点标志为已经最短距离
            for(int j=0;j<Vexnum;j++)       //再依据对应顶点的最短距离更新到其它顶点的最短距离，并更新路径path
            {
                if(!final[j] && Matrix[v][j]+mmin<dist[j])
                {
                    dist[j]=Matrix[v][j]+mmin;
                    len[j]=len[v]+1;
                }
            }
        }
    }
    
    int *shuzu=new int[Vexnum];
    int flag;
    for(int i=0;i<Vexnum;i++)
    {
        shuzu[i]=dist[i];
    }
    Sort(shuzu,Vexnum);
    flag=shuzu[r];
    for(int i=0;i<Vexnum;i++)
    {
        if(dist[i]==flag)
        {
            cout<<i<<" ";
        }
    }
    cout<<endl;
    delete []shuzu;
    delete []dist;
    delete []final;
}
int main()
{
    int i,j,k,t,r;
    int vnum,first;
    int mx[MaxLen][MaxLen];
    Map test;
    cin>>t;
    //while(t--)
    //{
        
        cin>>vnum;
        for(i=0;i<MaxLen;i++)
            for(j=0;j<MaxLen;j++)
                mx[i][j]=0;
        for(i=0;i<vnum;i++)        //以邻接矩阵方式读入图的信息
            for(j=0;j<vnum;j++)
                cin>>mx[i][j];
        cin>>first>>r;                   //读入开始顶点
        test.SetMatrix(vnum,mx);
        test.ShortestPath_DIJ(first,r);
   // }
    return 0;
}