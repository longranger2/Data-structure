#include<iostream>
using namespace std;
class Node
{
    public:
        int data;
        Node *next;
        Node()
        {
            data=0;
            next=NULL;
        }
        Node(int d)
        {
            data=d;
            next=NULL;
        }
        friend class Linklist;
};
class Linklist
{
    public:
        Node *root;
        int len;
        Linklist()
        {
            root=new Node;
            len=0;
        }
        void Create(int n)
        {
            //cout<<"hi"<<endl;
            len=n;
            Node *tail=root;
            for(int i=0;i<n;i++)
            {
                int num;
                cin>>num;
                Node *q=new Node(num);
                tail->next=q;
                tail=q;
                //cout<<"hi"<<endl;
            }
            //cout<<"hi"<<endl;
        }
        void Display()
        {
            Node *p=root->next;
            while(p)
            {
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<endl;
        }
        void Swap()
        {
            int pa,pb;
            cin>>pa>>pb;
            if(pa<=0||pb<=0||pa>len||pb>len)
                cout<<"error"<<endl;
            else
            {
                Node *p=Index(pa-1),*q=Index(pb-1);
                if(p->next==q)
                {
                    p->next=q->next;
                    q->next=q->next->next;
                    p->next->next=q;
                }
                Node *t=p->next;//交换前驱
                p->next=q->next;
                q->next=t;

                t=p->next->next;
                p->next->next=q->next->next;
                q->next->next=t;
                Display();
            }
        }
        Node *Index(int i)
        {
            if(i<0||i>len)
                return NULL;
            Node *p=root;
            for(int j=0;j<i;j++)
                p=p->next;
            return p;
        }
        ~Linklist()
        {
            Node *t=root;
            Node *s;
            while(t)
            {
                s=t;
                t=t->next;
                delete s;
            }
            len=0;
            root=NULL;
        }

};
int main()
{
    int n;
    cin>>n;
    Linklist ll;
    ll.Create(n);
    ll.Display();
    ll.Swap();
    ll.Swap();
    return 0;
}