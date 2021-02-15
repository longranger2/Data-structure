#include<iostream>
using namespace std;
#define INF 0x3f3f
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        next=NULL;
    }
    Node(int n,Node *x)
    {
        data=n;
        next=x;
    }
};
int Find(Node Hash[15],Node *ptr[15],int h)
{
    int tag=0;
    int times=1;
    if(Hash[h%11].data==h)
    {
        tag=1;
        cout<<h%11<<" "<<times<<endl;
    }
    else
    {
        Node *p=&Hash[h%11];
        p=p->next;
        while(true)
        {
            times++;
            if(p==NULL)
                break;
            else
            {
                if(p->data==h)
                {
                    tag=1;
                    break;
                }
            }
            p=p->next;
        }
        if(tag==1)
                cout<<h%11<<" "<<times<<endl;
        else
            cout<<"error"<<endl;
    }
    return tag;
}
 
 
int main()
{
    int n;
    cin>>n;
    Node Hash[15];//在hash存储首次出现的数字
    Node *ptr[15];
    for(int i=0;i<15;i++)
    {
        Hash[i].data=INF;
    }
    for(int i=0;i<n;i++)
    {
        int num;
        cin>>num;
        if(Hash[num%11].data==INF)
        {
            Hash[num%11].data=num;
            ptr[num%11]=&Hash[num%11];
        }
        else
        {
            Node *p=new Node();
            p->data=num;
            p->next=NULL;
            ptr[num%11]->next=p;
            ptr[num%11]=p;
        }
    }
    int t;
    cin>>t;
    while(t--)
    {
        int h;
        cin>>h;
        if(Find(Hash,ptr,h)==0)//没找到，将数字加入进去
        {
            if(Hash[h%11].data==INF)
            {
                Hash[h%11].data=h;
                ptr[h%11]=&Hash[h%11];
            }
            else
            {
                Node *p=new Node();
                p->data=h;
                p->next=NULL;
                ptr[h%11]->next=p;
                ptr[h%11]=p;//prt是用来存放上个结点的地址的
            }
        }
    }
    return 0;
}