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
		if(ch!='0')
		{
			p=new Node(ch);
			Create(p->Lchild);
			Create(p->Rchild);
		}
		else
			p=NULL;
	}
	int TreeHeight(Node *root)
	{
		if(root==NULL)
			return 0;
		if(root->Lchild==NULL&root->Rchild==NULL)
			return 1;
		return max(TreeHeight(root->Lchild),TreeHeight(root->Rchild))+1;
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
	void Height()
	{ 
		int num;
		num=TreeHeight(root);
		cout<<num<<endl;
	}
	
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int num;
		Tree tree;
		tree.CreaTree();
		tree.Height();
	}
	return 0;
}