#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set> 
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
using namespace std;
const int maxn = 1010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
char ch[maxn][maxn];
int vist[maxn][maxn];

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,i,j;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			scanf("%s",&ch[i]);
		memset(vist,0,sizeof(vist));
		for( i = 0 ; i < n ; i++)
			vist[i][i]=1,vist[i][n-1-i]=1;
		char a=ch[0][0],b=ch[0][1];
		if(a==b)
		{
			cout<<"NO"<<endl;
			continue;
		}
		int flag=0;
		for( i = 0 ; i < n&&!flag ; i++)
			for( j = 0 ; j < n&&!flag ; j++)
			{
				if(vist[i][j])
				{
					if(ch[i][j]!=a)
						flag=1;
				}
				else
				{
					if(ch[i][j]!=b)
						flag=1;
				}
			}
		if(flag)cout<<"NO"<<endl;
		else cout<<"YES"<<endl;
	}
	return 0;
}