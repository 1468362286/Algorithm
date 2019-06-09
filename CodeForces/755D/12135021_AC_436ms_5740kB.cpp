#include <stdio.h>
#include <string.h>
typedef long long ll;
#define lowbit(x) (x&-x);
const int maxn = 1e6 + 10;
int a[maxn], n, k;

void add(int x)
{
	while (x <= n)
	{
		a[x] += 1;
		x += lowbit(x);
	}
}

int getsum(int x)
{
	int sum = 0;
	while (x > 0)
	{
		sum += a[x];
		x -= lowbit(x);
	}
	return sum;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	while (~scanf("%d%d", &n, &k))
	{
		ll ans = 1;
		int s = 1, e;
		memset(a, 0, sizeof(a));
		if (k > (n / 2)) k = n - k;
		for (int i = 0; i < n; i++)
		{
			e = s + k;
			if (e > n) e -= n;
			if (s < e) ans += getsum(e - 1) - getsum(s) + 1;
			else ans += getsum(n) - getsum(s) + getsum(e-1) + 1;
			if (i != n - 1)printf("%lld ", ans);
			else printf("%lld\n", ans);
			add(s);
			add(e);
			s = e;
		}
	}
    return 0;
}