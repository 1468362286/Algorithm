#include <iostream>
#include <string>
#include <string.h>
#include <set>
#include <utility>
using namespace std;
const int maxn = 2000010;
int m,n,k;
int ar[maxn];
pair<int,int>pa[maxn];
set<int>se[maxn];
set<pair<int,int> >sep;
int ansl[maxn];

void update()
{
	while(sep.size()&&(*sep.begin()).first<k)
	{
		int x = (*sep.begin()).second;
		sep.erase(sep.begin());
		set<int>::iterator it;
		for( it = se[x].begin() ; it!=se[x].end() ; )
		{
			int to = (*it);
			if(sep.count(make_pair(ar[to],to)))
			{
				sep.erase(make_pair(ar[to],to));
				ar[to]--;
				sep.insert(make_pair(ar[to],to));
				se[x].erase(it++);
			}
			else
				it++;
		}
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	memset(ar,0,sizeof(ar));
	scanf("%d%d%d",&n,&m,&k);
	for( i = 0 ; i < m ; i++)
	{
		int a,b;
		scanf("%d%d",&a,&b);
		se[a].insert(b);
		se[b].insert(a);
		pa[i]=make_pair(a,b);
		ar[a]++;
		ar[b]++;
	}
	for( i = 1 ; i <= n ; i++)
		sep.insert(make_pair(ar[i],i));
	update();
	ansl[m]=sep.size();
	for( i = m-1 ; i >0 ; i--)
	{
		int a=pa[i].first,b=pa[i].second;
		if(sep.count(make_pair(ar[a],a))&&sep.count(make_pair(ar[b],b)))
		{
			sep.erase(make_pair(ar[a],a));
			sep.erase(make_pair(ar[b],b));
			ar[a]--;
			ar[b]--;
			sep.insert(make_pair(ar[a],a));
			sep.insert(make_pair(ar[b],b));
			se[a].erase(b);
			se[b].erase(a);
			update();
		}
		ansl[i]=sep.size();
	}
	for( i = 1 ; i <= m ; i++)
		printf("%d\n",ansl[i]);
	return 0;
}