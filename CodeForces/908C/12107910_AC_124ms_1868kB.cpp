#include <stdio.h>
#include <math.h>
#include <iostream>
const int maxn = 1010;
double a[maxn];
double ans[maxn];
double max(double a, double b) { return a > b ? a : b; }
int main()
{
	//freopen("in.txt", "r", stdin);
	int n;
	double r,h;
	while (~scanf("%d%lf", &n, &r))
	{
		for (int i = 0; i < n; i++)
		{
			scanf("%lf", &a[i]);
		}
		ans[0] = r;
		int p;
		for (int i = 1; i < n; i++)
		{
			double maxh = r;
			for (int j = 0; j < i; j++)
			{
				h = ans[j] + sqrt(2 * r * 2 * r - (a[i] - a[j])*(a[i] - a[j]));
				if (h > maxh)
				{
					maxh = h;
					p = j;
				}
			}
			ans[i] = maxh;
		}
		for (int i = 0; i < n; i++)
			printf("%lf%s", ans[i],i==n-1?"\n":" ");
	}
    return 0;
}