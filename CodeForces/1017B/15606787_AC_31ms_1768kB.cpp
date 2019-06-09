#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
const int maxn = 100000 + 100;
int n;
int sum[maxn][4];
char a[maxn],b[maxn];
int id(int i){return (a[i]-'0')*2+b[i]-'0';}

int main()
{
	int n,i,j;
	while(~scanf("%d",&n))
	{
		memset(sum,0,sizeof(sum));
		scanf("%s%s",a+1,b+1);
		for( i = n ; i > 0 ; --i)
		{
			for( j = 0 ; j < 4 ; ++j)
			{
				sum[i][j]=sum[i+1][j];
			}
			++sum[i][id(i)];
		}
		ll ans=0;
		for( i = 1 ; i < n ; i++)
		{
			switch(id(i))
			{
			case 0:ans+=sum[i+1][2]+sum[i+1][3];break;
			case 1:ans+=sum[i+1][2];break;
			case 2:ans+=sum[i+1][0]+sum[i+1][1];break;
			case 3:ans+=sum[i+1][0];break;
			default:break;
			}
		}
		printf("%I64d\n",ans);
	}
	return 0;
}