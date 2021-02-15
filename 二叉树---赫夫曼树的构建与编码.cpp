#include<iostream>
#include<string>
#include<cstring>
using namespace std;
 
const int maxW= 9999;
 
class HuffNode{
    public:
        int weight;
        int parent;
        int leftChild;
        int rightChild;
};
 
class HuffMan{
    private:
        void MakeTree()
        {
            for(int i= lnum+ 1; i<= len; i++)
            {
                int s1, s2;
                SelectMin(i- 1, &s1, &s2);//寻找没有父节点的最小的两个
                huffTree[s1].parent= huffTree[s2].parent= i;
                huffTree[i].leftChild= s1;
                huffTree[i].rightChild= s2;
                //父节点的权重等于两个子节点的权重之和
                huffTree[i].weight= huffTree[s1].weight+ huffTree[s2].weight;
            }
        }
        void SelectMin(int pos, int *s1, int *s2){
            int w1, w2, i;
            w1= w2= maxW;
            *s1= *s2= 0;
             
            for(i= 1; i<= pos ; i++)
            {
            //找到最小的两个的同时保证s1比s2小
               /* if(w1>huffTree[i].weight&&!huffTree[i].parent)
                {
                    w2=w1;
                    *s2=*s1;
                    w1=huffTree[i].weight;
                    *s1=i;
                }
                else if(w2>huffTree[i].weight&&!huffTree[i].parent)
                {
                    w2=huffTree[i].weight;
                    *s2=i;
                }*/
                if(w1> huffTree[i].weight&&!huffTree[i].parent){
                    w2= w1;
                    *s2= *s1;   
                       
                    w1= huffTree[i].weight;
                    *s1= i;         
                }
                else if(w2> huffTree[i].weight&&!huffTree[i].parent){
                    w2= huffTree[i].weight;
                    *s2= i;
                }
            }
        }
         
    public:
        int len;
        int lnum;
        HuffNode *huffTree;
        string *huffCode;
        void MakeTree(int n, int wt[])
        {
            int i;
            lnum= n;
            len= 2*n- 1;
            huffTree = new HuffNode[2*n];
            huffCode= new string[lnum+ 1];
                
            for(i= 1; i<= n; i++)
               huffTree[i].weight= wt[i- 1];
             
            for(i= 1; i<= len; i++){
                if(i> n)
                 huffTree[i].weight= 0;
                 huffTree[i].parent= 0;
                 huffTree[i].leftChild= 0;
                 huffTree[i].rightChild= 0;
            }
            MakeTree();
        }
        void Coding(){
            char *cd;
            int i, c, f, start;
             
            cd= new char[lnum];
            cd[lnum- 1]= '\0';
            /*for(i=1;i<lnum;i++)
            {
                start=lnum-1;
                for(c=i,f=huffTree[i].parent;f!=0;c=f,f=huffTree[f].parent)
                {
                    if(huffTree[f].leftChild==c)
                    {
                        cd[--start]=='0';
                    }
                    else{
                        cd[--start]=='1';
                    }
                }
                huffCode[i].assign(&cd[start]);

            }*/
            for(i= 1; i<= lnum; i++){
                start= lnum- 1;
                 
                for(c= i, f= huffTree[i].parent; f!= 0; c= f, f= huffTree[f].parent)
                   if(huffTree[f].leftChild== c){
                    cd[--start]= '0';            
                   } 
                   else{
                    cd[--start]= '1';   
                   }
                huffCode[i].assign(&cd[start]);
            }            
            delete []cd;
        }
        void Destroy(){
            len= 0;
            lnum= 0;
            delete []huffTree;
            delete []huffCode;
        }
};
 
int main(){
    int t, n,i,j;
    int wt[800];
    HuffMan myHuff;
    cin>>t;
    for(i= 0; i< t; i++){
        cin>>n;
        for(j= 0; j< n; j++)
           cin>>wt[j];
         
        myHuff.MakeTree(n, wt);
        myHuff.Coding();
        for(j= 1; j<= n; j++){
            cout<<myHuff.huffTree[j].weight<<'-';
            cout<<myHuff.huffCode[j]<<endl;
        }
        myHuff.Destroy();
    }
    return 0;
}

