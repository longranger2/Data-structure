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
	//	friend class Tree;
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
	
	void del()
	{
		int num;
		cin>>num;
		Node *previous=root;
		Node *p=root;
		while(p)
		{
			if(p->data==num)
				break;
			else if(num<p->data)
			{
				previous=p;
				p=p->Lchild;
			}
			else if(num>p->data)
			{
				previous=p;
				p=p->Rchild;
			}
		}
	//	cout<<previous->data<<" "<<p->data<<endl;
		if(p)//找到了要删除的数 
		{
			if(!p->Lchild&&!p->Rchild)//叶子节点 
			{
				previous->Lchild==p ? previous->Lchild=NULL : previous->Rchild=NULL;//判断是其父亲结点的左孩子还是右孩子
				delete p;
			//	cout<<"叶子"<<endl; 
			}
			else if(!p->Lchild&&p->Rchild)//左孩子为空的情况 
			{
				if(previous->Rchild==p)
				{
					previous->Rchild=p->Rchild;
					delete p;
				//	p=NULL;
				} 
				else if(previous->Lchild==p)
				{
					previous->Lchild=p->Rchild;
					delete p;
				//	p=NULL;
				}
			//	cout<<"左孩子"<<endl; 
			}
			else if(p->Lchild&&!p->Rchild)//右孩子为空的情况 
			{
				if(previous->Rchild==p)
				{
					previous->Rchild=p->Lchild;
					delete p;
				//	p=NULL;
				} 
				else if(previous->Lchild==p)
				{
					previous->Lchild=p->Lchild;
					delete p;
				//	p=NULL;
				}
			//	cout<<"右孩子"<<endl; 
			}
			else if(p->Lchild&&p->Rchild)//左右都不空时 
			{
				Node *q=p;
				Node *pre=p;
				q=q->Lchild;
				while(q->Rchild)
				{
					pre=q;
					q=q->Rchild;
				}
				p->data=q->data;
				if(q->Lchild==NULL)//一定没有右结点
				{
					pre->Lchild==q ? pre->Lchild=NULL :pre->Rchild=NULL;
					delete q;
					//q=NULL;
				}
				else
				{
					pre->Lchild==q ? pre->Lchild=q->Lchild :pre->Rchild=q->Lchild;
					delete q;
					//q=NULL;
				}
				//cout<<q->data<<endl;
				pre=NULL;
				//delete pre;
			//	cout<<"左右"<<endl;
			}
			
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
		void Delete()
		{
			del();
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
			tree.Delete();
			tree.MidOrder();
		}
	}
	return 0;
}