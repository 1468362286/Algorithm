#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 200010;
vector<int>vec[maxn];
int a[maxn];
struct Node
{
	int val,id;
}node[maxn];
bool cmp(Node A,Node B)
{
	return A.val<B.val;
}
int binary(int n,int id)
{
	int l = 1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(node[mid].val>=node[id].val)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return l;
}
int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i,x,y;
	while(cin>>n>>k)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>node[i].val,node[i].id=i;
		for( i = 1 ; i <= n ; i++)
			vec[i].clear();
		for( i = 1 ; i <= k ; i++)
		{
			cin>>x>>y;
			if(node[x].val>node[y].val)
				vec[x].push_back(y);
			else if(node[x].val<node[y].val)
				vec[y].push_back(x);
		}
		sort(node+1,node+n+1,cmp);
		vector<int> ans(maxn);
		for( i = 1 ; i <= n ; i++)
		{
			int len = binary(n,i)-1;
			int gg=vec[node[i].id].size();
			ans[node[i].id]=len-vec[node[i].id].size();
		}
		for( i = 1 ; i <= n ; i++)
		{
			cout<<ans[i]<<" ";
		}
		cout<<endl;
	}
	return 0;
}