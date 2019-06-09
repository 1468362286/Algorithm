#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef _int64 ll;
struct Node
{
	ll s,h;
	string t;
	bool operator<(const Node &b)const
	{
		return (s*b.h)>(h*b.s);
	}
}node[100010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	while(cin>>n)
	{
		string s;
		for( i = 0 ; i < n ; i++)
		{
			cin>>s;
			ll cnts=0,cnth=0;
			for( j = 0 ; j < s.size() ; j++)
			{
				if(s[j]=='s')
					cnts++;
				else if(s[j]=='h')
					cnth++;
			}
			node[i].s=cnts;
			node[i].h=cnth;
			node[i].t=s;
		}
		sort(node,node+n);
		string ans="";
		ll sums=0;
		for( i = 0 ; i < n ; i++)
		{
			ans+=node[i].t;
			sums+=node[i].s;
		}
		ll cnt=0;
		for( i = ans.size()-1 ; i >= 0 ; i--)
		{
			if(ans[i]=='h')
			{
				cnt+=sums;
			}
			else
			{
				sums--;
			}
		}
		printf("%I64d\n",cnt);
	}
	return 0;
}