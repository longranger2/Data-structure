#include<iostream>
#include<string>
using namespace std;
class Node
{
public:
    char data;
    Node *left;
    Node *right;
    Node()
    {
        left=right=NULL;
    }
};
 
class Tree
{
public:
    int pos;
    Node *Root;
    string strtree;
    string strpre;
    string strin;
    Tree(string str)
    {
        strpre="";
        strin="";
        pos=0;
        strtree=str;
        Root=CreateTree();
    }
    Node *CreateTree()
    {
        char ch=strtree[pos];
        pos++;
        if(ch=='#')
            return NULL;
        else
        {
            Node *T=new Node();
            T->data=ch;
            T->left=CreateTree();
            T->right=CreateTree();
            return T;
        }
    }
    void preorder(Node *T)
    {
        if(T!=NULL)
        {
            strpre+=T->data;
            preorder(T->left);
            preorder(T->right);
        }
        return;
    }
    void inorder(Node *T)
    {
        if(T!=NULL)
        {
            inorder(T->left);
            strin+=T->data;
            inorder(T->right);
        }
        return;
    }
};
 
class Martree
{
public:
    char *Tree;
    int number;
    string strpre;
    string strin;
    Martree(string str)
    {
        strpre="";
        strin="";
        number=(int)str.size();
        Tree=new char[number];
        for(int i=0;i<number;i++)
            Tree[i]=str[i];
    }
    void preorder(int i)
    {
        if(i<number)
        {
            if(Tree[i]!='#')
            {
                strpre+=Tree[i];
                preorder(2*i+1);
                preorder(2*i+2);
            }
        }
        return;
    }
    void inorder(int i)
    {
        if(i<number)
        {
            if(Tree[i]!='#')
            {
                inorder(2*i+1);
                strin+=Tree[i];
                inorder(2*i+2);
            }
        }
        return;
    }
};
 
 
 
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        string str1,str2;
        cin>>str1>>str2;
        if(str2[str2.size()-1]!='#')
            str2+="##";
        Martree mTree(str1);
        Tree bTree(str2);
        mTree.preorder(0);
        mTree.inorder(0);
        bTree.preorder(bTree.Root);
        bTree.inorder(bTree.Root);
        if(mTree.strpre==bTree.strpre&&mTree.strin==bTree.strin)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}