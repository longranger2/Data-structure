#include<iostream>
#include<cstring>
using namespace std;
int n;
void copy(string* &str, string* &st)
{ //实时更换str字符串中的内容
     for(int i= 1; i<= n; i++)
       str[i]= st[i];
}
void Merge(string* &str, string* &st, int m, int nn, int gap)
{//合并两个区间
    int k;
    int i, j;
    for(i= m,j= nn, k= m; i< m+ gap&&j< nn+ gap&&j<= n; k++)
    {
        if(str[i]> str[j])
          st[k]= str[i++];
        else
           st[k]= str[j++]; 
    }
    while(i< m+ gap) 
      st[k++]= str[i++];
    while(j< nn+ gap&&j<= n)
      st[k++]= str[j++];
    copy(str, st);//将str和st赋值为一样的
}

void print(string* &st)
{//输出
        for(int i= 1; i<= n; i++)
        {
            cout<<st[i];
            if(i!= n)
              cout<<' ';
            else
              cout<<endl;
        }   
}
void Msort(string* &str, string* &st){//归并排序
     
    int gap= 1;//每个区间的长度
    int num= n;//区间的个数
    int i;//要合并的第一个区间开头
    int j;//要合并的第二个区间的开头
    while(num>1)
    {//在组数小于1时退出循环
        i= 1;//数组从1开始
        j= gap+ 1;
        while(j<= n)
        {
            Merge(str, st, i, j, gap);
            num--;
            i+= gap* 2;//每次跳两个组的间距
            j+= gap* 2;     
        }
        gap= gap* 2;
        print(st);
    } 
}
int main(){
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        string* str= new string[n+ 5];
        string* st= new string[n+ 5];
        for(int i= 1; i<= n; i++)//从第一个位置开始存放
        {
            cin>>str[i];
            st[i]= str[i];
        }
            
        Msort(str, st);
        cout<<endl;
        delete []str;
        delete []st;
    }
    return 0;
}
