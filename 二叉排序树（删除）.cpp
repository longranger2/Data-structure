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
		//friend class Tree;
};
class Tree
{
	Node *root;
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
		cin >> num;                //输入要删除的结点的值
		Node *temp, *previous;
		temp = root;
		previous = root;
		while (temp != NULL)
		{
			if (temp->data == num)
				break;
			else if (temp->data > num)
			{
				previous = temp;
				temp = temp->Lchild;
			}
			else
			{
				previous = temp;
				temp = temp->Rchild;
			}
		}
		//cout<<temp->data<<endl;
		if (temp != NULL)
		{
			if (temp->Lchild == NULL)        //要删的结点的左孩子为空的情况
			{
				if (temp==root && temp->Rchild==NULL)
				{
				    delete temp;//delete只是删除temp所存储的那部分内存，temp指针的值（地址值仍存在）并非就是NULL，而是碎挤汁
				    temp=NULL;
				}
				else
				{
				    previous->Lchild==temp ? previous->Lchild=temp->Rchild :previous->Rchild=temp->Rchild;
	                delete temp;
	                temp=NULL;
				}
			}
			else if (temp->Rchild == NULL)        //要删的结点的右孩子为空的情况
			{
			    previous->Lchild == temp ? previous->Lchild=temp->Lchild :previous->Rchild=temp->Lchild;
	            delete temp;
	            temp=NULL;
			}
			else                            //要删的结点的左、右孩子都不为空的情况
			{
				Node *right_min = temp->Rchild;
				previous = right_min;
				while (right_min->Lchild != NULL)        //找到右子树最小结点
				{
				    previous = right_min;
					right_min = right_min->Lchild;
				}
				temp->data = right_min->data;            //最小结点的值赋给要删除的结点
				if(right_min == previous)
	            {
	                temp->Rchild=right_min->Rchild;
	            }
	            else
	            {
	                previous->Lchild = right_min->Rchild;
	            }
				delete right_min;  
				right_min=NULL;              //删除右子树的最小结点
			}
		}
	}
	public:
		Tree(){}
		Tree(int d)
		{
			root=new Node(d);
		}	
		~Tree(){}
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