#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
struct Node
{
	int s,d,c;
	int id;
}node[110];
int ans[110];
bool cmp(Node A,Node B)
{
	return A.d<B.d;
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j;
	while(cin>>n>>m)
	{
		for( i = 1 ; i <= m ; i++)
		{
			cin>>node[i].s>>node[i].d>>node[i].c;
			node[i].id=i;
		}
		sort(node+1,node+m+1,cmp);
		int flag=0;
		memset(ans,0,sizeof(ans));
		for( i = 1 ; i <= m ; i++)
		{
			int cnt=0;
			for( j = node[i].s ; ; j++)
			{
				if(cnt==node[i].c)
					break;
				if(ans[j]==0)
					ans[j]=node[i].id,cnt++;
			}
			if(ans[node[i].d]==0)
			{
				ans[node[i].d]=m+1;
			}
			else
			{
				flag=1;
				break;
			}
		}
		if(flag)cout<<"-1"<<endl;
		else
		{
			for( i = 1 ; i <= n ; i++)
			{
				cout<<ans[i]<<" ";
			}
			cout<<endl;
		}
	}
	return 0;
}