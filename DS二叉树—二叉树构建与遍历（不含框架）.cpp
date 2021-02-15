#include<iostream>
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
		if(ch!='#')
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
	void PO(Node *p)
	{
		if(p)
		{
			PO(p->Lchild);
			PO(p->Rchild);
			cout<<p->data;
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
		PO(root);
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
		tree.PreOrder();
		tree.MidOrder();
		tree.PostOrder();
	}
	return 0;
}