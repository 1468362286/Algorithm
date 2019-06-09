#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 200010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
map<int,int>mymap;
struct Node
{
	int x,cn;
}node[maxn];
bool cmp(Node A,Node B)
{
	return A.cn>B.cn;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,k,i,j;
	while(cin>>n>>k)
	{
		mymap.clear();
		for( i = 0 ; i < n ; i++)
			cin>>a[i],mymap[a[i]]++;
		map<int,int>::iterator it;
		int cnt=0;
		for( it = mymap.begin() ; it!=mymap.end() ; it++)
		{
			node[cnt].x=(*it).first;
			node[cnt++].cn=(*it).second;
		}
		sort(node,node+cnt,cmp);
		int ans=1;
		for( i = 1 ; i <= node[0].cn ; i++)
		{
			int tmp=0;
			int flag=0;
			for( j = 0 ; j < k ; j++)
			{
				tmp+=node[j].cn/i;
				if(tmp>=k)
				{
					flag=1;
					break;
				}
			}
			if(flag)ans=i;
		}
		int tmp=0;
		int xx=0;
		for( i = 0 ; i < k ; i++)
		{
			if(tmp+node[i].cn/ans>k)
			{
				xx=k-tmp;
				tmp=k;
			}
			else
			{
				tmp+=node[i].cn/ans;
				xx=node[i].cn/ans;
			}
			for( j = 0 ; j < xx ; j++)
				cout<<node[i].x<<" ";
			if(tmp>=k)
				break;
		}
		cout<<endl;
	}
	return 0;
}