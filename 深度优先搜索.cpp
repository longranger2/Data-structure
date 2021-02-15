#include<iostream>
using namespace std;
const int MaxLen = 20;
class Map 
{
	private:
		bool Visit[MaxLen];
		int Matrix[MaxLen][MaxLen];
		int Vexnum;
		void DFS(int v);
	public:
		void SetMatrix(int vnum,int mx[MaxLen][MaxLen]);
		void DFSTraverse();
};
void Map::SetMatrix(int vnum,int mx[MaxLen][MaxLen]) 
{
	Vexnum = vnum;
	for(int i = 0; i < MaxLen; i++) 
		for(int j = 0; j < MaxLen; j++) 
			Matrix[i][j] = 0;
	for(int i = 0; i < Vexnum; i++) 
		for(int j = 0; j < Vexnum; j++) 
			Matrix[i][j] = mx[i][j];
}
void Map::DFSTraverse() 
{
	int v = 0;
	for(int i = 0; i < Vexnum; i++)
		Visit[i] = 0;
	for(v = 0; v < Vexnum; v++) 
	{
		if(Visit[v] == 0) 
			DFS(v);
	}
	cout<<endl;
}
void Map::DFS(int v) 
{
	int w, i ,k;
	Visit[v] = 1;
	cout<<v<<" ";
	int *AdjVex = new int [Vexnum];
	for(int i = 0; i < Vexnum; i++) 
		AdjVex[i] = -1;//存放与v相邻的点
	k = 0;
	for(int i = 0; i < Vexnum; i++) 
	{
		if(Matrix[v][i] == 1) 
			AdjVex[k++] = i;
	}
	i = 0;
	w = AdjVex[i];
	while(w != -1) //对相邻的点进行遍历
	{	
		if(!Visit[w]) 
		{
			DFS(w);//若顶点w尚未访问，对w调用DFS函数进行遍历
		}
		w = AdjVex[++i];
	}
	delete []AdjVex;
}
int main() 
{
	int t,n,map[MaxLen][MaxLen];
	cin>>t;
	while(t--) 
	{
		cin>>n;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				cin>>map[i][j];
		Map m;
		m.SetMatrix(n, map);
		m.DFSTraverse();
	}

}