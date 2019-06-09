#include <stdio.h>
#include <map>
using namespace std;
typedef _int64 ll;
int n, m;
const int maxn = 2e5 + 5;
map<int, int>mp;
int pos, a[maxn];
int main() {
	int i;
    scanf("%d%d", &n, &m);
    for( i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        if(a[i] == m) pos = i;
    }
    int cnt = 0;
    for( i = pos; i <= n; i++) {
        if(a[i] > m) cnt++;
        else if(a[i] < m) cnt--;
        mp[cnt]++;//记录右边比m大小的情况  从pos 到 i 这一段比m大小的情况
    }
    ll  ans = 0;
    cnt=0;
    for( i = pos; i >= 1; i--) {
        if(a[i] > m) cnt++;
        else if(a[i] < m) cnt--;
        ans += ll(mp[-cnt]);//奇数取最中间
        ans += ll(mp[-cnt + 1]);//偶数去中间靠左的
    }
    printf("%I64d\n", ans);//注意会爆int
    return 0;
}