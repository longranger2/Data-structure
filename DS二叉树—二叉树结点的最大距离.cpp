#include<iostream>
#include<string>
#include<cstring>
using namespace std;
int M[100];
char L[100];
char R[100];
int I=0;
class BiTreeNode//结点
{
public:
    char data;
    BiTreeNode *Left;
    BiTreeNode *Right;
    BiTreeNode()
    {
        Left=NULL;
        Right=NULL;
    }
    ~BiTreeNode()
    {
        delete Left;
        delete Right;
    }
};
 
class BiTree//树
{
public:
    BiTreeNode *Root;
    int pos;//初始化时作为类的全局变量
    string strTree;
    int deep;
    int leftdeep;
    int rightdeep;
    char leftc;
    char rightc;
    char c;
    int maxx;
    BiTree(string str)//树的初始化
    {
        pos=0;
        deep=0;
        leftdeep=0;
        rightdeep=0;
        maxx=0;
        strTree=str;
        Root=CreateBiTree();
    }
    BiTreeNode *CreateBiTree()//树的构建
    {
        char ch=strTree[pos];
        pos++;
        if(ch=='#')
        {
            return NULL;
        }
        else
        {
            BiTreeNode *T;
            T=new BiTreeNode();
            T->data=ch;
            T->Left=CreateBiTree();
            T->Right=CreateBiTree();
            return T;
        }
    }
    void countleftdeep(BiTreeNode *p)//求当前树结点的左子树最大深度
    {
        if(p->Left==NULL)//左子树为空
        {
            leftdeep=0;
            leftc=p->data;
            return;
        }
        p=p->Left;
        countdeep(p,0);//写0是因为后面是先自加
        leftdeep=deep;//递归完之后将深度deep赋值给leftdeep
        leftc=c;//并且将相应结点的字符赋值给leftc
        return;
    }
    void countrightdeep(BiTreeNode *p)//求当前树结点的右子树最大深度
    {
        if(p->Right==NULL)
        {
            rightdeep=0;
            rightc=p->data;
            return;
        }
        p=p->Right;
        countdeep(p,0);
        rightdeep=deep;
        rightc=c;
        return;
    }
    void countdeep(BiTreeNode *p,int i)
    {
        if(p)
        {
            i++;
            if(p->Left==NULL&&p->Right==NULL)//到达叶子结点位置
            {
                if(deep<i)//若原有的深度小于现在的深度，则将两者替换，并存储此时的字符
                {
                    deep=i;
                    c=p->data;
                }
            }
            countdeep(p->Left,i);
            countdeep(p->Right,i);
        }
    }
    void pre(BiTreeNode *p)//
    {
        if(p!=NULL)
        {
            deep=0;
            countleftdeep(p);//求当前树结点的左子树最大深度
            deep=0;
            countrightdeep(p);//求当前树结点的右子树最大深度
            deep=0;
            maxx=leftdeep+rightdeep;//将两者相加即是该树结点的最大距离
            M[I]=maxx;
            L[I]=leftc;
            R[I]=rightc;
            I++;
            pre(p->Left);//求其左结点的最大距离
            pre(p->Right);//求其右结点的最大距离
        }
    }
};
 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        for(int i=0;i<I;i++)
            M[i]=0;
        memset(L,0,sizeof(L));//将L数组初始化为0
        memset(R,0,sizeof(L));//将R数组初始化为0
        I=0;
        string str;
        cin>>str;
        BiTree tree(str);
        tree.pre(tree.Root);
        int m=M[0];
        int index=0;
        for(int i=0;i<I;i++)//遍历M数组，找到其中最大距离的下标
        {
            if(M[i]>m)
                index=i;
        }
        cout<<M[index]<<":";
        if(M[index]!=0)
            cout<<L[index]<<" "<<R[index]<<endl;
        else
            cout<<endl;
    }
    return 0;
}