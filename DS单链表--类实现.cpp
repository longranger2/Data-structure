/*#include<iostream>
using namespace std;
#define ok 0
#define error -1
class ListNode
{
public:
	int data;
	ListNode *next;
	ListNode()
	{
		next=NULL;
	}
};
class Linklist
{
public:
	ListNode *head;
	int len;
	Linklist();
	~Linklist();
	ListNode *LL_index(int i);
	void LL_get(int i);
	int LL_insert(int i,int item);
	int LL_del(int i);
	void LL_display();
};
ListNode * Linklist::LL_index(int i)
{
	ListNode *p=head;
	for(int j=1;j<=i;j++)
	{
		p=p->next;
	}
	if(p)
	{
		return p;
	}
	else
		return NULL;
}
void Linklist::LL_get(int i)
{

	ListNode *p=head;
	for(int j=1;j<=i;j++)
	{
		p=p->next;
	}
	if(p&&i>0)
	{
		cout<<p->data<<endl;
	}
	else
		cout<<"error"<<endl;
}

int Linklist::LL_insert(int i,int item)
{
	ListNode *p=head;
	int j;
	for(j=1;j<i;j++)
	{
		p=p->next;
	}
	if(p)
	{
		len++;
		ListNode *temp=new ListNode;
		temp->data=item;
		temp->next=p->next;
		p->next=temp;
		return ok;
	}
	else
		return error;

}
Linklist::Linklist()
{
	head=new ListNode;
	len=0;
}
int Linklist::LL_del(int i)
{
	if(i<=0||i>len)
		return error;
	ListNode *p=head;
	for(int j=1;j<i;j++)
	{
		p=p->next;
	}
	ListNode *q;
	q=p->next;
	p->next=q->next;
	delete q;
	len--;
	return ok;
	
	
}
Linklist::~Linklist()
{
	ListNode *p,*q;
	p=head;
	while(p!=NULL)
	{
		q=p;
		p=p->next;
		delete q;
	}
	len=0;
	head=NULL;
}
void Linklist::LL_display()
{
	ListNode *p;
	p=head->next;
	while(p)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}
int main()
{
	int n,num,pos;
	cin>>n;
	Linklist list;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		list.LL_insert(i,num);
	}
	list.LL_display();


	cin>>pos>>num;
	if(list.LL_insert(pos,num)==ok)
		list.LL_display();
	else
		cout<<"error"<<endl;
	cin>>pos>>num;
	if(list.LL_insert(pos,num)==ok)
		list.LL_display();
	else
		cout<<"error"<<endl;


	cin>>pos;
	if(list.LL_del(pos)==ok)
		list.LL_display();
	else
		cout<<"error"<<endl;
	cin>>pos;
	if(list.LL_del(pos)==ok)
		list.LL_display();
	else
		cout<<"error"<<endl;

	cin>>pos;
	list.LL_get(pos);
	cin>>pos;
	list.LL_get(pos);

	return 0;
}
*/
#include <iostream>
using namespace std;
#define ok 0
#define error -1

class ListNode{
    public:
        int data;
        ListNode *next;
        ListNode()
        {
            next=NULL;
        }
};
class LinkList{
    public:
        ListNode *head;
        int len;
        LinkList();
        ~LinkList();
        ListNode *LL_index(int i);
        int LL_get(int i);
        int LL_insert(int i,int item);
        int LL_del(int i);
        void LL_display();
};
LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}
LinkList::~LinkList()
{
    ListNode *p,*q;
    p=head;
    while(p!=NULL){
        q=p;
        p=p->next;
        delete q;
    }
    len=0;
    head=NULL;
}
void LinkList::LL_display()
{
    ListNode *p;
    p=head->next;
    while(p)
    {
        cout<<p->data<<' ';
        p=p->next;
    }
    cout<<endl;
}
ListNode *LinkList::LL_index(int i)
{
    int j=0;
    ListNode *p=head;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p) return NULL;
    else return p;
}
int LinkList::LL_get(int i)
{
    if(i<=0||i>len) return error;
    int j=0;
    ListNode *p=head;
    while(p&&j<i)
    {
        p=p->next;
        j++;
    }
    if(!p) return error;
    else return p->data;
}
int LinkList::LL_insert(int i,int item)
{
    if(i<=0||i>len+1) return error;
    ListNode *p,*s;
    p=LL_index(i-1);
    s=new ListNode();
    s->data=item;
    s->next=p->next;
    p->next=s;
    len++;
    return ok;
}
int LinkList::LL_del(int i)
{
    if(i<=0||i>len) return error;
    ListNode *p,*s;
    p=LL_index(i-1);
    s=p->next;
    p->next=s->next;
    delete s;
    len--;
    return ok;
}

int main()
{
    int n,i,m;
    int j;
    LinkList list;
    cin>>n;
    for(i=1;i<=n;i++)
    {
        cin>>m;
        list.LL_insert(i,m);
    }
    list.LL_display();
    for(j=0;j<2;j++)
    {
        cin>>i>>m;
        if(list.LL_insert(i,m)!=-1)
            list.LL_display();
        else cout<<"error"<<endl;
    }
    for(j=0;j<2;j++)
    {
        cin>>i;
        if(list.LL_del(i)!=-1)
            list.LL_display();
        else cout<<"error"<<endl;
    }
    for(j=0;j<2;j++)
    {
        cin>>i;
        if(list.LL_get(i)!=-1)
            cout<<list.LL_get(i);
        else cout<<"error"<<endl;
    }
    return 0;
}