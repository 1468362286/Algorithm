#include <iostream>
#include <string>
using namespace std;
const int maxn = 55;
char ch[maxn][maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i,j;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
			scanf("%s",&ch[i]);
		for( i = 0 ; i < n ; i++)
			for( j = 0 ; j < n ; j++)
			{
				if(ch[i][j]=='.')
				{
					if(i>0&&i<n-1&&j>0&&j<=n-1)
					{
						if(ch[i-1][j]=='.'&&ch[i+1][j]=='.'&&ch[i][j+1]=='.'&&ch[i][j-1]=='.')
						{
							ch[i][j]=ch[i-1][j]=ch[i+1][j]=ch[i][j+1]=ch[i][j-1]='#';
						}
					}
				}
			}
		int flag=0;
		for( i = 0 ; i < n&&!flag ; i++)
			for( j = 0 ; j < n&&!flag ; j++)
				if(ch[i][j]=='.')flag=1;
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}