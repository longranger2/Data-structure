#include<iostream>
#include<queue>
using namespace std;
const int maxlen = 20;
class MAP
{
    private:
        int maxtrix[maxlen][maxlen];
        int vexnum;
        int *visit;
        void map(int start)
        {//广度优先遍历
            queue<int > que;
            que.push(start);
            while(!que.empty())
            {
                int st= que.front();
                que.pop();
                visit[st]= 1;
                cout<<st<<' ';
                for(int i= 0;i< vexnum; i++)
                {
                    if(maxtrix[st][i]&&!visit[i])
                    {
                        visit[i]= 1;//这里得改变i已被遍历，否则将会重复遍历
                        que.push(i);
                    }
                }
            }
        }
    public :
        void setMx(int mx[maxlen][maxlen], int vnum)
        {
            vexnum= vnum;
            visit= new int[vnum+ 5];
            for(int i= 0; i< vexnum ;i++)
                visit[i]= 0;
            for(int i= 0; i< vexnum; i++)
            {
                for(int j= 0; j< vexnum; j++)
                  maxtrix[i][j]= mx[i][j];
            }
        }
        void map()
        {
            map(0);
            cout<<endl;
        }
};
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int mx[maxlen][maxlen];
        for(int i= 0; i< n; i++)
          for(int j= 0; j< n; j++)
            cin>>mx[i][j];
        MAP test;
        test.setMx(mx, n);
        test.map();
    }
    return 0;
}