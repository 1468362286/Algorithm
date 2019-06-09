#include <stdio.h>
#include <string.h>
const int maxn = 222222;
int n,sum[maxn];
struct BIT
{
#define lowbit(x) (x&(-x))
	int b[maxn];
	void init()
	{
		memset(b, 0, sizeof(b));
	}
	void add(int i,int x)
	{
		while (i <= n)
		{
			b[i] += x;
			i += lowbit(i);
		}
	}

	int getsum(int x)
	{
		int sum = 0;
		while (x )
		{
			sum += b[x];
			x -= lowbit(x);
		}
		return sum;
	}
}x,y;

int main()
{
	//freopen("in.txt", "r", stdin);
	int k, a, b, q,opt,u,v,ans;
	while (~scanf("%d%d%d%d%d", &n, &k, &a, &b, &q))
	{
		x.init(), y.init();
		memset(sum, 0, sizeof(sum));
		while (q--)
		{
			scanf("%d", &opt);
			if (opt == 1)
			{
				scanf("%d%d", &u, &v);
				if (sum[u] + v <= b)x.add(u, v), y.add(u, v);
				else if (sum[u] + v > b&&sum[u] + v <= a)
				{
					if (sum[u] < b)x.add(u, b - sum[u]);
					y.add(u, v);
				}
				else if (sum[u] + v >= a)
				{
					if (sum[u] < b)x.add(u, b - sum[u]);
					if (sum[u] < a)y.add(u, a - sum[u]);
				}
				//x.add(u, sum[u]+v>a?a:v);
				//y.add(u, sum[u]+v>b?b:v);
				sum[u] += v;
			}
			else if (opt == 2)
			{
				scanf("%d", &u);
				//printf("%d %d %d\n", y.getsum(u - 1),x.getsum(n),x.getsum(u+k));
				ans = x.getsum(u - 1) + y.getsum(n) - y.getsum(u + k-1);
				printf("%d\n", ans);
			}
		}
	}
    return 0;
}