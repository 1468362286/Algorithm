#include <bits/stdc++.h>
using namespace std;

struct item
{
    int idx, c;
    bool operator < (const item &a) const
    {
        return c < a.c;
    }
    item(int i = 0, int c = 0): idx(i), c(c) {}
};
priority_queue<item> pq;


int tim[1000010];
int main(void)
{
    int n, k;
    scanf("%d%d", &n, &k);
    long long cost = 0;
    for(int i = 1; i <= n + k; i++)
    {
        int tmp;
        if(i <= n)
        {
            scanf("%d", &tmp);
            pq.push({i, tmp});
        }
        if(i >= k + 1)
        {
            item tem = pq.top();pq.pop();
            cost += 1ll * tem.c * (i - tem.idx);
            tim[tem.idx] = i;
        }
    }
    cout << cost << endl;
    for(int i = 1; i < n; i++)
        printf("%d ", tim[i] );
    printf("%d\n", tim[n] );
    return 0;
}