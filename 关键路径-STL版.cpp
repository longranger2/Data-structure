#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

class Vertex 
{
public:
    int indexNo;
    bool hasEnterQueue;
    int early;
    int later;

    Vertex(int indexNo) {
        this->indexNo = indexNo;
        this->hasEnterQueue = false;
        early = -1;
        later = 0x7FFFF;
    }
    void updateEarly(int parentEarly, int edgeValue) {
        int newEarly = parentEarly + edgeValue;
        if (newEarly > this->early)
            this->early = newEarly;
    }
    void updateLater(int childLater, int edgeValue) {
        int newLater = childLater - edgeValue;
        if (newLater < this->later)
            this->later = newLater;
    }
};


class Graph {
public:
    vector<Vertex> vertexes;
    vector<vector<int> > adjMat;
    int n;
public:
    void readVertexes() 
    {
        //TODO: 将顶点数读入成员变量n
        cin>>n;
        //TODO： 从输入初始化vertexes数组
        int i=0;
        for(; i<n; ++i) 
        {
            Vertex v(i);
            this->vertexes.push_back(v);
        }
        
        //为成员变量adjMat创建内存，赋初值
        for(i=0; i<n; ++i) {
            vector<int> row;
            int j=0;
            for(; j<n; ++j) 
            {
                //TODO： 将0增加到row最后
                row.push_back(0);
            }
           //TODO： 将row增加到adjMat最后
            adjMat.push_back(row);
        }
    }
    void readAdjMatrix() {
        //read the adjacent info into this->adjMat
        int edges;
        cin >> edges;
        int i=0;
        int s, t, w;  //s源顶点编号，t目的顶点编号，w边长
        for(; i<edges; ++i) 
        {
            //TODO: 读入s,t,w，并将adjMat的第s行、第t列的值改为w.
            cin>>s>>t>>w;
            adjMat[s][t]=w;
        }
    }

    void updateEarly(int parentNo, queue<int>& earlyQue) 
    {
        int parentEarly = vertexes[parentNo].early;  //读入父结点early值

        int j=0;
        for(; j<n; ++j) 
        {
            int edgeValue = adjMat[parentNo][j];
            if (edgeValue == 0) continue;  //若父结点与结点j没有边相连，pass

            Vertex& child = vertexes[j];
            child.updateEarly(parentEarly, edgeValue); //更新子结点j的early信息

            if(!child.hasEnterQueue) {
                child.hasEnterQueue = true; //将子结点加入队列
                earlyQue.push(j);
            }
        }
    }
    void updateLater(int childNo, queue<int>& laterQue) 
    {
        //TODO:
        int parentLater=vertexes[childNo].later;
        int j=0;
        for(;j<n;j++)
        {
            int edgeValue=adjMat[j][childNo];
            if(edgeValue==0)
                continue;
            Vertex& parent = vertexes[j];
            parent.updateLater(parentLater,edgeValue); //更新子结点j的Later信息

            if(!parent.hasEnterQueue) 
            {
                parent.hasEnterQueue = true; //将父结点加入队列
                laterQue.push(j);
            }
        }
    }

    int getRoot() 
    {
        //获取入度为0的顶点
        int j=0;
        for(; j<n; ++j) {
            int i=0;
            for(; i<n && adjMat[i][j] == 0; ++i);
            if (i>=n) return j; //j has not any in-edges.
        }
        return -1;  //表示没找到
    }
    int getLeaf() 
    {
        //TODO： 获取出度为0的顶点
        /*int i=0;
        for(;i<n;i++)
        {
            int j=0;
            for(;j<n &&adjMat[i][j]==0;++j);
            if(j>=n)    
            return i;//i has not any out-edges.
        }
        return -1;
        */
        int j = 0;
        for(; j < n; ++j)
        {
            int i = 0;
            for(; i < n && adjMat[j][i] == 0; ++i);
            if(i >= n)
                return j;
        }
        return -1;
    }

    void printEarlyLater(bool isEarly) {
        int i=0;
        for(; i<n; ++i) {
            Vertex& v = vertexes[i];
            if (isEarly)
                cout << v.early << " ";
            else {
                cout << v.later << " ";
            }
        }
        cout << endl;
    }

    void findEarly() {
        //执行关键路径算法，求每个顶点的最早开始时间。
        int r = getRoot();
        Vertex& root = vertexes[r];
        root.hasEnterQueue = true;
        root.early = 0;

        queue<int> que;
        que.push(r);

        while(!que.empty()) {
            int p = que.front();
            que.pop();

            updateEarly(p, que);
        }

        printEarlyLater(true);
    }
    void clearEnterQueue() {
        int i=0;
        for(; i<n; ++i) {
            vertexes[i].hasEnterQueue = false;
        }
    }
    void findLater() 
    {
        //TODO：调用clearEnterQueue，以清除每个顶点的hasEnterQueue=false
        clearEnterQueue();
        //执行关键路径算法，求每个顶点的最迟开始时间。
       
        int r = getLeaf();
        Vertex &parent = vertexes[r];
        parent.hasEnterQueue = true;
        parent.later = parent.early;
 
        queue<int> que;
        que.push(r);
 
        while(!que.empty())
        {
            int p = que.front();
            que.pop();
 
            updateLater(p,que);
        }
        printEarlyLater(false);
    }

