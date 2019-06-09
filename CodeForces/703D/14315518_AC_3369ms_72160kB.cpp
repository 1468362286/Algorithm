#include <iostream>
#include <string>
#include <string.h>
#include <map>
#include <utility>
#include <vector>
using namespace std;
const int maxn = 1000010;
map<int,int> pos;
vector<pair<int,int> > q[maxn];
vector<pair<int,int> >::iterator it;
int n,m,l,r,prevPos,appearXOR;
int a[maxn];
int ans[maxn];
int PrefixSum[maxn];
int c[maxn]; 
inline int lowbit(int x){return x&(-x);}

inline void update(int x,int value)
{
	for(int i = x ; i < maxn ; i+=lowbit(i))
	{
		c[i]^=value;
	}
}

inline int query(int x)
{
	int sum=0;
	for(int i = x ; i ; i-=lowbit(i))
	{
		sum^=c[i];
	}
	return sum;
}

int main()
{
//	freopen("in.txt","r",stdin);
	int i,j;
	ios::sync_with_stdio(false);  
    cin.tie(0);  
    cout.tie(0); 
	memset(ans,0,sizeof(ans));
	memset(c,0,sizeof(c));
	memset(a,0,sizeof(a));
	memset(PrefixSum,0,sizeof(PrefixSum));
	pos.clear();
	for( i = 0 ; i < maxn ; i++)
		q[i].clear();
	cin>>n;
	for( i = 1 ; i <= n ; i++)
		cin>>a[i],PrefixSum[i]=PrefixSum[i-1]^a[i];
	cin>>m;
	for( i = 1 ; i <= m ; i++)
	{
		cin>>l>>r;
		q[r].push_back(make_pair(l,i));
	}
	for( i = 1 ; i <= n ; i++)
	{
		prevPos=pos[a[i]];
		if(prevPos!=0)
			update(prevPos,a[i]);
		update(i,a[i]);
		pos[a[i]]=i;
		for(it=q[i].begin();it!=q[i].end();it++)
		{
			l=(*it).first;
			r=i;
			appearXOR=query(r)^query(l-1);
			ans[(*it).second]=PrefixSum[l-1]^PrefixSum[r]^appearXOR;
		}
	}
	for( i = 1 ; i <= m ; i++)
		cout<<ans[i]<<endl;
	return 0;
}