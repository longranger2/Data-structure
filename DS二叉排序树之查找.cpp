#include<iostream>
using namespace std;
class Node
{
	public:
		int data;
		Node *Lchild;
		Node *Rchild;
		Node()
		{
			data=0;
			Lchild=Rchild=NULL;
		}
		Node(int d)
		{
			data=d;
			Lchild=Rchild=NULL;
		}
		~Node()
		{
			delete Lchild;
			delete Rchild;
		}
		friend class Tree;
};
class Tree
{
	Node *root;
	int time;
	void insert_Node(Node *r,int num)
	{
		if(num>r->data&&r->Rchild)
			insert_Node(r->Rchild,num);
		else if(num<r->data&&r->Lchild)
			insert_Node(r->Lchild,num);
		else if(num>r->data&&!r->Rchild)
		{
			Node *s=new Node(num);
			r->Rchild=s;
		}
		else if(num<r->data&&!r->Lchild)
		{
			Node *s=new Node(num);
			r->Lchild=s;
		}
			
	}
	void MidOrder(Node *r)
	{
		if(r)
		{
			MidOrder(r->Lchild);
			cout<<r->data<<" ";
			MidOrder(r->Rchild);
		}
	}
	void find(Node *r,int num)
	{
		if(num==r->data)
		{
			time++;
			cout<<time<<endl;
		}
		else if(num>r->data&&r->Rchild)
		{
			time++;
			find(r->Rchild,num);
		}
		else if(num<r->data&&r->Lchild)
		{
			time++;
			find(r->Lchild,num);
		}
		else
		{
			cout<<"-1"<<endl;
		}
	}
	public:
		Tree(int d)
		{
			root=new Node(d);
		}	
		void insert(int num)
		{
			insert_Node(root,num);
		}
		void MidOrder()
		{
			MidOrder(root);
			cout<<endl;
		}
		void Find(int num)
		{
			time=0;
			find(root,num);
		}
};
int main()
{
	int t,n,num;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>num;
		Tree tree(num);
		for(int i=1;i<n;i++)
		{
			cin>>num;
			tree.insert(num);
		}
		tree.MidOrder();
		cin>>n;
		while(n--)
		{
			cin>>num;
			tree.Find(num);
		}
	}
	return 0;
}