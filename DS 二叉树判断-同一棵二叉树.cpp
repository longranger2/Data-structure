/*#include<iostream>
using namespace std;
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1 //std中的NULL默认为0，而0为数组的第一个下标

struct TreeNode
{
    ElementType Element;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];

Tree BuildTree(struct TreeNode T[])
{
    ElementType cl,cr;
    Tree N,Root,check[10],i;//Root是结构数组的下标，也是根节点的下标
    cin >> N;//输入树的元素个数
    if(N)
    {
        for(i=0;i<N;i++) check[i] = 0;//check数组用来记录哪一个结点没有被其他结点指过，说明该结点是根节点，初始化为0，表示全未被指过
        for(i=0;i<N;i++)//遍历N次，从数组下标开始
        {
            cin >>T[i].Element;//cl,cl是char型的左右值，还要转换成整型
            cin >> cl;
            cin >> cr;
            if(cl!='-')//输入‘-’说明其左子节点非空
            {
                T[i].Left = cl-'0';//类型转换成整型
                check[T[i].Left] = 1;//说明这个结点被指过，不能是根结点
            }
            else T[i].Left = Null;//子节点为空，其左右值设为-1
            if(cr!='-')//输入‘-’说明其左子节点非空
            {
                T[i].Right = cr-'0';//类型转换成整型
                check[T[i].Right] = 1;//说明这个结点被指过，不能是根结点
            }
            else T[i].Right = Null;
        }
        for(i=0;i<N;i++)
                if(!check[i]) break;//遍历，直到直到找到根节点
        Root = i;
    }
    return Root;
}


int Isomorphic(Tree R1,Tree R2)
{
    //第一个树且第二个树都为空，返回相同
    if((R1==Null)&&(R2==Null)) return 1;
    //第一个结点空，第二个非空或者反之，返回不同
    if(((R1==Null)&&(R2!=Null)) || ((R1!=Null)&&(R2==Null)))
        return 0;
    //结点元素不相同
    if(T1[R1].Element!=T2[R2].Element) return 0;
    //左子树均为空，则继续判断右子树
    if((T1[R1].Left==Null)&&T2[R2].Left==Null)
        return Isomorphic(T1[R1].Right,T2[R2].Right);
    //左子树均非空，且元素相同，则需继续判断其根节点的左右子树，这里为什么不对其右子树直接判断？是因为return语句进行递归的过程中会对其右子树进行判断，在此判断多此一举
    if(((T1[R1].Left!=Null)&&(T2[R2].Left!=Null))&&
        ((T1[T1[R1].Left].Element==T2[T2[R2].Left].Element)))
        return (Isomorphic(T1[R1].Left,T2[R2].Left)&&//判断其左子树
                Isomorphic(T2[R1].Right,T2[R2].Right));//判断其右子树
    else//否则则可能是对称同构，需要进一步判断是否左=右，和右=左
        return (Isomorphic(T1[R1].Left,T2[R2].Right)&&
                Isomorphic(T1[R1].Left,T2[R2].Left));
}
int main()
{
    Tree R1,R2;
    R1 = BuildTree(T1);//建立第一棵结构数组二叉树
    R2 = BuildTree(T2);//第二棵
    cout << R1<<endl;
    cout << R2<<endl;
    if(Isomorphic(R1,R2)) 
        cout << "Yes"<<endl;//判断是否同构
    else 
        cout<<"No"<<endl;
    return 0;
}
*/

/*
#include<iostream>
using namespace std;
typedef struct TreeNode
{

　　char c;
　　struct TreeNode * left;
　　struct TreeNode * right;
};

　　判断两棵二叉树是否相等，如果相等返回0，如果不相等则返回1

　　int compareTree(TreeNode* tree1, TreeNode* tree2)
{

　　//用分治的方法做，比较当前根，然后比较左子树和右子树

　　bool tree1IsNull = (tree1==NULL);

　　bool tree2IsNull = (tree2==NULL);

　　if(tree1IsNull != tree2IsNull)
    {

　　 　  return 1;

    }

　　if(tree1IsNull && tree2IsNull)
{

　　//如果两个都是NULL，则相等

　　return 0;

}

　　//如果根节点不相等，直接返回不相等，否则的话，看看他们孩子相等不相等
if(tree1->c != tree2->c)
{
　　return 1;
}

    return (compareTree(tree1->left,tree2->left)&&compareTree(tree1->right,tree2->right))||(compareTree(tree1->left,tree2->right)&&compareTree(tree1->right,tree2->left));
}*/





#include<iostream>
#include<string>
using namespace std;
void Inorder(string &s,string cs,int n,int i=0)
{
    if(i>=n)
        s+='#';
    else if(cs[i]=='#')
        s+='#';
    else
    {
    s+=cs[i];
    Inorder(s,cs,n,2*i+1); 
    Inorder(s,cs,n,2*i+2);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string cs,cs1;
        string s="";
        int i=0;
        cin>>cs>>cs1;
        int n=cs.length();
        Inorder(s,cs,cs.length(),i);
        if(s==cs1)
            cout<<"YES\n";
        else
        {
            cs1+="##";
            if(s==cs1)
            cout<<"YES\n";
            else
            cout<<"NO\n";
        }
    }
    return 0;
}
