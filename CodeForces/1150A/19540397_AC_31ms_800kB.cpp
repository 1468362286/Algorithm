#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,m,r,x,i;
	while(cin>>n>>m>>r)
	{
		int mina=inf,maxi=-1;
		for( i = 0 ; i < n ; i++)
			cin>>x,mina=min(mina,x);
		for( i = 0 ; i < m ; i++)
			cin>>x,maxi=max(maxi,x);
		if(maxi<mina)
		{
			cout<<r<<endl;
			continue;
		}
		int tmp = (r/mina)*mina;
		r+=(r/mina)*maxi;
		r-=tmp;
		cout<<r<<endl;
	}
	return 0;
}		