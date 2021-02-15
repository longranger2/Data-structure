/*#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class ListNode
{
    int vertex;
    double weight;
    ListNode *next;
public:
    ListNode(){next = NULL;}
    friend class Graph;
};

class Graph
{
private:
    int vexnum;
    int edgenum;
    ListNode **adjlist;
    double **matrix;
    int *S;
    int *s;
    double *dist;
    int *path;//由于还是以最长求最长，所以这里还是可以只用一个path数组记录到每个点的路径。
    int IsOver();
    void DisplayPath(int i);
    void TopologicalSort();
public:
    Graph();
    ~Graph();
    void Dijkstra();
};

Graph::Graph()
{
    int i, j;
    cin>>vexnum>>edgenum;
    adjlist = new ListNode*[vexnum];
    s = new int[vexnum];
    S = new int[vexnum];
    dist = new double[vexnum];
    path = new int[vexnum];
    matrix = new double*[vexnum];
    for(i=0; i<vexnum; i++)
    {
        s[i] = 0;
        dist[i] = 0;
        path[i] = -1;
        adjlist[i] = new ListNode;
        matrix[i] = new double[vexnum];
        for(j=0; j<vexnum; j++)
            matrix[i][j] = 0;
    }
    for(i=0; i<edgenum; i++)
    {
        ListNode *p;
        int startvex, endvex;
        double weight;
        cin>>startvex>>endvex>>weight;
        p = new ListNode;
        p->weight = weight;
        p->vertex = endvex;
        p->next = adjlist[startvex]->next;
        adjlist[startvex]->next = p;
        matrix[startvex][endvex] = weight;
    }
}

Graph::~Graph()
{
    delete []adjlist;
    delete []s;
    delete []dist;
    delete []path;
    for(int i=0; i<vexnum; i++)
        delete []matrix[i];
    delete []matrix;
}

int Graph::IsOver()
{
    for(int i=0; i<vexnum; i++)
    {
        if(!s[i])
            return 0;
    }
    return 1;
}

void Graph::DisplayPath(int i)
{//在不断根据path逆向求路径时需要用一个栈来跟着保存，每次调用只输出到一个点i的路径。
    stack<int> s;
    s.push(i);
    while(path[i]!=-1)
    {
        i = path[i];
        s.push(i);
    }
    while(!s.empty())
    {
        i = s.top();
        s.pop();
        cout<<i<<' ';
    }
    cout<<endl;
}

void Graph::TopologicalSort()
{
    int num = 0;
    while(!IsOver())
    {
        int i, j;
        for(i=0; i<vexnum; i++)
        {
            if(!s[i])
            {
                for(j=0; j<vexnum; j++)
                {
                    if(matrix[j][i])
                        break;
                }
                if(j==vexnum)
                    break;
            }
        }
        s[i] = 1;
        S[num] = i;
        num++;
        for(j=0; j<vexnum; j++)
            matrix[i][j] = 0;
    }
}

void Graph::Dijkstra()
{
    TopologicalSort();
    int i;
    ListNode *q;
    for(i=0; i<vexnum; i++)
    {
        int temp = S[i];
        q = adjlist[temp];
        while(q->next)
        {
            q = q->next;
            if(dist[q->vertex]<dist[temp]+q->weight)
            {
                dist[q->vertex] = dist[temp]+q->weight;
                path[q->vertex] = temp;
            }
        }
    }
    for(i=0; i<vexnum; i++)
    {
        if(i!=S[0])
            DisplayPath(i);
    }
}

int main()
{
    Graph myGraph;
    myGraph.Dijkstra();
}

*/
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class ListNode
{
    int vertex;
    double weight;
    ListNode *next;
public:
    ListNode(){next = NULL;}
    friend class Graph;
};

class Graph
{
private:
    int vexnum;
    int edgenum;
    ListNode **adjlist;
    double **matrix;
    int *S;
    int *s;
    double *dist;
    int *path;
    int IsOver()
    {
        for(int i=0; i<vexnum; i++)
    {
        if(!s[i])
            return 0;
    }
    return 1;
    }
    void DisplayPath(int i)
    {
         stack<int> s;
    s.push(i);
    while(path[i]!=-1)
    {
        i = path[i];
        s.push(i);
    }
    while(!s.empty())
    {
        i = s.top();
        s.pop();
        cout<<i<<' ';
    }
    cout<<endl;
    }
    void DisplayPath1(int i)
    {
         stack<int> s;
    s.push(i);
    while(path[i]!=-1)
    {
        i = path[i];
        s.push(i);
    }
    while(!s.empty())
    {
        i = s.top();
        s.pop();
        if(s.empty())
            cout<<i;
        else
            cout<<i<<" ";
    }
    cout<<endl;
    }
    void Sort()
    {
        int num = 0;
    while(!IsOver())
    {
        int i, j;
        for(i=0; i<vexnum; i++)
        {
            if(!s[i])
            {
                for(j=0; j<vexnum; j++)
                {
                    if(matrix[j][i])
                        break;
                }
                if(j==vexnum)
                    break;
            }
        }
        s[i] = 1;
        S[num] = i;
        num++;
        for(j=0; j<vexnum; j++)
            matrix[i][j] = 0;
    }}
public:
    Graph()
    {
        int i, j;
    cin>>vexnum>>edgenum;
    adjlist = new ListNode*[vexnum];
    s = new int[vexnum];
    S = new int[vexnum];
    dist = new double[vexnum];
    path = new int[vexnum];
    matrix = new double*[vexnum];
    for(i=0; i<vexnum; i++)
    {
        s[i] = 0;
        dist[i] = 0;
        path[i] = -1;
        adjlist[i] = new ListNode;
        matrix[i] = new double[vexnum];
        for(j=0; j<vexnum; j++)
            matrix[i][j] = 0;
    }
    for(i=0; i<edgenum; i++)
    {
        ListNode *p;
        int startvex, endvex;
        double weight;
        cin>>startvex>>endvex>>weight;
        p = new ListNode;
        p->weight = weight;
        p->vertex = endvex;
        p->next = adjlist[startvex]->next;
        adjlist[startvex]->next = p;
        matrix[startvex][endvex] = weight;
    }
    }
    ~Graph()
    {
        delete []adjlist;
    delete []s;
    delete []dist;
    delete []path;
    for(int i=0; i<vexnum; i++)
        delete []matrix[i];
    delete []matrix;
    }
    void Dijkstra()
    {
    Sort();
    int i;
    ListNode *q;
    for(i=0; i<vexnum; i++)
    {
        int temp = S[i];
        q = adjlist[temp];
        while(q->next)
        {
            q = q->next;
            if(dist[q->vertex]<dist[temp]+q->weight)
            {
                dist[q->vertex] = dist[temp]+q->weight;
                path[q->vertex] = temp;
            }
        }
    }
    DisplayPath(0);
    for(i=1; i<vexnum; i++)
    {
        if(i!=S[0])
            DisplayPath(i);
    }}
};


int main()
{
    Graph myGraph;
    myGraph.Dijkstra();
}