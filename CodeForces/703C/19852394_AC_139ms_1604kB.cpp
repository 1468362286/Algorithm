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
const int maxn = 100010;
const int inf = 0x3ffffff;
int min(int a,int b){return a>b?b:a;}
int max(int a,int b){return a>b?a:b;}
const double eps=1e-10;
struct Node
{
	double x,y;
}node[maxn];

int solve1(int n,double u,double v)
{
	for(int i = 0 ; i < n ; i++)
	{
		if(node[i].x*u<node[i].y*v)
			return 0;
	}
	return 1;
}

int solve2(int n,double mid,double u,double v)
{
	for(int i = 0 ; i < n ; i++)
	{
		if((node[i].x-v*mid)*u>node[i].y*v)
			return 0;
	}
	return 1;
}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,w,i;
	double v,u;
	while(cin>>n>>w>>v>>u)
	{
		for( i = 0 ; i < n ; i++)
			cin>>node[i].x>>node[i].y;
		if(solve1(n,u,v))
		{
			printf("%.10lf\n",w/u);
		}
		else
		{
			double l=0,r=1e9,mid;
			while(r-l>eps)
			{
				mid=(l+r)/2;
				if(solve2(n,mid,u,v))
				{
					r=mid;
				}
				else
				{
					l=mid;
				}
			}
			printf("%.10lf\n",w/u+mid);
		}
	}
	return 0;
}