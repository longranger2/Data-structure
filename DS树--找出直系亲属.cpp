/*#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

const int maxn=27;
int son[maxn];

void Initial()
{
  for(int i=0;i<maxn;i++)
  {
    son[i]=0;
  }
}
bool isparent(int x,int y,int & num)
{
  if(son[x]==0)return false;
  if(son[x]!=y)
     return isparent(son[x],y,++num);
      else
      {
        return true;
      }
      
}
int main ()
{
  int n,m;
  while(scanf("%d%d",&n,&m)!=EOF)
  {
    getchar();
    string str;
    for(int i=0;i<n;i++)
    {
      getline(cin,str);
      int x=str[0]-'A'+1;
      int y=str[1]-'A'+1;
      int z=str[2]-'A'+1;
      son[y]=x;
      son[z]=x;
    }
  for(int i=0;i<m;i++)
  {
    getline(cin,str);
    int x=str[0]-'A'+1;
      int y=str[1]-'A'+1;
      int num=1;
      int num2=1;
      if(isparent(x,y,num))
      {
        if(num==1)
        printf("parent\n");
        else if(num==2)
        printf("grandparent\n");
        else
        {
          while(num-->2)
          {
            printf("great-");
          }
          printf("grandparent\n");
        }
        
      }
      else if(isparent(y,x,num2))
      {
        if(num2==1)
        printf("son\n");
        else if(num2==2)
        printf("grandson\n");
        else
        {
          while(num2-->2)
          {
            printf("great-");
          }
          printf("grandson\n");
        }
        
      }else
      {
        printf("-\n");
      }
      
  }
  }
  return 0;
}
*/

#include <iostream>
#include <map>
#define N 26
using namespace std;
struct Node{//二叉树节点    
    int p1;//第一个双亲的下标，-1表示不存在 
    int p2;//第二个双亲的下标，-1表示不存在
}tree[N];//顺序存储，下标就是它所代表的字符编号，比如0代表'A' 
int preOrder(int from, int to, int depth){//从from出发先序遍历到找到to为止，并返回to相对于from的深度   
    if(from==to)
        return depth; 
    if(tree[from].p1!=-1)   p1，p2是双亲
    { 
        int ret=preOrder(tree[from].p1, to, depth+1);    
        if(ret!=-1) 
            return ret;
    }
    if(tree[from].p2!=-1)
    {
        int ret=preOrder(tree[from].p2, to, depth+1);   
        if(ret!=-1) 
            return ret;    
    }
    return -1;
}
int main(){ 
    int n, m;  
    while(scanf("%d %d", &n, &m)!=EOF)    
    {    
        for(int i=0; i<N; i++)    //初始化
        {
            tree[i].p1=tree[i].p2=-1;
        }    
        while(n--)//构建树     
        {   
            char str[4];     
            scanf("%s", str);         
            if(str[1]!='-') 
                tree[str[0]-'A'].p1=str[1]-'A';  
            if(str[2]!='-')
                tree[str[0]-'A'].p2=str[2]-'A';        
        }  
        while(m--)//查询        
        {  
            char str[3];  
            scanf("%s", str);
            int from=str[0]-'A';        
            int to=str[1]-'A';      
            int ans1=preOrder(from, to, 0);     
            if(ans1==1)
                printf("child\n");       
            else if(ans1>=2){        
                for(int i=ans1; i>2; i--) 
                    printf("great-");        
                printf("grandchild\n");       
            }       
            else//看来不是晚辈，那就是长辈了     
            {    
                int ans2=preOrder(to, from, 0);     
                if(ans2==1)
                    printf("parent\n");   
                else if(ans2>=2)     
                {   
                    for(int i=ans2; i>2; i--) 
                        printf("great-");         
                    printf("grandparent\n");   
                }     
                else
                    printf("-\n");//也不是长辈，那就不是直系亲属        
            }  
        }
    } 
    return 0;//大功告成
}
