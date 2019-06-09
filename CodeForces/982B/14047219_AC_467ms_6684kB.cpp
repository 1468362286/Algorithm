#include <iostream>
#include <string>
#include <queue>
#include <set>
#include <utility>
using namespace std;
const int maxn = 200010;
int w[maxn];
int vist[maxn];
priority_queue<pair<int,int> > q1;
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > > q0;
pair<int,int> t;
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	string s;
	while(cin>>n)
	{
		while(!q0.empty()) q0.pop();
		for( i = 1 ; i <= n ; i++)
		{
			cin>>w[i];
			q0.push(make_pair(w[i],i));
		}
		cin>>s;
		while(!q1.empty()) q1.pop();
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='0')
			{
				t = q0.top();
				cout<<t.second<<" ";
				q1.push(t);
				q0.pop();
			}
			else if(s[i]=='1')
			{
				t = q1.top();
				cout<<t.second<<" ";
				q1.pop();
			}
		}
		cout<<endl;
	}
	return 0;
}