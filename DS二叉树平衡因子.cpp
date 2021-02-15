#include<iostream>
using namespace std;
class Tree
{
    private:
        int n;
        char *data;
        int *Left;   //存左子树深度
        int *Right;  //存右子树深度
    public:
        Tree(){}
        ~Tree(){}
        void Set_Tree()
        {
            cin>>n;
            data=new char[n];
            for(int i=0;i<n;i++)
            {
                cin>>data[i];
            }
            Left=new int[n];
            Right=new int[n];
            for(int i=0;i<n;i++)//初始化
            {
                Left[i]=-1;
                Right[i]=-1;
            }
        }
        void Get_balance_factor(int k)
        {
            int left=2*k+1,right=2*k+2;
            if(left>=n)   //左右子树都不存在,则深度为0
            {
                Left[k]=0;
                Right[k]=0;
            }    
            else
            {
                if(data[left]=='0')  //左子树不存在
                    Left[k]=0;
                else
                {
                    Get_balance_factor(left);
                    Left[k]=Left[left]>Right[left]? Left[left]+1 : Right[left]+1;
                }
                if(right>=n) //右子树不存在
                    Right[k]=0;
                else
                {
                    if(data[right]=='0')
                        Right[k]=0;
                    else
                    {
                        Get_balance_factor(right);
                        Right[k]=Left[right]>Right[right]? Left[right]+1 : Right[right]+1;
                    }
                }
                
            }
        }
        void PostOrder(int k)
        {
            if(data[k]=='0'||k>=n)
                return;
            int left=2*k+1,right=2*k+2;
            PostOrder(left);
            PostOrder(right);
            cout<<data[k]<<" "<<Left[k]-Right[k]<<endl;
        }
};
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        Tree tree;
        tree.Set_Tree();
        tree.Get_balance_factor(0);
        tree.PostOrder(0);
    }
    return 0;
}