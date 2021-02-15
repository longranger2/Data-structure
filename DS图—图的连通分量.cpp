#include <iostream>
#include <string>
#include <queue>
using namespace std;
const int MaxLen =20;
class Map
{
private:
    bool Visit[MaxLen]; //辅助数组，判断顶点是否访问过
    int Matrix[MaxLen][MaxLen];
    int Vexnum; //顶点个数
    void BFS(int v);   //广度优先搜索
public:
    void SetMatrix(int vnum,int **mx); //初始化
    void BFSTraverse();
    int get();
};
void Map::BFSTraverse()
{
    cout<<0<<' ';
    Visit[0]=true;
    BFS(0);
    cout<<endl;
}
void Map::BFS(int v) //广度优先搜索算法
{
    //法一
    /*Visit[v]=true;
    queue<int> Q;
    for(int i=0;i<Vexnum;i++)
    {
        if(Matrix[v][i]!=0 &&!Visit[i])
        {
            Q.push(i);
        }
    }
    while(!Q.empty())
    {
        BFS(Q.front());//每一个顶点出对时，相对应的下面一层的顶点就要进队
        Q.pop();
    }*/
    //法2 更好理解些
    queue<int > que;
    que.push(v);
    while(!que.empty())
    {
        int st= que.front();
        que.pop();
        Visit[st]= 1;
        //cout<<st<<' ';
        for(int i= 0;i< Vexnum; i++)
        {
            if(Matrix[st][i]&&!Visit[i])
            {
                Visit[i]= 1;//这里得改变i已被遍历，否则将会重复遍历
                que.push(i);
            }
        }
    }
}
void Map::SetMatrix(int vnum,int **mx)//图的初始化
{
    for(int i=0;i<Vexnum;i++)
        Visit[i]=false;
    int i,j;
    Vexnum =vnum;
    for(i=0;i<MaxLen;i++)
        for(j=0;j<MaxLen;j++)
            Matrix[i][j]=0;
    for(i=0;i<Vexnum;i++)
        for(j=0;j<Vexnum;j++)
            Matrix[i][j]=mx[i][j];
}
int Map::get() //用BFS遍历相连通的顶点，成功一次sum++，其中visit是用来记录顶点是否被遍历过的
{
    int sum=0;
    for(int i=0;i<Vexnum;i++)
    {
        if(!Visit[i])
        {
            BFS(i);
            sum++;
        }
    }
    return sum;
}
void test()
{
    int n,k;
    cin>>n;
    string *s=new string[n];
    for(int i=0;i<n;i++)
        cin>>s[i];
    int **m;
    m=new int*[n];
    for(int i=0;i<n;i++)
    {
        m[i]=new int[n];
        for(int j=0;j<n;j++)
            m[i][j]=0;
    }
    cin>>k;
    string temp1,temp2;
    int flag1,flag2;
    for(int i=0;i<k;i++)
    {
        cin>>temp1>>temp2;
        for(int p=0;p<n;p++)
        {
            if(s[p]==temp1)
                flag1=p;
            if(s[p]==temp2)
                flag2=p;
        }
        m[flag1][flag2]=1;
        m[flag2][flag1]=1;
    }
    for(int i=0;i<n;i++)
    {
        if(i==n-1)
            cout<<s[i];
        else
            cout<<s[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(j==n-1)
                cout<<m[i][j];
            else
            cout<<m[i][j]<<' ';
        }
        cout<<endl;
    }
    Map t;
    t.SetMatrix(n,m);
    cout<<t.get()<<endl<<endl;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        test();
    }
}