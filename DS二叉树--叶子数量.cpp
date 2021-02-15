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
	void Count(Node *p,int &n)
	{
		if(p)
		{
			if(p->Lchild!=NULL&&p->Lchild->Lchild==NULL&&p->Lchild->Rchild==NULL)
				n++;
			else
			{
				Count(p->Lchild,n);
				Count(p->Rchild,n);
			}
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
	void Count_Leftleaf()
	{
		int n=0;
		Count(root,n);
		cout<<n<<endl;
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
		tree.Count_Leftleaf();
	}
	return 0;
}