#include <iostream>
#include <string.h>
using namespace std;
class ListNode
{
	public:
		char data;
		ListNode *next;
		ListNode *before;
		ListNode(char n,ListNode *p,ListNode *q)
		{
			data=n;
			next=p;
			before=q;
		}
		ListNode()
		{
			next=NULL;
			before=NULL;
		}

};
class LinkList
{
	public:
		ListNode *head;
		int len;
		LinkList()
		{
			head=NULL;
			len=0;
		}
		void create(char *num,int n)
		{
			ListNode *tail;
			ListNode *s;
			head=new ListNode;
			tail=head;
			for(int i=0;i<n;i++)
			{
				s=new ListNode(num[i],NULL,tail);
				tail->next=s;
				tail=s;
				len++;
			}
		}
		ListNode *indexfind(int i)
		{
			if(i<0)
				return NULL;
			ListNode *p=head;
			int k=1;
			while(k<=i&&p!=NULL)
			{
				p=p->next;
				k++;
			}
			if(p==NULL)
				return NULL;
			else
				return p;
		}
		void Insert(int i,char c)
		{
			len++;
			if(len==1)
			{
				ListNode *temp=new ListNode(c,NULL,head);
				head->next=temp;
				return ;
			}
			ListNode *p=indexfind(i);
			ListNode *beforeI=indexfind(i-1);
			ListNode *temp=new ListNode(c,p,beforeI);
			beforeI->next=temp;
			p->before=temp;
		}
		void Delete(int i)
		{
			len--;
			ListNode *beforeI=indexfind(i-1);
			ListNode *p=indexfind(i);
			//ListNde *temp=p;
			beforeI->next=p->next;
			if(p->next!=NULL)
				p->next->before=beforeI;
			delete p;
		}
		int Start()
		{
			ListNode *p=head->next;
			int index=1;
			while(p!=NULL)
			{
				int count=1;
				ListNode *cur=p->next;
				while(cur!=NULL&&p->data==cur->data)
				{
					count++;
					cur=cur->next;
				}
				if(count>=3)
				{
					for(int i=index,j=0;j<count;j++)
						Delete(i);
					return 0;
				}
				index++;
				p=p->next;
			}
			return -1;
		}
		void Display()
		{
			ListNode *p=head->next;
			if(p==NULL)
			{
				cout<<"-"<<endl;
				return ;
			}
			while(p!=NULL)
			{
				cout<<p->data;
				p=p->next;
			}
			cout<<endl;
		}

};
int main()
{
	char str[1000];
	cin>>str;
	int n;
	cin>>n;
	int len=strlen(str);
	LinkList L;
	L.create(str,len);
	while(n--)
	{
		int index;
        char ch;
        cin>>index>>ch;
        L.Insert(index+1,ch);
        while(1)
        {
            if(L.Start()!=0)
                break;
        }
        L.Display();
	}
	return 0;
}