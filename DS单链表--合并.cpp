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
void Merge(Node *La, Node *Lb)
{
	Node *pa,*pb,*pc;
	pa=La->next;
	pb=Lb->next;
	pc=La;
	//cout<<pa->data<<" "<<pb->data<<endl;
	while(pa!=NULL&&pb!=NULL)
	{
		//cout<<pc->data<<endl;
		if(pa->data<=pb->data)
		{
			pc->next=pa;
			pc=pc->next;
			pa=pa->next;
		}
		else
		{
			pc->next=pb;
			pc=pc->next;
			pb=pb->next;
		}
		//cout<<"1"<<endl;
	}
	if(pa!=NULL)
	{
		pc->next=pa;
	}
	else if(pb!=NULL)
	{
		pc->next=pb;
	}
	Node *p=La->next;
    while(p)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
int main()
{
    int n;
    Linklist list1,list2;
    cin>>n;
    list1.Create(n);
    cin>>n;
    list2.Create(n);
    Merge(list1.root,list2.root);
    return 0;
}