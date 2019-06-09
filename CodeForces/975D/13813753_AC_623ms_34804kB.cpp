#include <iostream>
#include <string>
#include <map>
#include <utility>
using namespace std;
typedef _int64 ll;
const int maxn = 2000010;
int n,a,b;
struct Node
{
	int x,v_x,v_y;
}node[maxn];
map<ll,int>S;
map<pair<int,int>,int> T;
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j;
	while(cin>>n>>a>>b)
	{
		for( i = 1 ; i <= n ; i++)
		{
			cin>>node[i].x>>node[i].v_x>>node[i].v_y;
		}
		ll cnt=0;
		for( i = 1 ; i <= n ; i++)
		{
			ll t=node[i].v_y-ll(a)*(ll)node[i].v_x;
			cnt+=(S[t]-T[make_pair(node[i].v_x,node[i].v_y)])<<1;
			S[t]++;
			T[make_pair(node[i].v_x,node[i].v_y)]++;
		}
		printf("%I64d\n",cnt);
	}
	return 0;
}