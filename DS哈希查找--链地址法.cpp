#include<iostream>
using namespace std;
#define INF 0x3f3f
class Node 
{
    public:
        int data;
        Node *next;
        Node(int n) 
        {
            data = n;
            next = NULL;
        }
        Node() 
        {
            data = 0;
            next = NULL;
        }
        Node* insert(int n) 
        { //表头插入
            Node *p = new Node(n);
            p->next = this;
            return p;
        }
        int search(int find) 
        {
            Node *p = this;
            int time = 0;
            while(p) 
            {
                time++; //记录查找次数
                if(p->data == find) 
                {
                    return time;
                }
                p = p->next;
            }
            return -1; //查找未成功
        }
        ~Node() 
        {
            Node *p = this;
            Node *q;
            while(p) 
            {
                q = p->next;
                delete p;
                p = q;
            }
        }
};
class HashTable 
{
    private:
        Node **root;
        int size;
    public:
        HashTable(int s) 
        {
            size = s;
            root = new Node*[size];
            for(int i; i < size; i++) 
            {
                root[i] = new Node(0);
            }
        }
        int Hash(int n) 
        {
            return n % 11;
        }
        void insert(int n) 
        {
            int hash = Hash(n);
            root[hash] = root[hash]->insert(n);
        }
        void search(int find) 
        {
            int hash = Hash(find);
            if(root[hash]->search(find) > -1) 
                cout<<hash<<" "<<root[hash]->search(find)<<"\n";
            else 
            {
                cout<<"error\n";
                insert(find);
            }
            return ;
        }
        ~HashTable() {
            delete []root;
        }
};
int main() 
{
    int n;
    HashTable h(11);
    cin>>n;
    while(n--) 
    {
        int data;
        cin>>data;
        h.insert(data);
    }
    int t;
    cin>>t;
    while(t--) 
    {
        int find;
        cin>>find;
        h.search(find);
    }
    return 0;
}
