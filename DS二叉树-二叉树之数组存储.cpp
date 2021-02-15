#include<iostream>
using namespace std;
class Tree
{
	int len;
	int *data;
	void Preorder(int i)
	{
		if(data[i]!=0&&i<len)
		{
			cout<<data[i]<<" ";
			Preorder(2*i+1);
			Preorder(2*i+2);
		}
	}
public:
	Tree():len(0),data(NULL){}
	void CreateTree()
	{
		cin>>len;
		data=new int[len];
		for(int i=0;i<len;i++)
			cin>>data[i];
	}
	void Preorder()
	{
		Preorder(0);
		cout<<endl;
	}
	~Tree()
	{
		delete []data;
	}
};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		Tree tree;
		tree.CreateTree();
		tree.Preorder();
	}
	return 0;
}