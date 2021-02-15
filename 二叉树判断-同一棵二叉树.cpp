#include<iostream>
#include<string>
using namespace std;
void Firstorder(string &s,string cs,int n,int i=0)//s用来存储cs先序遍历的结果
{
    if(i>=n)
        s+='#';
    else if(cs[i]=='#')
        s+='#';
    else
    {
        s+=cs[i];
        Firstorder(s,cs,n,2*i+1); 
        Firstorder(s,cs,n,2*i+2);
    }
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string cs,cs1;
        string s="";
        int i=0;
        cin>>cs>>cs1;
        int n=cs.length();
        Firstorder(s,cs,cs.length(),i);
        if(s==cs1)
            cout<<"YES\n";
        else
        {
            cs1+="##";
            if(s==cs1)
                cout<<"YES\n";
            else
            cout<<"NO\n";
        }
    }
    return 0;
}


