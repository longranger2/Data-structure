#include<iostream>
using namespace std;

const int MaxLen = 20;

class Map {
	private:
		bool Visit[MaxLen];
		int Matrix[MaxLen][MaxLen];
		int Vexnum;
		void DFS(int v);
	public:
		void SetMatrix(int vnum,int mx[MaxLen][MaxLen]);
		void DFSTraverse();
};

void Map::SetMatrix(int vnum,int mx[MaxLen][MaxLen]) {
	Vexnum = vnum;
	for(int i = 0; i < MaxLen; i++) {
		for(int j = 0; j < MaxLen; j++) {
			Matrix[i][j] = 0;
		}
	}
	for(int i = 0; i < Vexnum; i++) {
		for(int j = 0; j < Vexnum; j++) {
			Matrix[i][j] = mx[i][j];
		}
	}
}

void Map::DFSTraverse() {
	int v = 0;
	for(int i = 0; i < Vexnum; i++)
		Visit[i] = 0;
	for(v = 0; v < Vexnum; v++) {
		if(Visit[v] == 0) {
			DFS(v);
		}
	}
	cout<<endl;
}

void Map::DFS(int v) {
	int w, i ,k;
	Visit[v] = 1;
	cout<<v<<" ";

	int *AdjVex = new int [Vexnum];
	for(int i = 0; i < Vexnum; i++) {
		AdjVex[i] = -1;
	}
	k = 0;
	for(int i = 0; i < Vexnum; i++) {
		if(Matrix[v][i] == 1) {
			AdjVex[k++] = i;
		}
	}
	i = 0;
	w = AdjVex[i];
	while(w != -1) {	
		if(!Visit[w]) {
			DFS(w);
		}
		w = AdjVex[++i];
	}
	delete []AdjVex;
}


int main() {
	int t,n,map[MaxLen][MaxLen];
	cin>>t;
	while(t--) {
		cin>>n;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
			cin>>map[i][j];
		}
		}
		Map m;
		m.SetMatrix(n, map);
		m.DFSTraverse();
	}

}
/*
#include <iostream>
using namespace std;
const int Maxlen=20;

class Map
{
private:
	bool Visit[Maxlen];  //访问标志数组
	int Matrix[Maxlen][Maxlen];  //图的领接矩阵
	int Vexnum;  //图顶点数量
	void DFS(int v);   //深度优先
public:
	void SetMatrix(int vnum,int mx[Maxlen][Maxlen]);
	void DFSTraverse();
};
void Map::SetMatrix(int vnum,int mx[Maxlen][Maxlen])
{
	int i,j;
	Vexnum=vnum;   //设置图的结点数量
	for(i=0;i<Maxlen;i++) //领接矩阵初始化为0
	{
		for(j=0;j<Maxlen;j++)
			Matrix[i][j]=0;
	}
	for(i=0;i<Vexnum;i++)//领接矩阵初始化
		for(j=0;j<Vexnum;j++)
			Matrix[i][j]=mx[i][j];
}
void Map::DFSTraverse()
{
	int v;
	for(v=0;v<Vexnum;v++)
		Visit[v]=false;
	for(v=0;v<Vexnum;v++)
		if(Visit[v]!=true)
			DFS(v);
	cout<<endl;
}
void Map::DFS(int v)
{
	int w,i,k;
	Visit[v]=true;
	cout<<Visit[v]<<" ";
	//找出与v相连接的其他所有顶点，存放在AdjVex数组中
	int *AdjVex=new int [Vexnum];//存放v相连接的顶点
	for(i=0;i<Vexnum;i++)
		AdjVex[i]=-1;

	k=0;//k事数组AdjVex的空位置下⌚标，初始为0表示数组AdJVex一开始没有数组
	for(i=0;i<Vexnum;i++)
		if(Matrix[v][i]==1)
			AdjVex[k++]=i;
	i=0;
	w=AdjVex[i];
	while(w!=-1)
	{
		if(!Visit[w])
			DFS(w);
		w=AdjVex[++i];
	}
	delete []AdjVex;
}

int main()
{
	int t,n,map[Maxlen][Maxlen];
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>map[i][j];
		Map m;
		m.SetMatrix(n,map);
		m.DFSTraverse();
	}
	return 0;
}
*/