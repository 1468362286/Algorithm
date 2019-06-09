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
const int maxn = 5210;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
typedef _int64 ll;
vector<int>vec[maxn];
bool cmp(int a,int b){return a>b;}
char ch[maxn][maxn];
int a[maxn][maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,i,j,k,x,d;
	while(cin>>n)
	{
		getchar();
		for( i = 1 ; i <= n ; i++)
		{
			int cnt=1;
			for( j = 1 ; j <= n/4 ; j++)
			{
				scanf("%c",&ch[i][j]);
				if(ch[i][j]>='A'&&ch[i][j]<='F')
				{
					x = ch[i][j]-'A'+10;
				}
				else x=ch[i][j]-'0';
				for( k = 0 ; k < 4 ; k++)
				{
					a[i][cnt*4-k]=(x&1);
					x>>=1;
				}
				cnt++;
			}
			getchar();
		}
		for( i = 1 ; i <= n ; i++)
			for( j = 1 ; j <= n ; j++)
				a[i][j]=a[i-1][j]+a[i][j-1]-a[i-1][j-1]+a[i][j];
		int ans=1;
		for( d = n ; d  ; d--)
		{
			if(n%d==0)
			{
				x = n/d;
				int cnt=0;
				bool flag=1;
				for( i = 1 ; i*d <= n ; i++)
					for( j = 1 ; j*d <= n ; j++)
					{
						int tmp = a[i*d][j*d]-a[(i-1)*d][j*d]-a[i*d][(j-1)*d]+a[(i-1)*d][(j-1)*d];
						flag&=(tmp==0||tmp==d*d);
					}
				if(flag)return cout<<d<<endl,0;
			}
		}
	}
	return 0;
}