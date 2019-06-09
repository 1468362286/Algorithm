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
const int maxn=1010;
const int inf = 0x7fffffff;
typedef _int64 ll;
vector<int>G,O;
int min(int a,int b){return a>b?b:a;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,x;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x&1)G.push_back(x);
			else O.push_back(x);
		}
		sort(G.begin(),G.end());
		sort(O.begin(),O.end());
		int len = min(G.size(),O.size());
		int sum=0;
		for( i = G.size()-len-1 ; i>= 0 ; i--)
		{
			sum+=G[i];
		}
		for( i = O.size()-len-1 ; i>= 0 ; i--)
		{
			sum+=O[i];
		}
		if(G.size()>O.size())
		{
			sum-=G[G.size()-len-1];
		}
		else if(O.size()>G.size())
		{
			sum-=O[O.size()-len-1];
		}
		cout<<sum<<endl;
	}
	return 0;
}	