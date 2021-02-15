/*#include<iostream>
using namespace std;

class Graph {
	private:
		int **mat;
		int n;
		char **vertex; //顶点名字
		int du[20][2]; //当图是有向图时，du[1][0]=顶点1的出度
		//du[1][1]= 入度
		char type;
	public:
		Graph(int input_n,char t) {
			n = input_n;
			for(int i=0;i<20;i++)
				for(int j=0;j<2;j++)
					du[i][j] = 0;
			for(int i = 0; i < 20; i++){
				for(int j = 0; j < 2; j++){
				du[i][j]=0;
			}
			}
			type = t;
			mat = new int *[n];
			vertex = new char *[n];
			for (int i = 0; i < n; i++) {
				vertex[i] = new char[10];
				mat[i] = new int[n];
				for(int j = 0; j < n; j++) {
					mat[i][j] = 0;
				}
				for(int j = 0; j < 10; j++) {
					vertex[i][j] = 0;
				}

			}
			for(int i = 0; i < n; i++) {
				cin>>vertex[i];
			}
			int side; //边数
			cin >> side;
			while(side--) {
				if(type == 'U')
					u_insert();
				else
					d_insert();
			}
		}
		~Graph() {
			for (int i = 0; i< n; ++i) {
				delete[] mat[i];
				delete[] vertex[i];
			}
			delete[] mat;
			delete[] vertex;
		}
		int find(char *a) {
			for(int i = 0; i < n; i++) {
				int flag = 1;
				for(int j = 0; j < 10; j++) {
					if(vertex[i][j] != a[j]) {
						flag = 0;
						break;
					}
				}
				if(flag == 1) {
					return i;
				}
			}
		}

		void d_insert() {
			char a[10] = {0}, b[10] = {0};
			cin>>a>>b;
			int x = find(a), y = find(b); //找到目标数组下标
			mat[x][y] = 1;
			du[x][0]++; //x的出度+1
			du[y][1]++; //y的入度+1
		}
		void u_insert() {
			char a[10] = {0}, b[10] = {0};
			cin>>a>>b;
			int x = find(a), y = find(b); //找到目标数组下标
			mat[x][y] = 1;
			mat[y][x] = 1;
			du[x][0]++;
			du[y][0]++;
		}
		void output() {
			for (int i = 0; i < n; ++i) {
				for(int j = 0; j < n; j++) {
					cout<<mat[i][j]<<" ";
				}
				cout<<endl;
			}

			for(int i = 0; i < n; i++) {
				cout<<vertex[i];
				if(type == 'D') {
					if(du[i][0]||du[i][1])
					cout<<": "<<du[i][0]<<" "<<du[i][1]<<" "<<du[i][0] + du[i][1];
				} else {
					if(du[i][0])
					cout<<": "<<du[i][0]<<" ";
				}
				cout<<endl;
			}
		}

};


int main() {
	int t,num;
	char type;
	cin>>t;
	while(t--) {
		cin>>type>>num;
		Graph g(num,type);
		g.output();
	}
	return 0;
}
*/

#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		char type;
		int n,ln;
		cin>>type>>n;
		string *p=new string[n];
		for(int i=0;i<n;i++)
			cin>>p[i];
		cin>>ln;
		int m[100][100];
		for(int i=0;i<n;i++)//要先初始化
			for(int j=0;j<n;j++)
				m[i][j]=0;
		string s1,s2;
		int flag1,flag2;
		for(int i=0;i<ln;i++)
		{
			cin>>s1>>s2;
			for(int j=0;j<n;j++)
			{
				if(p[j]==s1)
					flag1=j;
				if(p[j]==s2)
					flag2=j;
			}
			m[flag1][flag2]=1;
			if(type=='U')
				m[flag2][flag1]=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j!=n-1)
					cout<<m[i][j]<<" ";
				else 
					cout<<m[i][j];
			}
			cout<<endl;
		}
		if(type=='U')
		{
			int sum=0;
			for(int i=0;i<n;i++)
			{
				sum=0;
				cout<<p[i];
				for(int j=0;j<n;j++)
				{
					if(m[i][j]==1)
						sum++;
				}
				if(sum!=0)
					cout<<": "<<sum<<endl;
			}
		}
		else if(type=='D')
		{
			int insum=0,outsum=0;
			for(int i=0;i<n;i++)
			{
				insum=outsum=0;
				cout<<p[i];
				for(int j=0;j<n;j++)
				{
					if(m[i][j]==1)
						outsum++;
				}
				for(int j=0;j<n;j++)
				{
					if(m[j][i]==1)
						insum++;
				}
				if(insum==0&&outsum==0)
					cout<<"";
				else
					cout<<": "<<outsum<<" "<<insum<<" "<<insum+outsum<<endl;
			}
		}
	}
	return 0;
}
