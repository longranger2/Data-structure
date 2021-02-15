#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
 
void test()
{
    int t1,t2;
    cin>>t1>>t2;
    int *n1,*n2,*n3,*n4,*n5;
    n1=new int[t1];    //存年
    n2=new int[t1];    //存月
    n3=new int[t1];    //存日
    n4=new int[t1];    //存第一个数
    n5=new int[t1];    //存第二个数
    string *s1,*s2;
    s1=new string[t1];    //存年月日字符串
    s2=new string[t1];    //存状态字符串
 
    int a1,a2;
    for(int i=0;i<t1;i++)
    {
        cin>>s1[i]>>s2[i]>>n4[i]>>n5[i];    //s1为日期，s2为状态，n4和n5为值
        string temp = s1[i].substr(0,4);    //将年月日转为int型存到n1,n2,n3数组中，由于后台数据只有日期是不同的，所以只需要将日期存到n3数组就行，n1和n2暂时用不到
        stringstream sss;//substr(pos,n)用法：第一个参数是开始位置，第二个参数是获取子串的长度
        temp = s1[i].substr(7,9);
        sss<<temp;//stingstream可以用来类型转化
        sss>>n3[i];
    }
    for(int i=0;i<t1;i++)
    {
        for(int j=0;j < t1-i-1;j++)
        {
            if(n3[j]>n3[j+1])    //按日期n3进行冒泡排序，排序时除了要交换n3，还需要交换状态s2，还有数值n4和n5
            {
                swap(n3[j],n3[j+1]);
                swap(s1[j],s1[j+1]);
                swap(s2[j],s2[j+1]);
                swap(n4[j],n4[j+1]);
                swap(n5[j],n5[j+1]);
            }
        }
    }
//    cout<<endl;
//    for(int i=0;i<t1;i++)
//        cout<<s1[i]<<' '<<s2[i]<<' '<<n4[i]<<' '<<n5[i]<<endl;
//    cout<<endl;
    int coun,sum1,sum2;
    for(int i = 1; i < t1; i++)        //按日期从小到大先将open状态的平均值输出
    {
        sum1 = n4[i], sum2 = n5[i];
        coun = 0;
        if(s2[i]=="close")
            continue;
        for(int j = i-1; j >= 0; j--)
        {
            if(s2[j] == "open")
            {
                coun++;
                sum1 += n4[j];
                sum2 += n5[j];
            }
            if(coun == t2-1)
                break;
        }
        if(coun == t2-1)
        {
            cout<<s1[i]<<' '<<s2[i]<<' '<<sum1/t2<<' '<<sum2/t2<<endl;
        }
    }
    for(int i = 1; i < t1; i++)       //按日期从小到大再将close状态的平均值输出
    {
        sum1 = n4[i], sum2 = n5[i];
        coun = 0;
        if(s2[i]=="open")
            continue;
        for(int j = i-1; j >= 0; j--)
        {
            if(s2[j] == "close")
            {
                coun++;
                sum1 += n4[j];
                sum2 += n5[j];
            }
            if(coun == t2-1)
                break;
        }
        if(coun == t2-1)
        {
            cout<<s1[i]<<' '<<s2[i]<<' '<<sum1/t2<<' '<<sum2/t2<<endl;
        }
    }
}
int main()
{
    test();
	return 0;
}
