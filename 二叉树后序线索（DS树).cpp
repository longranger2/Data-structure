#include<iostream>
using namespace std;
#include <queue>
#include<string.h>
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
	string s;
	void order(Node *p)
	{
		if(p)
		{
			order(p->Lchild);
			order(p->Rchild);
			s+=p->data;
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
		void Postorder()
		{
			order(root);
		}
		void Find()
		{
			int i;
		    char ch;
		    cin>>ch;
		    int len = (int)s.length();
		    for(i=0; i<len; i++)
		    {
		        if(s[i]==ch)
		            break;
		    }
		    if(i==len)
		        cout<<"ERROR"<<endl;
		    else if(!i && i==len-1)
		        cout<<"－1 －1"<<endl;
		    else if(!i && i!=len-1)
		        cout<<"－1 "<<s[i+1]<<endl;
		    else if(i && i==len-1)
		        cout<<s[i-1]<<" －1"<<endl;
		    else
		        cout<<s[i-1]<<' '<<s[i+1]<<endl;
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
		tree.Postorder();
		tree.Find();
		tree.Find();
	}
	return 0;
}