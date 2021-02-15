#include <iostream>
#include <list>
#include <string>
#include <sstream>
#define rep(i, n) for ( int i = 0; i < (n); i++ )
using namespace std;
int n; // num of dorms
int t; // num of commans 
 
void solve ()
{
	list<int> free;
	list<string> used;
	list<int>::iterator it1;
	list<string>::iterator it2;
	string s;
	stringstream ss;
	int num;
	int first; // if it is the first element to be output
	cin >> n;
	
	for (int i = 101; i <= 120; i++) free.push_back(i);
	
	rep(i, n)
	{
		cin >> s >> num;
		free.remove(num);
	//	ss.clear();
		ss.str("");
		ss << num;
		string tp = ss.str() + s;
	//	cout << tp << endl;
		used.push_back( tp );
	}
	
	cin >> t;
	rep(i, t)
	{
		cin >> s;
		if ( s[0] == 'a' )
		{
			cin >> s;
		//	cout << "why WA?" << s << endl;
			num = free.front();
			free.pop_front();
			
			ss.str("");
		//	ss.clear(); //不知道为什么，明明用了 clear() 以后，下一行仍然有输出 
		//	cout << "wrong there? " << ss.str() << endl;
			ss << num;
			string tp = ss.str() + s;
		//	cout << tp << endl;
			used.push_back( tp );
		}
		else if ( s[0] == 'r' )
		{
			cin >> num;
		//	ss.clear();
			ss.str("");
			ss << num;
			
		//	cout << "wrong there? " << ss.str() << endl;
			string tp = ss.str();
			for ( it2 =  used.begin(); it2 != used.end(); it2++ )
			{
				if ( (*it2).substr(0, 3) == tp )
				{
					used.erase(it2);
					break;
				}
			}
			free.push_back(num);
		}
		else if ( s == "display_free" )
		{
			first = 1;
			for ( it1 = free.begin(); it1 != free.end(); it1++ )
			{
				if ( first ) first = 0;
				else cout << "-";
				cout << (*it1);
			}
			cout << endl;
		}
		else
		{
			used.sort();
			first = 1;
			for ( it2 = used.begin(); it2 != used.end(); it2++ )
			{
				if ( first ) first = 0;
				else cout << "-";
				cout << (*it2).substr(3) << "(" << (*it2).substr(0, 3) << ")";
			}
			cout << endl;
		}
	}
	
}
 
int main ()
{
	solve();
	return 0;
}