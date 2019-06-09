#include <iostream>
#include <string>
using namespace std;
char a[110][110];
int dir[8][2]={1,0,-1,0,0,1,0,-1,-1,-1,-1,1,1,-1,1,1};
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i,j,k;
	while(cin>>n>>m)
	{
		for( i = 0 ; i < n ; i++)
			scanf("%s",&a[i]);
		int flag=0;
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < m ; j++)
			{
				if((a[i][j]>='1'&&a[i][j]<='9')||a[i][j]=='.')
				{
					int cnt=0;
					for( k = 0 ; k < 8 ; k++)
					{
						int dx = i+dir[k][0];
						int dy = j+dir[k][1];
						if(dx>=0&&dx<n&&dy>=0&&dy<m)
						{
							if(a[dx][dy]=='*')
							{
								cnt++;
								if(a[i][j]=='.')
								{
									flag=1;
									goto loop;
								}
							}
						}
					}
					if(cnt!=(a[i][j]-'0')&&a[i][j]!='.')
					{
						flag=1;
						goto loop;
					}
				}
			}
loop:	if(flag)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}