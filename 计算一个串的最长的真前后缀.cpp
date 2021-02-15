/*#include <iostream>
#include <string>
using namespace std;

int* GetNext (string str)
{
	int j=0,k=-1;
	int len=(int)str.size();
	int *next=new int[len+1];
	next[j]=k;
	while(j<=len)
	{
		if(k==-1||str[j]==str[k])
			next[++j]=++k;
		else
			k=next[k];
	}
	return next;
}
string matched_Prefix_Postfix(string str)
{
	int *next=GetNext(str);
	int len=(int)str.size();
	int flag=next[len];
	delete []next;
	if(flag<=0) 
		return "empty";
	else 
		return str.substr(0,flag);
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<matched_Prefix_Postfix(s)<<endl;
	}
}
*/
#include <iostream>
#include <string>
#include <cstring>
#define rep(i, n) for ( int i = (n); i >= 1; i-- )
using namespace std;
const int maxn = 1e3 + 5;
string s1[maxn], s2[maxn];//字符串数组
 
void GetPrefixSuffix (string str)//截取好存在s1,s2数组中
{
	int len = (int)str.size();
	rep(i, len - 1) //前(后)缀的最长长度是字符串长度减 1，前(后)缀的最短长度是 1 
	{
		s1[i] = str.substr(0, i);  //得到前缀的字符串数组 
		s2[i] = str.substr(len - i, i);  //得到后缀的字符串数组 
		cout << "test: " << s1[i] << " "<< s2[i] << endl;
	}
	// 按照我对 rep 循环的定义，2个字符串数组，都是先截取较长的子串 
}
 
string matched_Prefix_Postfix(string str)
{
	int len = (int)str.size();
	GetPrefixSuffix(str);
	rep(i, len - 1)
	{
		if (s1[i] == s2[i]) return s1[i];
	}
	return "empty";
}
 
int main ()
{
	int t;
	string str;
	cin >> t;
	while (t--)
	{
		cin >> str;
		cout << matched_Prefix_Postfix(str) << endl;
	}
	return 0;
}