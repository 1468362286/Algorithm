#include <iostream>
#include <string>
using namespace std;
const int maxn = 1010;
char ch[maxn][maxn];
int vist[maxn][maxn];
int dir[8][2]={0,1,0,-1,1,0,-1,0,1,-1,1,1,-1,1,-1,-1};
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < n ; i++)
			scanf("%s",ch[i]);
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
			{
				if(ch[i][j]=='.')
				{
					for( k = 0 ; k < 8 ; k++)
					{
						int dx=i+dir[k][0];
						int dy=j+dir[k][1];
						if(dx>=0&&dx<n&&dy>=0&&dy<m)
						{
							vist[dx][dy]=1;	
						}
					}
				}
			}
		for( i = 0 ; i < n ; i++)
			vist[i][0]=1,vist[i][m-1]=1;
		for( i = 0 ; i < m ; i++)
			vist[0][i]=1,vist[n-1][i]=1;
		int flag=0;
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
			{
				if(ch[i][j]=='#')
				{
					int cnt=0;
					for( k = 0 ; k < 8 ; k++)
					{
						int dx = i+dir[k][0];
						int dy = j+dir[k][1];
						if(dx>=0&&dx<n&&dy>=0&&dy<m)
						{
							if(!vist[dx][dy])
								cnt++;
						}
					}
					if(cnt==0)
					{
						flag=1;
						goto loop;
					}
				}
			}
loop:	if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}