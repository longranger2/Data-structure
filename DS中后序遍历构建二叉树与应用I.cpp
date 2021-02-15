#include<cstdio>
#include<iostream>
#define maxn 100000
using namespace std;
struct node
{
	int data;//值 
	int height;//高度 
	node* left;//左子树 
	node* right; //右子树 
}; 
int in[maxn];
int post[maxn];
int N;
node* create(int postL,int postR,int inL,int inR)//postL 后续遍历的最左边的值，postL 后序遍历最右边的值
{
	if(postL > postR)
	{//说明到头了 
		return NULL; 
	}//下面这个就是建树的步骤 
	node* root = new node;
	root->data = post[postR];//新节点的数据域为根节点的值 
	int i;
	for(i = inL; i <= inR;i++ )
	{
		if(in[i] == post[postR]){//说明找到了相同值 ，in[i]是中序遍历
			break;
		}
	}
	int numLeft ;//表示的是这个根节点左侧的节点数
	numLeft = i - inL;
	root->left = create(postL,postL+numLeft-1,inL,i-1); //建左子树 
	root->right = create(postL+numLeft,postR-1,i+1,inR);//建右子树 
	return root; 
} 
//输出先序遍历 
void preOrder(node* root)
{
	cout << root->data <<" ";
	if(root->left!=NULL) preOrder(root->left);//输出左子树 
	if(root->right!=NULL) preOrder(root->right);//输出右子树 
}
void find(node *p,int *Min)
{
	if(p)
	{
		if(p->left==NULL&&p->right==NULL)
	{
		if(p->data<*Min)
			*Min=p->data;
	}
	find(p->left,Min);
	find(p->right,Min);
	}
}
int main()
{
	while(scanf("%d",&N)!=EOF)
	{
	int i;
	int Min=1000000;
	for(i = 0;i< N;i++){
		cin >> in[i];//中序遍历
	}
	for(i = 0;i< N;i++){//后序遍历
		cin >> post[i];
	}
	node* root = create(0,N-1,0,N-1);
	find(root,&Min); 
	cout<<Min<<endl;
	}
	
}