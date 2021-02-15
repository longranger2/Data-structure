#include<iostream>
#include<math.h>
using namespace std;
int H(int key)
{
	return key%11;
}
void Judge(int final[],int num,int m)
{
	int flag=0,pos,d,coef,t;
	int count=0,key,temp_key;
	key=num%11;	//映射的值
	temp_key=key;
	count=0;//记录查找次数
	d=1; //记录偏移量
	coef=1; //变号
	t=0;  //偏移次数
	while(1)
    {
    	count++;
        if(final[temp_key]==num)
        {
        	flag=1;
	    	pos=temp_key+1;
			break;
        } 
        else 
        {   
            if(final[temp_key]==-1)
        	{
        		break;
        	}
        	t++;                            
            temp_key=key+coef*(d*d);    //更新key
            coef*=-1;                //更新符号
            if(count%2==0)            //每2次需要更新1次偏移量
                d++;
            if(temp_key>m)            //key超过hash表长度
            	temp_key -= m;
            else if(temp_key <0)      //key的值为负数
                temp_key += m;
            if(t>m/2)
            {
        		break;
            }
        }
        
    }
	if(flag==1)
		cout<<1<<" "<<count<<" "<<pos<<endl;
	else 
		cout<<0<<" "<<count<<endl;
}

void Hash(int a[],int m,int n)//m为表长 , n为关键字个数
{
	int final[m],d,coef,num;
	for(int i=0;i<m;i++)
	{
		final[i]=-1;
	}
	
	int value,key,temp_key;
	for(int i=0;i<n;i++)
	{
		value=a[i];
		key=value%11;	//映射的值
		temp_key=key;
		num=0;//计数
		d=1;//偏移量
		coef=1;
		while(1)
        {
            if(final[temp_key]==-1)
            {
                final[temp_key]=value;
				break;
            }
            else
            {                                    //滚动取key
                num++;
                temp_key=key+coef*(d*d);    //更新key
                coef*=-1;                //更新符号
                if(num%2==0)            //每2次需要更新1次偏移量
                    d++;
                if(temp_key>m)            //key超过hash表长度
                    temp_key -= m;
                else if(temp_key <0)      //key的值为负数
                    temp_key += m;
            }
        }
	}
	for(int i=0;i<m;i++)
	{
		if(i!=m-1)
		{
			if(final[i]!=-1)
				cout<<final[i]<<" ";
			else
				cout<<"NULL"<<" ";
		}
		else
		{
			{
			if(final[i]!=-1)
				cout<<final[i]<<endl;
			else
				cout<<"NULL"<<endl;
		}
		}
	}
	int time,number;
	cin>>time;
	while(time--)
	{
		cin>>number;
		Judge(final,number,m);
	}
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int m,n;
		cin>>m>>n;
		int shuzu[n];
		for(int i=0;i<n;i++)
			cin>>shuzu[i];
		Hash(shuzu,m,n);
	}
	return 0;
}