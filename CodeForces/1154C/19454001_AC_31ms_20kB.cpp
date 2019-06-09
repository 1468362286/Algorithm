#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 110;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int F[7]={1,2,3,1,3,2,1};
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int	a,b,c,i;
	while(cin>>a>>b>>c)
	{
		vector<int>k(3);
		k[0]=a,k[1]=b,k[2]=c;
		int full=min(min(a/3,b/2),c/2);
		k[0]-=full*3;
		k[1]-=full*2;
		k[2]-=full*2;
		int ans=0;
		for( i = 0 ; i < 7 ; i++)
		{
			int day=i;
			int cur=0;
			vector<int>M=k;
			while(M[F[day]-1]>0)
			{
				--M[F[day]-1];
				day=(day+1)%7;
				++cur;
			}
			ans=max(ans,full*7+cur);
		}
		cout<<ans<<endl;
	}
	return 0;
}		