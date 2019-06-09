#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int b[maxn];
struct Node
{
	int l,r;
}node[maxn];
vector<int>Ans,tmp;
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,m,i,j,k;
	while(cin>>n>>m)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		for( i = 1 ; i <= m ; i++)
			cin>>node[i].l>>node[i].r;
		int ans=-1;
		for( i = 1 ; i <= n ; i++)
		{
			tmp.clear();
			memcpy(b,a,sizeof(a));
			for( j = 1 ; j <= m ; j++)
			{
				if(node[j].l>i||node[j].r<i)
				{
					tmp.push_back(j);
					for( k = node[j].l ; k <= node[j].r ; k++)
					{
						b[k]--;
					}
				}
			}
			int maxi = -inf;
			int mina = inf;
			for( j = 1 ; j <= n ; j++)
			{
				maxi = max(b[j],maxi);
				mina = min(b[j],mina);
			}
			if(maxi-mina>ans)
			{
				ans=maxi-mina;
				Ans=tmp;
			}
		}
		cout<<ans<<endl;
		cout<<Ans.size()<<endl;
		for( i = 0 ; i < Ans.size() ; i++)
			cout<<Ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}