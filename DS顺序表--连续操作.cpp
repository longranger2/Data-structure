#include <iostream>
using namespace std;
class SeqList{
    int *list;
    int len;
    int maxLen;
public:
    SeqList(int n);
    ~SeqList();
    void multiInsert(int i, int n, int *item);
    void multiDel(int i, int n);
    void outPut();
};

SeqList::SeqList(int n) 
{
    maxLen = 1000;
    len = n;
    list = new int[maxLen];
    for(int i=0;i<n;i++)
        cin>>list[i];
}

SeqList::~SeqList() {
    delete []list;
}

void SeqList::multiInsert(int i, int n, int *item) 
{
    if(len+n>maxLen || i<1 || i>len+1)
        return;
    for(int j=len-1;j>=i-1;j--)
        list[j+n] = list[j];
    for(int j=i-1;j<i-1+n;j++)
        list[j] = item[j-i+1];
    len += n;
}
void SeqList::multiDel(int i, int n) {
    if(i<1 || i>len || i+n-1>len)
        return;
    for(int j=i-1+n;j<len;j++)
        list[j-n] = list[j];
    len -= n;
}
void SeqList::outPut() {
    cout<<len<<' ';
    for(int i=0;i<len;i++)
        cout<<list[i]<<' ';
    cout<<endl;
}

int main()
{
    int n;
    cin>>n;
    SeqList myList(n);
    myList.outPut();
    int i,*item;
    cin>>i>>n;
    item = new int[n];
    for(int j=0;j<n;j++)
        cin>>item[j];
    myList.multiInsert(i,n,item);
    myList.outPut();
    delete []item;
    cin>>i>>n;
    myList.multiDel(i,n);
    myList.outPut();

    return 0;
}
