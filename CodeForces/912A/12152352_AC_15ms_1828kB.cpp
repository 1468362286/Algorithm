#include <stdio.h>
typedef long long ll;
int main()
{
	//freopen("in.txt", "r", stdin);
	ll a, b, x, y, z;
	while (~scanf("%lld%lld", &a, &b))
	{
		ll yellow = 0,blue=0;
		scanf("%lld%lld%lld", &x, &y, &z);
		yellow = 2 * x+y;
		blue = 3 * z+y;
		yellow -= a;
		if (yellow < 0)yellow = 0;
		blue -= b;
		if (blue < 0)blue = 0;
		printf("%lld\n", yellow + blue );
	}
    return 0;
}
