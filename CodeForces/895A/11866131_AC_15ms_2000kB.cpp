#include <stdio.h>
#include <algorithm>
using namespace std;
const int maxn = 370;
int a[maxn];
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j,sum;
	while(~scanf("%d",&n))
	{
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i); 
		int mina = 0x3f3f3f3f;
		for( i = 0 ; i < n ; i++)
		{
			sum = 0;
			for( j = i ; j < n ; j++)
			{
				sum+=a[j];
				if(abs(360-sum-sum)<mina)
				{
					mina = abs(360-sum-sum);
				}
			}
		}
		printf("%d\n",mina);
	}
	return 0;
}