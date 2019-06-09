#include <iostream>
#include <string>
using namespace std;
const int maxn = 2010;
char map[maxn][maxn];
int vist[maxn][maxn][2];
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,k,i,j,z;
	while(cin>>n>>m>>k)
	{
		memset(vist,0,sizeof(vist));
		int ans=0;
		for( i = 0 ; i < n ; i++)
			scanf("%s",&map[i]);
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
			{
				if(map[i][j]=='.')
				{
					if(k==1)
					{
						ans++;
						continue;
					}
					if(vist[i][j-1][0]==1&&j>=1)
					{
						if(map[i][j+k-1]=='.')
						{
							ans++;
							vist[i][j][0]=1;
						}
					}
					else 
					{
						if(j+k-1<m&&j+k-1>=0)
						{
							int cnt=1;
							for( z = 1 ; z < k ; z++)
							{
								int dy = j+z;
								if(dy>=0&&dy<m)
								{
									if(map[i][dy]=='.')
									{
										cnt++;
									}
									else
										break;
								}
								else
									break;
							}
							if(cnt==k)
							{
								vist[i][j][0]=1;
								ans++;
							}
						}
					}
					if(vist[i-1][j][1]==1&&i>=1)
					{
						if(map[i+k-1][j]=='.')
						{
							ans++;
							vist[i][j][1]=1;
						}
					}
					else
					{
						if(i+k-1<n&&i+k-1>=0)
						{
							int cnt=1;
							for( z = 1 ; z < k ; z++)
							{
								int dx = i+z;
								if(dx>=0&&dx<n)
								{
									if(map[dx][j]=='.')
										cnt++;
									else
										break;
								}
								else
									break;
							}
							if(cnt==k)
							{
								ans++;
								vist[i][j][1]=1;
							}
						}
					}
				}
			}
		cout<<ans<<endl;
	}
	return 0;
}