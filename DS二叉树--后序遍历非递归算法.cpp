#include<iostream>
#include<stack>
using namespace std;
class Node
{
public:
	char data;
	Node *Lchild;
	Node *Rchild;
	Node()
	{
		Lchild=NULL;
		Rchild=NULL;
	}
	Node(char d)
	{
		data=d;
		Lchild=NULL;
		Rchild=NULL;
	}
	~Node()
	{
		delete Lchild;
		delete Rchild;
	}
};
class  Tree
{
private:
	void Create(Node *&p)//为什么要加&
	{
		char ch;
		cin>>ch;
		if(ch!='0')
		{
			p=new Node(ch);
			Create(p->Lchild);
			Create(p->Rchild);
		}
		else
			p=NULL;
	}
	void FO(Node *p)
	{
		if(p)
		{
			cout<<p->data;
			FO(p->Lchild);
			FO(p->Rchild);
		}
	}
	void MO(Node *p)
	{
		if(p)
		{
			MO(p->Lchild);
			cout<<p->data;
			MO(p->Rchild);
		}
	}
	void PO()
	{
		int tag;
		stack<Node *>s1;
		stack<int >s2;
		Node *T=root;
		if(!T)
			return;
		else
		{
			Node *p=T;
			do
			{
				while(p)
				{
					s1.push(p);
					tag=0;
					s2.push(tag);
					p=p->Lchild;
				}
				if(s1.empty())
					break;
				if(p==NULL)
				{
					if(s2.top()==0)
					{
						s2.top()=1;
						p=s1.top()->Rchild;
					}
					else if(s2.top()==1)
					{
						p=s1.top();
						s1.pop();
						s2.pop();
						cout<<p->data;
						p=NULL;
					}
				}
			}while(!s1.empty());
		}
		
	}
public:
	Node *root;
	 Tree()
	 {
	 	root=NULL;
	 }
	~ Tree()
	{
		delete root;
	}
	void CreaTree()
	{
		Create(root);
	}
	void PreOrder()
	{
		FO(root);
		cout<<endl;
	}
	void MidOrder()
	{
		MO(root);
		cout<<endl;
	}
	void PostOrder()
	{
		PO();
		cout<<endl;
	}
	
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Tree tree;
		tree.CreaTree();
		tree.PostOrder();
	}
	return 0;
}