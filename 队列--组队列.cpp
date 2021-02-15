#include<iostream>
#include<queue>
#include<map>
#include<string>
using namespace std;
const int maxt=10;
void solve()
{
	int t;
	int n;
	int x;
	int first=1;
	string s;
	map<int ,int> team;//类似于键值对
	queue<int> q[maxt];
	queue<int>Q4team;
	
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n;j++)
		{
			cin>>x;
			team[x]=i;
		}
	}
	
	while(cin>>s&&s!="STOP")
	{
		if(s[0]=='D')
		{
			int num=Q4team.front();
			if(first)
				first=0;
			else 
				cout<<" ";
			cout<<q[num].front();
			q[num].pop();
			if(q[num].empty())
				Q4team.pop();
		}
		else if(s[0]=='E')
		{
			int num;
			cin>>num;
			int group=team[num];
			if(q[group].empty())
				Q4team.push(group);
			q[group].push(num);
		}
		
	}
}
int main()
{
	solve();
	return 0;
}