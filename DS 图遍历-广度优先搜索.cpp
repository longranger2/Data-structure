/*#include<iostream>
#include<queue>
using namespace std;
const int maxlen = 20;
class MAP{
    private:
        int maxtrix[maxlen][maxlen];
        int vexnum;
        int *visit;
        void map(int start){//广度优先遍历
            queue<int > que;
            que.push(start);
            
            while(!que.empty())
            {
                int st= que.front();
                que.pop();
                visit[st]= 1;
                cout<<st<<' ';
                
                for(int i= 0;i< vexnum; i++){
                    if(maxtrix[st][i]&&!visit[i]){
                        visit[i]= 1;//这里得改变i已被遍历，否则将会重复遍历
                        que.push(i);
                    }
                }
            }
        }
    public :
        void setMx(int mx[maxlen][maxlen], int vnum){
            vexnum= vnum;
            visit= new int[vnum+ 5];
            
            for(int i= 0; i< vexnum ;i++)
             visit[i]= 0;
            for(int i= 0; i< vexnum; i++){
                for(int j= 0; j< vexnum; j++)
                  maxtrix[i][j]= mx[i][j];
            }
        }
        void map(){
            map(0);
            cout<<endl;
        }
};
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mx[maxlen][maxlen];
        for(int i= 0; i< n; i++)
          for(int j= 0; j< n; j++)
            cin>>mx[i][j];
        
        MAP test;
        test.setMx(mx, n);
        test.map();
    }
    return 0;
}
*/
#include<iostream>
#include<queue>
using namespace std;
const int MaxLen = 20;
class Map 
{
    private:
        bool Visit[MaxLen];
        int Matrix[MaxLen][MaxLen];
        int Vexnum;
        void BFS(int v);
    public:
        void SetMatrix(int vnum,int mx[MaxLen][MaxLen]);
        void BFSTraverse();
};
void Map::SetMatrix(int vnum,int mx[MaxLen][MaxLen])
{
    int i,j;
    Vexnum=vnum;   //设置图的结点数量
    for(i=0;i<MaxLen;i++) //领接矩阵初始化为0
    {
        for(j=0;j<MaxLen;j++)
            Matrix[i][j]=0;
    }
    for(i=0;i<Vexnum;i++)//领接矩阵初始化
        for(j=0;j<Vexnum;j++)
            Matrix[i][j]=mx[i][j];
}

/*void Map::BFS (int v)//v是当前顶点
{
    int w,u;   //变量用于存放顶点编号
    int i,k;
    int *AdjVex=new int[Vexnum];
    queue<int> Q;
    for(i=0;i<Vexnum;i++)
        Visit[i]=false;

    for(v=0;v<Vexnum;++v)
    {
        if(!Visit[v])
        {
            Visit[v]=true;
            cout<<v<<' ';
            Q.push(v);
            while(!Q.empty())
            {
                u=Q.front();
                Q.pop();
                k=0;
                for(i=0;i<Vexnum;i++)
                {
                    if(Matrix[v][i]&&!Visit[i])
                    {
                        Visit[i]=1;
                        Q.push(i);
                    }
                }
            }
        }
    }
    cout<<endl;
    delete []AdjVex;
}*/
void Map::BFS(int v)
{
    int w,u;
    int i,k;
    int *AdjVex=new int[Vexnum];
    queue<int>Q;
    for(int i=0;i<Vexnum;i++)
        Visit[i]=false;
    for(v=0;v<Vexnum;++v)
    {
        if(!Visit[v])
        {
            Visit[v]=true;
            cout<<v<<" ";
            Q.push(v);
            while(!Q.empty())
            {
                u=Q.front();
                Q.pop();
                for(i=0;i<Vexnum;i++)
                {
                    if(Matrix[v][i]&&!Visit[i])
                    {
                        Visit[i]=1;
                        Q.push(i);
                    }
                }

            }
        }
    }
    cout<<endl;
    delete []AdjVex;
}
void Map::BFSTraverse()
{
    BFS(0);
}
int main()
{
    int t,n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        int mx[MaxLen][MaxLen];
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mx[i][j];
        Map map;
        map.SetMatrix(n,mx);
        map.BFSTraverse();

    }
    return 0;
}