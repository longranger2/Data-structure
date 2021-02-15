#include<iostream>
#include<queue>
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

void Create(Node *&p);
class Tree
{
	Node *root;
	public:
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
		void LevelOrder()//定义层次遍历函数
		{
			LevelOrder(root);//共有函数，对外接口
		}
		void LevelOrder(Node *t)
		{//队列实现
			queue<Node *> tq;//创建队列tq，每个元素都是结点
			Node *p=t;//p指向当前结点的指针变量
			if(p)//如果p不空，把p入队
				tq.push(p);
			while(!tq.empty())//执行循环
			{
				p=tq.front();
				tq.pop();
				cout<<p->data;
				if(p->Lchild)//把p的左右结点依次入队
					tq.push(p->Lchild);
				if(p->Rchild)
					tq.push(p->Rchild);
			}
			
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
			//	cout<<"h1"<<endl;
				Create(p->Rchild);
		//		cout<<"h2"<<endl;
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
		Tree tree;
		tree.CreatTree();
		//cout<<"hi"<<endl;
		tree.LevelOrder();
		cout<<endl;
		
	}
	return 0;
}