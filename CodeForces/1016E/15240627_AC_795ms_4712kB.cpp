#include <iostream>
#include <string>
using namespace std;
const int maxn = 200005;
double sy,a,b;
#define eps 1e-8

double fencel[maxn];
double fencer[maxn];
double pre[maxn];
double min(double a,double b){return a>b?b:a;}
int main()
{
	scanf("%lf%lf%lf",&sy,&a,&b);
	int n,i;
	scanf("%d",&n);
	for( i = 0 ; i < n ; i++)
	{
		scanf("%lf%lf",&fencel[i],&fencer[i]);
		pre[i+1]=pre[i]+(fencer[i]-fencel[i]);
	}
	int q;
	scanf("%d",&q);
	for( i = 0 ; i < q ; i++)
	{
		double x,y;
		scanf("%lf%lf",&x,&y);
		double sfb=(y-0)/(y-sy);
		double pax = a-x;
		double pbx = b-x;
		pax = pax*sfb;
		pbx = pbx*sfb;
		pax = x+pax;
		pbx = x+pbx;
		if(pbx<=fencel[0])
		{
			printf("0.000000000000000\n");
			continue;
		}
		if(pax>=fencer[n-1])
		{
			printf("0.000000000000000\n");
			continue;
		}
		int l=0,r=n-1,mid;
		while(l<=r)
		{
			mid = (l+r)/2;
			if(fencer[mid]>pax+eps)
				r=mid-1;
			else
				l=mid+1;
		}
		l=r+1;
		double left=pre[l+1];
		left-=min(fencer[l]-fencel[l],(fencer[l]-pax));
		l=0,r=n-1;
		while(l<=r)
		{
			mid=(l+r)/2;
			if(fencel[mid]<pbx-eps)
				l=mid+1;
			else
				r=mid-1;
		}
		r=l-1;
		double right=pre[n]-pre[r];
		right-=min(fencer[r]-fencel[r],pbx-fencel[r]);
		double t = (b-a)*(pre[n]-right-left)/(pbx-pax);
		printf("%.15f\n",t);
	}
	return 0;
}
