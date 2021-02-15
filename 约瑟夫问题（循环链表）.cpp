#include<iostream>
using namespace std;
/*class Node
{
	public:
	int No;
	Node *next;
	Node()
	{
		No=0;
		next=NULL;
	}	
	Node(int n)
	{
		No=n;
		next=NULL;
	}
};
class LinkList
{
	public:
	Node *head;
	int len;
	LinkList()
	{
		head=NULL;
		len=0;
	}	
	void Create(int n)
	{
		head=new Node(1);
		head->next=head;
		Node *tail;
		tail=head;
		len=n;
		Node *s;
		for(int i=2;i<=n;i++)
		{
			s=new Node(i);
			tail->next=s;
			s->next=head;
			tail=s;	
		}
		//s->next=head;
	}
	void Display(int n)
	{
		Node *p;
		p=head;
		for(int i=0;i<=n;i++)
		{
			cout<<p->No<<" ";
			p=p->next;
		}
		
	}
	void Start(int k,int s)
	{
	
		Node *p=head;
		s=s-1;
		while(s--)
		{
			p=p->next;
		}
		int flag=0;
		while(flag<len)
		{
			for(int i=1;i<k-1;i++)
			{
				p=p->next;
			}
			cout<<p->next->No<<" ";
			Node *ptr=p->next;
			p->next=ptr->next;
			delete ptr;
			p=p->next;
			//p=p->next;
			flag++;
		}
	}
	
	
};
int main()
{
	int n,s,k;
	cin>>n>>k>>s;
	LinkList ll;
	ll.Create(n);
	//ll.Display(n);
	ll.Start(k,s);
	return 0;
}
*/
class Node
{
	public:
		int No;
		Node *next;
		Node()
		{
			No=0;
			next=NULL;
		}
		Node(int n)
		{
			No=n;
			next=NULL;
		}
};
class LinkList
{
public:
	Node *head;
	int len;
	LinkList()
	{
		head=NULL;
		len=0;
	}
	void Create(int n)
	{
		head=new Node(1);
		len=n;
		Node *tail=head;
		Node *s;
		for(int i=2;i<=n;i++)
		{
			s=new Node(i);
			tail->next=s;
			s->next=head;
			tail=s;
		}
	}
	void Start(int k,int s)
	{
		Node *p=head;
		s--;
		while(s--)
		{
			p=p->next;
		}
		int time=0;
		while(time<len)
		{

			for(int i=1;i<k-1;i++)
			{
				p=p->next;
			}
			cout<<p->next->No<<" ";
			Node *ptr=p->next;
			p->next=ptr->next;
			delete ptr;
			p=p->next;
			time++;
		}
		cout<<endl;
	}
	~LinkList(){}
	
};
int main()
{
	int n,s,k;
	cin>>n>>k>>s;
	LinkList ll;
	ll.Create(n);
	//ll.Display(n);
	ll.Start(k,s);

	
	return 0;
}