#include<iostream>
#include<string> 
using namespace std;
 
int B;
class BNode{
    public :
        char data;
        BNode *left, *right; 
        BNode(){
            left= NULL;
            right= NULL;
        }
}; 
 
class TNode{
    public:
        char data;
        TNode **child;
        TNode(){
            child = new TNode*[B];
            for(int i= 0; i< B; i++)
              child[i]= NULL;
        }
};
 
class Tree
{
    private:
         TNode* root;
    public :
        Tree()
        {
            int i= 0; //
            root= CreateTree();
        }
        TNode* CreateTree(){
            TNode *p= NULL;
            char c;
            cin>>c;
            if(c!= '0'){
                p= new TNode;
                p->data= c;
                for(int k= 0; k< B; k++)
                  p->child[k]= CreateTree();
            } 
            return p;
        }
        BNode* change(){
            return change(root);
        }
        BNode* change(TNode* t)
        {
            BNode *p= NULL;
            if(t){
                p= new BNode;
                p->data= t->data;
                p->left= change(t->child[0]);
                if(p->left){
                    BNode *q= p->left;
                    for(int i= 1; i< B; i++){
                        q->right= change(t->child[i]);
                        if(q->right)
                          q= q->right;
                    } 
                }
            } 
            return p;
        }
};
 
class BiTree{
    private:
        BNode* root;
        void get_leaves(BNode* t, string str)
        {
            if(t)
            {
                if(!t->left&&!t->right)
                {
                    int len= str.length();
                    str= str.substr(0, len- 1);
                     
                    cout<<str<<endl;
                }
                get_leaves(t->left, str+ "0 ");
                get_leaves(t->right, str+ "1 ");
            }
        }
    public :
        void merge(BNode** t, int N)
        {
            for(int i= 0; i< N- 1; i++)
              t[i]->right= t[i+ 1];
              root= t[0];
        }
        void get_leaves()
        {
            string str= "";
            get_leaves(root, str);
        }
};
 
int main()
{
    int n;
    cin>>n>>B;
    Tree* p= new Tree[n];
    BNode**q= new BNode*[n];
     
    for(int i= 0; i< n; i++)
        q[i]= p[i].change();
    BiTree tree;
    tree.merge(q, n);
    tree.get_leaves();
     
    return 0;
}