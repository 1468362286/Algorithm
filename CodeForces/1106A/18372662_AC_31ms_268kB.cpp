#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
#include <utility>
#include <time.h>
using namespace std;
const int maxn = 510;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
typedef _int64 ll;

bool cmp(int a,int b){return a>b;}
char ch[maxn][maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,j;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			scanf("%s",&ch[i]+1);
		int ans=0;
		for( i = 1 ; i <= n ; i++)
		{
			for( j = 1 ; j <= n ; j++)
			{
				if(ch[i][j]=='X')
				{
					if(ch[i-1][j-1]=='X'&&ch[i-1][j+1]=='X'&&ch[i+1][j-1]=='X'&&ch[i+1][j+1]=='X')
					{
						ans++;
					}
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}