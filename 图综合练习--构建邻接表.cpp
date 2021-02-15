#include <iostream>
using namespace std;

class Node
{
    
public:
    int pos;
    Node *next;
    Node():next(NULL){}
    Node(int position):pos(position),next(NULL){}
    friend class AdjList;
};

class List{
    int vexNum;
    int arcNum;
    char *vex;
    Node *heads;
    int Index(char c);
public:
    List();
    ~List();
    void outPut();
};

List::List() {
    cin>>vexNum>>arcNum;
    vex = new char[vexNum];
    for(int i=0;i<vexNum;i++)
        cin>>vex[i];

    heads = new Node[vexNum];

    for(int i=0;i<arcNum;i++)
    {
        char c1,c2;
        cin>>c1>>c2;
        int num1=Index(c1),num2=Index(c2);
        Node *p = &heads[num1];

        while (p->next)
            p=p->next;

        Node *s = new Node;
        s->pos=num2;
        p->next = s;
    }
}

List::~List() {
    delete []vex;
    for(int i=0;i<vexNum;i++) {
        Node *p = heads[i].next;
        while (p)
        {
            Node *q = p;
            p = p->next;
            delete q;
        }
    }
    delete []heads;
}

int List::Index(char c) {
    for(int i=0;i<vexNum;i++)
        if(c==vex[i])
            return i;
    return -1;
}

void List::outPut() {
    for(int i=0;i<vexNum;i++)
    {
        cout<<i<<' '<<vex[i];
        Node *p = heads[i].next;

        while (p)
        {
            cout<<'-'<<p->pos;
            p=p->next;
        }
        cout<<"-^"<<endl;
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        List list;
        list.outPut();
    }

    return 0;
}
