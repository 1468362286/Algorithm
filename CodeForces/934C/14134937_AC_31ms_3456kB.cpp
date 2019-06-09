#include <iostream>
#include <string>
using namespace std;
const int maxn = 2005;
int n;
int pre1[maxn];
int pre2[maxn];
int a[maxn];
inline int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k;
	scanf("%d",&n);
	for( i = 1 ; i <= n ; i++)
	{
		scanf("%d",&a[i]);
		pre1[i]=pre1[i-1]+(a[i]==1);
	}
	for( i = n ; i >=1 ; i--)
		pre2[i]=pre2[i+1]+(a[i]==2);
	int ans=0;
	for( k = 1 ; k <= n+1 ; k++)
	{
		int num1=0,num2=0;
		for( i = 1 ; i <= k ; i++)
			num1=max(num1,pre1[i-1]+pre2[i]-pre2[k]);
		for( i = k ; i <= n+1 ; i++)
			num2=max(num2,pre2[i]+pre1[i-1]-pre1[k-1]);
		ans=max(ans,num1+num2);
	}
	printf("%d\n",ans);
	return 0;
}

