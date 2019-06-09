#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;
int mp[110][110];
struct Node
{
	int opt,r,c,x;
}node[10010];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,q,tmp,i,j,opt,r,c;
	while(cin>>n>>m>>q)
	{
		memset(mp,0,sizeof(mp));
		int cnt=0;
		while(q--)
		{
			cin>>opt;
			node[cnt].opt=opt;
			if(opt==1)
			{
				cin>>node[cnt].r;
			}
			else if(opt==2)
			{
				cin>>node[cnt].c;
			}
			else if(opt==3)
			{
				cin>>node[cnt].r>>node[cnt].c>>node[cnt].x;
			}
			cnt++;
		}
		for( i = cnt-1 ; i >=0 ; i--)
		{
			opt=node[i].opt;
			if(opt==1)
			{
				r=node[i].r-1;
				tmp = mp[r][m-1];
				for( j = m-1 ; j >= 1 ; j--)
				{
					mp[r][j]=mp[r][j-1];
				}
				mp[r][0]=tmp;
			}
			else if(opt==2)
			{
				c=node[i].c-1;
				tmp = mp[n-1][c];
				for( j = n-1 ; j >= 1 ; j--)
				{
					mp[j][c]=mp[j-1][c];
				}
				mp[0][c]=tmp;
			}
			else if(opt==3)
			{
				mp[node[i].r-1][node[i].c-1]=node[i].x;
			//	printf("%d %d %d\n",node[i].r,node[i].c,node[i].x);
			}
		}
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
				printf("%d%s",mp[i][j],j==m-1?"\n":" ");
	}
	return 0;
}