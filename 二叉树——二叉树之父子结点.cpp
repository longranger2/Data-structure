#include<iostream>
using namespace std;
#include <queue>
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
void Create(Node *&p);
class Tree
{
	Node *root;
	void FO1(Node *p,char ch)
	{
		if(p)
		{
			if(p->Lchild==NULL&&p->Rchild==NULL)
			{
				cout<<p->data<<" ";
				q.push(ch);
			}
			FO1(p->Lchild,p->data);
			FO1(p->Rchild,p->data);
		}
	}
	public:
		queue<char> q;
		Tree()
		{
			root=NULL;		
		}
		~Tree()
		{
			delete root;
		}
		void CreatTree()
		{
			Create(root);
		//	cout<<"h3"<<endl;
		}		
		
		void Find()
		{
			FO1(root,root->data);
			cout<<endl;
		}
		
};
void Create(Node *&p)
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
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char ch;
		Tree tree;
		tree.CreatTree();
		tree.Find();
		while(!tree.q.empty())
		{
			ch=tree.q.front();
			tree.q.pop();
			cout<<ch<<" ";
		}
		cout<<endl;
	}
	return 0;
}