#include <stdio.h>

template <typename T>
static T amax(T a,T b)
{
	return a>b?a:b;
}

template<typename T>
static T agcd(T a,T b)
{
	return a==0?b:agcd(b%a,a);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		int a,b;
		double maxi=0;
		for( i = 0 ; i <n/2+1 ; i++)
		{
			if(agcd(i,n-i)==1)
			{
				double ans = 1.0*i/(n-i);
				if(maxi<ans)
				{
					maxi = ans;
					a = i;
					b = n-i;
				}
			}
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}