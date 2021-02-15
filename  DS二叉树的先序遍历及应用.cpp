#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int M[100];
int x[100];
int I=0;
class BiTreeNode
{
public:
    int data;
    int x;
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
class BiTree
{
public:
    BiTreeNode *Root;
    BiTree()
    {
        Root=CreateBiTree(-1,0);
    }
    BiTreeNode *CreateBiTree(int n,int d)
    {
        BiTreeNode *T;
        int p;
        if(n==-1)
            cin>>p;
        else
            p=n;
        if(p==-1)
            return NULL;
        else
        {
            T=new BiTreeNode();
            T->data=p;
            T->x=d;
            T->Left=CreateBiTree(-1,d-1);
            T->Right=CreateBiTree(-1,d+1);
        }
        return T;
    }
    void Pre(BiTreeNode *p)
    {
        if(p)
        {
            M[I]=p->data;
            x[I]=p->x;
            I++;
            Pre(p->Left);
            Pre(p->Right);
        }
    }
};
int main()
{
    int T=1;
    while(T)
    {
        for(int i=0;i<I;i++)
        {
            M[i]=0;
            x[i]=0;
        }
        I=0;
        BiTree Tree;
        if(Tree.Root==NULL)
            break;
        Tree.Pre(Tree.Root);
        for(int i=0;i<I;i++)
        {
            for(int j=0;j<I-1-i;j++)
            {
                if(x[j]>x[j+1])
                {
                    swap(x[j],x[j+1]);
                    swap(M[j],M[j+1]);
                }
            }
        }
        for(int i=0;i<I;i++)
        {
            for(int j=i+1;j<I;j++)
            {
                if(x[j]==x[i])
                {
                    M[i]+=M[j];
                    x[j]=-9999;
                    M[j]=0;
                }
            }
        }
        cout<<"Case "<<T<<":"<<endl;
        for(int i=0;i<I;i++)
            if(x[i]!=-9999)
                cout<<M[i]<<" ";
        cout<<endl;
        cout<<endl;
        T++;
    }
    return 0;
}