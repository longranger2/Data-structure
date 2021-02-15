#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;
struct Node{
	char date;
	struct Node *next[26];    //next指针有26个，代表26个字母
};
class Tire{
private:
    struct Node *m;
public:
    Tire(){};
    ~Tire(){};
    void test();
    int get_num(struct Node *t);
    void level_print(struct Node *t);
};
void Tire::level_print(struct Node *t)    //层序遍历输出结果,t默认取树根
{
    queue<struct Node*> q1;            //设置一个队列，先将根结点不空的孩子加进来
    for(int i = 0; i < 26; i++)
    {
        if(t[i].date != '0')
        {
            q1.push(&t[i]);
        }
    }
    while(!q1.empty())            //在队列不空的情况下，每次输出结点对应的字符，然后将结点的孩子中不空的结点加到队列中
    {
        struct Node *t = q1.front();
        q1.pop();
        cout<<t->date;
        for(int i = 0; i < 26; i++)
        {
            if(t->next[i] != NULL)
            {
                q1.push(t->next[i]);
            }
        }
    }
    cout<<endl;
}
int Tire::get_num(struct Node *t)    //获取该结点的子树的个数，需要递归实现
{
    int coun=0;
    for(int i=0;i<26;i++)
    {
        if(t->next[i] != NULL)          //如果孩子结点不空，则计算此孩子结点的子树个数，加到父结点的子树个数中去
        {
            coun += get_num(t->next[i]);
        }
    }
    if(coun == 0)        //若最后的计算结果显示所有孩子结点都是空，证明只含有父结点这棵树，长度就是1
        return 1;
    else
        return coun;
}
void Tire::test()
{
    m = new Node[26];
    for(int i=0; i<26; i++)        //初始化结构体
    {
        m[i].date='0';
        for(int j=0;j<26;j++)
            m[i].next[j]=NULL;
    }
    char str[1024];
    int num=0;
    while((str[num] = getchar()) != '\n')    //读入第一行输入的所有单词
        num++;
    for(int i=0;i<num;i++)
    {
        string t;                    //对单词进行分割，每次分割出来的单词存在t中
        while(str[i] != ' ' && i<num)
        {
            t+=str[i];
            i++;
        }
        struct Node *father = &m[t[0]-'a'];        //设置父结点指针，方便单词加到字典树中
        father->date = t[0];
        for(int j = 1; j < t.length(); j++)
        {
            if(father->next[t[j]-'a'] != NULL)    //如果单词的第i个字母已经存在字典树中，则父节点继续往下，如果不存在，则生成新的结点加入到字典树中去
            {
                father=father->next[t[j]-'a'];
                continue;
            }
            struct Node* temp = new Node;
            temp -> date = t[j];
            for(int k = 0; k < 26; k++)
                temp->next[k] = NULL;
            father->next[t[j]-'a'] = temp;
            father = father->next[t[j]-'a'];
        }
    }
    level_print(m);        //层序遍历字典树输出结果
    int n;                //输入要检测的前缀的个数
    cin>>n;
    string temp;
    for(int i=0;i<n;i++)
    {
        cin>>temp;        //输入前缀
        struct Node *father = &m[temp[0]-'a'];
        for(int j=1;j<temp.length();j++)            //father指针取前缀的最后一个字母在树中的位置，如果不存在，则father指针为空
        {
            father = father->next[temp[j]-'a'];
            if(father == NULL)
                break;
        }
        if(father==NULL)            //若father指针为空，则前缀不存在字典树中，输出0
            cout<<0<<endl;
        else                        //若father指针不为空，则调用计算子树个树函数，输出father指针的子树的个数，此个数即为具有此公共前缀的单词的个数
        {
            int coun = get_num(father);
            cout<<coun<<endl;
        }
    }
 
 
}
int main()
{
    Tire t;
    t.test();
	return 0;
}