    void main() {
        readVertexes();
        readAdjMatrix();
        findEarly();
        findLater();
    }
};


int main() {
    int t=1;
    //cin >> t;
    while (t--) {
        Graph g;
        g.main();
    }
    return 0;
}
/*

#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
class Vertex{
public:
    int indexNo;
    bool hasEnterQueue;
    int early;
    int later;
 
    Vertex(int indexNo)
    {
        this->indexNo = indexNo;
        hasEnterQueue = false;
        early = -1;
        later = 0x7ffff;
    }
    void updateEarly(int parentEarly,int edgeValue)
    {
        int newEarly = parentEarly + edgeValue;
        if(newEarly > this->early)
            this->early = newEarly;
    }
    void updateLater(int childLater,int edgeValue)
    {
        int newLater = childLater - edgeValue;
        if(newLater < this->later)
            this->later = newLater;
    }
};
class Graph{
public:
    vector<Vertex> vertexes;
    vector<vector<int> > adjMat;
    int n;
 
    void readVertexes()
    {
        cin>>n;                   //将顶点数读入成员变量n
        int i = 0;
        for(; i < n; ++i)        //初始化vertexes数组
        {
            Vertex v(i);
            vertexes.push_back(v);
        }
        for(i = 0; i < n; i++)    //初始化adjMat数组
        {
            vector<int> row;
            int j = 0;
            for(; j < n; ++j)
            {
                row.push_back(0);
            }
            adjMat.push_back(row);
        }
    }
    void readAdjMatrix()
    {
        int edges;
        cin>>edges;
        int i = 0;
        int s,t,w;
        for(; i < edges; ++i)     //读入s,t,w，并将adjMat的第s行、第t列的值改为w.
        {
            cin>>s>>t>>w;
            adjMat[s][t] = w;
        }
    }
    void updateEarly(int parentNo,queue<int> &earlyQue)    //更新最早开始时间
    {
        int parentEarly = vertexes[parentNo].early;        //读入父结点early值
        int j = 0;
        for(; j < n; ++j)
        {
            int edgeValue = adjMat[parentNo][j];
            if(edgeValue == 0)                         //若父结点与结点j没有边相连，pass
                continue;
            Vertex &child = vertexes[j];
            child.updateEarly(parentEarly,edgeValue);    //更新子结点j的early信息
            if(!child.hasEnterQueue)
            {
                child.hasEnterQueue = true;
                earlyQue.push(j);                     //将子结点加入队列
            }
        }
    }
    void updateLater(int childNo,queue<int> &laterQue)    //更新最晚开始时间
    {
        int parentLater = vertexes[childNo].later;        //同理
        int j = 0;
        for(; j < n; ++j)
        {
            int edgeValue = adjMat[j][childNo];
            if(edgeValue == 0)
                continue;
            Vertex &parent = vertexes[j];
            parent.updateLater(parentLater,edgeValue);
            if(!parent.hasEnterQueue)
            {
                parent.hasEnterQueue = true;
                laterQue.push(j);
            }
        }
    }    
    int getRoot()                            //获取入度为0的顶点
    {
        int j = 0;
        for(; j < n; ++j)
        {
            int i=0;
            for(; i < n && adjMat[i][j] == 0; ++i);
            if(i >= n)
                return j;
        }
        return -1;
    }
    int getLeaf()                         //获取出度为0的顶点
    {
        int j = 0;
        for(; j < n; ++j)
        {
            int i = 0;
            for(; i < n && adjMat[j][i] == 0; ++i);
            if(i >= n)
                return j;
        }
        return -1;
    }
    void printEarlyLater(bool isEarly)    //输出，参数是1表示输出最早，参数是0表示输出最晚
    {
        int i = 0;
        for(; i < n; ++i)
        {
            Vertex &v = vertexes[i];
            if(isEarly)
                cout<<v.early<<' ';
            else
                cout<<v.later<<' ';
        }
        cout<<endl;
    }
    void findEarly()                //执行关键路径算法，求每个顶点的最早开始时间。
    {
        int r = getRoot();
        Vertex &root = vertexes[r];
        root.hasEnterQueue = true;
        root.early = 0;
 
        queue<int> que;
        que.push(r);
 
        while(!que.empty())
        {
            int p = que.front();
            que.pop();
 
            updateEarly(p,que);
        }
        printEarlyLater(true);
    }
    void clearEnterQueue()        //重置各顶点标志的信息
    {
        for(int i = 0; i < n; ++i)
            vertexes[i].hasEnterQueue = false;
    }
    void findLater()                //执行关键路径算法，求每个顶点的最玩开始时间。
    {
        clearEnterQueue();
        int r = getLeaf();
        Vertex &parent = vertexes[r];
        parent.hasEnterQueue = true;
        parent.later = parent.early;
 
        queue<int> que;
        que.push(r);
 
        while(!que.empty())
        {
            int p = que.front();
            que.pop();
 
            updateLater(p,que);
        }
        printEarlyLater(false);
    }
    void start()                //开始函数：依次执行初始化、求最早、求最晚
    {
        readVertexes();
        readAdjMatrix();
        findEarly();
        findLater();
    }
};
int main()
{
    int t=1;
    while(t--)
    {
        Graph g;
        g.start();
    }
    return 0;
}*/