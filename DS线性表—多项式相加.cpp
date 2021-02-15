/*#include<iostream>
#include<cmath>
using namespace std;
class Node
{
	public:
		int coef;
		int expn;
		Node *next;
		Node()
		{
			coef=expn=0;
			next=NULL;
		}	
		Node(int c,int e)
		{
			coef=c;
			expn=e;
			next=NULL;
		}
};
class Poly
{
	public:
		Node *head;
		int len;
		Poly()
		{
			head=NULL;
			len=0;
		}
		~Poly()
		{
			head=NULL;
			len=0;
		}
		void create(int n)
		{
			head=new Node;
			Node *tail;
			tail=head;
			len=n;
			int c,e;
			Node *s;
			while(n--)
			{
				cin>>c>>e;
				s=new Node(c,e);
				tail->next=s;
				tail=s;	
			}
		}
		
		void Add_Poly(Poly &Lb)
		{
			Node *pc=head;
			Node *pa=head->next;
		    Node *pb=Lb.head->next;
			//Node *lc=pc;
			while(pa!=NULL&&pb!=NULL)
			{
				//cout<<"hi"<<endl;
				if(pa->expn<pb->expn)
				{
					pc->next=pa;
					pc=pa;
					pa=pa->next;
				}
				else if(pa->expn>pb->expn)
				{
					pc->next=pb;
					pc=pb;
					pb=pb->next;
				}
				else if(pa->expn==pb->expn)
				{
					int x=pa->coef+pb->coef;
					if(x==0)
					{
						Node*ptr=pa;
						pa=pa->next;
						delete(ptr);
						Node *p=pb;
						pb=pb->next;
						delete(p);
						
					}
					else
					{
						pc->next=pa;
						pa->coef=x;
						pc=pa;
						pa=pa->next;
						Node*ptr=pb;
						pb=pb->next;
						delete(ptr);
					}
				}
			}
			if(pa==NULL)
				pc->next=pb;
			else
				pc->next=pa;
	}
	void display()
		{
			Node *p=head->next;
			if(p==NULL)
			{
				return ;
			}
		
			while(p!=NULL)
			{
				if(p->expn==0)
				{
					if(p->coef<0)
						cout<<"("<<p->coef<<")";
					else if(p->coef>0)
						cout<<p->coef;
					else
						cout<<"";
				}
				else 
				{
					if(p->coef<0)
						cout<<"("<<p->coef<<")"<<"x^"<<p->expn;
					else if(p->coef>0)
						cout<<p->coef<<"x^"<<p->expn;
				}
				
				p=p->next;
				if(p==NULL)
					cout<<"";
				else
					cout<<"+";
			
			}
			cout<<endl;
		}	
};

int main()
{
	int t,n1,n2;
	cin>>t;
	while(t--)
	{
		cin>>n1;
		Poly poly1,poly2;
		poly1.create(n1);
		cin>>n2;
		poly2.create(n2);
		poly1.display();
		poly2.display();
		poly1.Add_Poly(poly2);
		poly1.display();
	}

	return 0;
}

*/

#include<iostream>
using namespace std;
class  Node
{
public:
	int coef;
	int expn;
	Node *next;
	Node()
	{
		coef=expn=0;
		next=NULL;
	}
	Node(int c,int e)
	{
		coef=c;
		expn=e;
		next=NULL;
	}
	~ Node()
	{
		coef=expn=0;
		next=NULL;
	}
	
};
class Poly
{
public:
	Node *head;
	int len;
	Poly()
	{
		head=NULL;
		len=0;
	}
	void create(int n)
	{
		head=new Node;
		len=n;
		Node *p=head;
		Node *s;
		while(n--)
		{
			int c,e;
			cin>>c>>e;
			s=new Node(c,e);
			p->next=s;
			p=p->next;
		}
	}
	void Add_Poly(Poly & Lb)
	{
		Node *pc=head;
		Node *pa=head->next;
		Node *pb=Lb.head->next;
		while(pa!=NULL&&pb!=NULL)
		{
			if(pa->expn<pb->expn)
			{
				pc->next=pa;
				pc=pa;
				pa=pa->next;
			}
			else if(pa->expn>pb->expn)
			{
				pc->next=pb;
				pc=pb;
				pb=pb->next;
			}
			
			else if(pa->expn==pb->expn)
			{
				int x=pa->coef+pb->coef;
				if(x==0)
				{
					Node *ptr;
					ptr=pa;
					pa=pa->next;
					delete(ptr);
					Node *p=pb;
					pb=pb->next;
					delete(p);
				}
				else 
				{
					pa->coef=x;
					pc->next=pa;
					pc=pa;
					pa=pa->next;
					Node *ptr=pb;
					pb=pb->next;
					delete(ptr);
				}
			}
		}
		if(pa!=NULL)
		{
			pc->next=pa;
		}
		else 
		{
			pc->next=pb;
		}
	}
	
	void display()
	{
		Node *p=head;
		p=p->next;
		while(p)
		{
			if(p->expn==0)
			{
				if(p->coef==0)
					cout<<"";
				else if(p->coef<0)
					cout<<"("<<p->coef<<")";
				else
					cout<<p->coef;
			}
			else 
			{
				if(p->coef<0)
				{
					if(p->expn<0)
						cout<<"("<<p->coef<<")x^"<<"("<<p->expn<<")";
					else
						cout<<"("<<p->coef<<")x^"<<p->expn;
				}
				else
				{
					if(p->expn<0)
						cout<<p->coef<<"x^"<<"("<<p->expn<<")";
					else
						cout<<p->coef<<"x^"<<p->expn;
				}
			}
			p=p->next;
			if(p!=NULL)
				cout<<" + ";
			else
				cout<<"";
		}
		cout<<endl;
	}


	~ Poly()
	{
		head=NULL;
		len=0;
	}
	
};
int main()
{
	int t,n1,n2;
	int c,e;
	cin>>t;
	while(t--)
	{
		cin>>n1;
		Poly poly1;
		Poly poly2;
		poly1.create(n1);
		cin>>n2;
		poly2.create(n2);
		poly1.display();
		poly2.display();
		poly1.Add_Poly(poly2);
		poly1.display();
	}
	return 0;
}