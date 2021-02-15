#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
#define ok 0
#define ERROR -1
#define OVERFLOW -1
#define OPSETSIZE 7
typedef int Status;

char Prior[7][7]=
{
    ///运算符间的优先关系，分别是+ - * / ( ) #
    ///按行看+ - * / ( ) #
    '>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>',
    '>','>','>','>','<','>','>',
    '<','<','<','<','<','=',' ',
    '>','>','>','>',' ','>','>',
    '<','<','<','<','<',' ',' '
};
float Operate(float a,unsigned char theta,float b)
{
	if(theta=='+')
		return a+b;
	else if(theta=='-')
		return a-b;
	else if(theta=='*')
		return a*b;
	else if(theta=='/')
		return a/b;
	return ERROR;
}
char OPSET[OPSETSIZE]={'+','-','*','/','(',')','#'};
char precede(char Aop,char Bop)
{
    ///获取两个运算符之间的优先级，Aop是栈顶，Bop是下一个运算符
    int i;
    for(i=0;i<OPSETSIZE;i++)
        if(OPSET[i]==Aop)
            break;
    int j;
    for(j=0;j<OPSETSIZE;j++)
        if(OPSET[j]== Bop)
            break;
    return Prior[i][j];
}
int in(char Test,char *p)///1是运算符，0不是运算符
{
    ///判断字符Test是否是运算符
    for(int j=0;j<OPSETSIZE;j++)
    {
        if(Test==p[j])
            return 1;
    }
    return 0;
}

double EvaluateExpression(string MyExp)
{
	stack <char> OPTR;//运算符栈，字符元素
	stack <char> OPND;//运算数栈，实数元素
	char TempData[20];
	double Data,a,b,r;
	char theta,Dr[2];
	char c;
	//stringstream ss;
	int i=0;//用于控制字符窜的移动
	OPTR.push('#');
	c=MyExp[0];
	strcpy(TempData,"\0");
	while(c!='#'||OPTR.top()!='#')
	{
		if(!in(c,OPSET))
		{
			Dr[0]=c;
			Dr[1]='\0';
			strcat(TempData,Dr);
			c=MyExp[++i];
			if(in(c,OPSET))//c为运算符，表明前面读入了一个完整的操作数
			{	
				Data=(double)atof(TempData);//atof()将字符串转化为浮点数
				OPND.push(Data);
				strcpy(TempData,"\0");
			}

		}
		else
		{
			switch(precede(OPTR.top(),c))
			{
				case '<'://栈顶元素优先权低，压入
					OPTR.push(c);
					c=MyExp[++i];
					break;
				case '=':
					OPTR.pop();
					c=MyExp[++i];
					break;
				case '>':
					theta=OPTR.top();
					OPTR.pop();
					b=OPND.top();
					OPND.pop();
					a=OPND.top();
					OPND.pop();
					OPND.push(Operate(a,theta,b));
					break;



			}
		}
	}
	return OPND.top();
}

int main()
{
	string Exp;
	int t;
	double result;
	cin>>t;
	while(t--)
	{
		cin>>Exp;
		result=EvaluateExpression(Exp);
		cout<<fixed<<setprecision(4)<<result<<endl;
	}
	return 0;
}


/*

#include<iostream>
#include<stack>
#include<string>
#include<sstream>
#include<iomanip>
using namespace std;
 
#define ok 0
#define error -1
#define opsetsize 7//运算符集合长度，目前只有7个运算符
 
char Prior[7][7]=
{
    ///运算符间的优先关系，分别是+ - * / ( ) #
    ///按行看+ - * / ( ) #
    '>','>','<','<','<','>','>',
    '>','>','<','<','<','>','>',
    '>','>','>','>','<','>','>',
    '>','>','>','>','<','>','>',
    '<','<','<','<','<','=',' ',
    '>','>','>','>',' ','>','>',
    '<','<','<','<','<',' ',' '
};
 
double Operate(double a,char theta,double b)
{
    if(theta=='+')
        return a+b;
    else if(theta=='-')
        return a-b;
    else if(theta=='*')
        return a*b;
    else if(theta=='/')
        return a/b;
    return error;
}
char opset[opsetsize]={'+', '-', '*', '/', '(', ')','#'};///运算符集合
int in(char Test,char *p)///1是运算符，0不是运算符
{
    ///判断字符Test是否是运算符
    for(int j=0;j<opsetsize;j++)
    {
        if(Test==p[j])
            return 1;
    }
    return 0;
}
char precede(char Aop,char Bop)
{
    ///获取两个运算符之间的优先级，Aop是栈顶，Bop是下一个运算符
    int i;
    for(i=0;i<opsetsize;i++)
        if(opset[i]==Aop)
            break;
    int j;
    for(j=0;j<opsetsize;j++)
        if(opset[j]== Bop)
            break;
    return Prior[i][j];
}
 
double EvaluateExpression(string Myexp)
{
    stack<char>Optr;///运算符栈
    stack<double>Opnd;///操作数栈
    string Tempdata;
    double data;
    char theta;
    char c;
    int i=0;///用于控制字符串的位置移动
    stringstream ss;
    Optr.push('#');///先压入一个#号
    c= Myexp[0];
    while(c!='#'||Optr.top()!='#')
    {
        if(in(c, opset)==0)
        {
            ///判断读入的字符是不是操作数，是则进入
            Tempdata+=c;
            c=Myexp[++i];///读取下一个字符
            if(in(c, opset)!=0)
            {
                ///如果c是运算符，表明前面读入了一个完整的操作数
                ss.clear();
                if(Tempdata.size()!=0)
                {
                    ss<<Tempdata;
                    ss>>data;
                    Opnd.push(data);
                    Tempdata.clear();
                }
            }
        }
        else
        {
            ///是运算符，开始计算
            switch(precede(Optr.top(),c))
            {
                case'<':///栈顶的优先级低，即Op1<Op2，不进行计算，压入新的运算符
                    Optr.push(c);
                    c= Myexp[++i];
                    break;
                case'=':///脱括号和脱#号
                    Optr.pop();
                    c=Myexp[++i];
                    break;
                case'>':///退栈并将计算结果入栈
                    double b=Opnd.top();///第一个弹出右操作数
                    Opnd.pop();
                    double a=Opnd.top();///第二个弹出左操作数
                    Opnd.pop();
                    theta=Optr.top();
                    Optr.pop();
                    Opnd.push(Operate(a,theta,b));
                    break;
            }
        }
    }
    return Opnd.top();
}
int main()
{
    string exp;
    int T;
    cin>>T;
    while(T--)
    {
        cin>>exp;
        exp+="#";
        double result=EvaluateExpression(exp);
        cout<<fixed<<setprecision(4)<<result<<endl;
    }
    return 0;
}*/