/*#include <iostream>
#include <queue>
using namespace std;

class BiNode{
    char data;
    BiNode *lChild;
    BiNode *rChild;
    int road;
public:
    BiNode():lChild(NULL),rChild(NULL){}
    BiNode(char e):data(e),lChild(NULL),rChild(NULL){}
    ~BiNode(){delete lChild; delete rChild;}
    friend class BiTree;
};

class BiTree{
    BiNode *root;
    int count;
    queue<int> weight;
    void CreateTree(BiNode *&t, int layer);
    void preOrder(BiNode *t);
public:
    BiTree():root(NULL),count(0){}
    void CreateTree();
    void preOrder();
    void getWeight();
};

void BiTree::CreateTree(BiNode *&t,int layer) {
    char c;
    cin>>c;
    if(c!='0')
    {
        t = new BiNode(c);
        t->road = layer;
        CreateTree(t->lChild,layer+1);
        CreateTree(t->rChild,layer+1);
    }
}

void BiTree::CreateTree() {
    CreateTree(root,0);
}

void BiTree::preOrder(BiNode *t) {
    if(t)
    {
        if(!t->lChild && !t->rChild) {
            count += weight.front() * t->road;
            weight.pop();
        }
        preOrder(t->lChild);
        preOrder(t->rChild);
    }
}

void BiTree::preOrder() {
    preOrder(root);
    cout<<count<<endl;
}

void BiTree::getWeight() {
    int n;
    cin>>n;
    while (n--)
    {
        int w;
        cin>>w;
        weight.push(w);
    }
}

int main()
{
    int t;
    cin>>t;
    while (t--)
    {
        BiTree myTree;
        myTree.CreateTree();
        myTree.getWeight();
        myTree.preOrder();
    }
    return 0;
}*/


#include<iostream>
#include<queue>
using namespace std;
class Node
{
    char data;
    int road;
    Node *lChild;
    Node *rChild;
    friend class Tree;
public:
    Node():lChild(NULL),rChild(NULL){}
    Node(char d):data(d),lChild(NULL),rChild(NULL){}
    ~Node(){delete lChild;delete rChild;}
};
class Tree
{
    Node *root;
    int count;
    queue<int> weight;
    void Create(Node *&p,int layer)
    {
        char ch;
        cin>>ch;
        if(ch!='0')
        {
            p=new Node(ch);
            p->road=layer;
            Create(p->lChild,layer+1);
            Create(p->rChild,layer+1);
        }
    }
    void find(Node *p)
    {
        if(p)
        {
            if(p->lChild==NULL&&p->rChild==NULL)
            {
                count+=p->road*weight.front();
                weight.pop();
            }
            find(p->lChild);
            find(p->rChild);
        }
    }
public:
    Tree():root(NULL),count(0){}
    void CreateTree()
    {
        Create(root,0);
    }
    ~Tree(){delete root;}
    void getWeight()
    {
        int n,num;
        cin>>n;
        while(n--)
        {
            cin>>num;
            weight.push(num);
        }
    }
    void preOrder()
    {
        find(root);
        cout<<count<<endl;
    }

};
int main()
{
    int n;
    cin>>n;
    while(n--)
    {
        Tree tree;
        tree.CreateTree();
        tree.getWeight();
        tree.preOrder();
    }
    return 0;
}