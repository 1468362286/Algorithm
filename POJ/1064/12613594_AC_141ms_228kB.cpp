#include <stdio.h>
#include <algorithm>
using namespace std;
double a[10010];
int n,k;
const double eps=1e-10;
double max(double a,double b){return a>b?a:b;}
inline int cal(double x)
{
	int sum=0;
	for(int i = 0 ; i < n ; i++)
	{
		sum+=int(a[i]/x);
	}
	return sum;
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(~scanf("%d%d",&n,&k))
	{
		double maxi=0;
		for(int i = 0 ; i < n ; i++)
			scanf("%lf",a+i),maxi=max(maxi,a[i]);
		double l=0,r=maxi,ans=0.00;
		while(r-l>=eps)
		{
			double mid=(l+r)/2;
	//		double p=cal(mid);
			if(cal(mid)>=k)
			{
				
				l=mid;
			//	ans=l;
			}
			else
			{
				r=mid;
			//	ans=r;
			}
		}
		if((int)(r*1000)%10>=5)  
        r-=0.005;
		printf("%.2lf\n",r);
	}
	return 0;
}