#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;
const int maxn = 1010;
pair<double,double> p[maxn];

bool cmp(pair<double,double> A,pair<double,double> B)
{
	/*
	if(A.second==0&&B.second==0)
	{
		return A.first<B.first;
	}
	else if(A.second==0&&B.second!=0)
	{
		return A.second>B.second;
	}
	else if(A.second!=0&&B.second==0)
	{
		return A.second<B.second;
	}
	else
	*/
	return (A.first/A.second)>(B.first/B.second);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,i;
	while(~scanf("%d%d",&m,&n))
	{
		int cnt = 0;
		if(n==-1&&m==-1)
			break;
		if(n==0)
		{
			printf("0.000\n");
			continue;
		}
		for( i = 0 ; i < n ; i++)
		{
			scanf("%lf%lf",&p[i].first,&p[i].second);
			if(p[i].second==0)
				cnt++;
		}
		sort(p,p+n,cmp);
		double ans = 0;
		
		for( i = 0 ; i < n ; i++)
		{
			if(m>p[i].second)
			{
				ans+=p[i].first;
				m-=p[i].second;
			}
			else
			{
				if(p[i].second==0)
					ans+=p[i].first;
				else
				ans+=m*(1.0*p[i].first/p[i].second);
				break;
			}
		}
		printf("%.3lf\n",ans);
	}
	return 0;
}