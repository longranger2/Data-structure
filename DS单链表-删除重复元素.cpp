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
        void find();
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
    while(p!=NULL)
    {
        q=p;
        p=p->next;
        delete q;
    }
    len=0;
    head=NULL;
}
void LinkList::find()
{
	ListNode *root=head->next;
	while(root!=NULL)
	{
		ListNode *flag=root->next;
		ListNode *pre=root;
		while(flag!=NULL)
		{
			if(flag->data==root->data)
			{
				pre->next=flag->next;
				len--;
			}
			else
				pre=flag;
			flag=flag->next;
		}
		root=root->next;
	}
	LL_display();
}
void LinkList::LL_display()
{
	cout<<len<<": ";
    ListNode *p;
    p=head->next;
    while(p)
    {
        if(p->next!=NULL)
        	cout<<p->data<<' ';
        else
        	cout<<p->data;
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
	int t;
	cin>>t;
	while(t--)
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
	    //list.LL_display();
	    list.find();
	    
	}
    
    return 0;
}