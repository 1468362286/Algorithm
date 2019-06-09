#include <bits/stdc++.h>
using namespace std;
const int maxn = 1501;
bitset<maxn>p[maxn][2];
vector<int>v[maxn];
char str[3000];
int main()
{
    freopen("triatrip.in","r",stdin);
    freopen("triatrip.out","w",stdout);
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%s",&str[1]);
        for(int j=1;j<=n;j++)
            if(str[j] == '+' )
            {
                v[i].push_back(j);
                p[i][0].set(j);
                //i点能到的点
                p[j][1].set(i);
                //能到i点的点 
            }
    }
    long long ans=0;
    for(int i=1;i<=n;i++)
        for(int j=0;j<(int)v[i].size();j++)
            ans+=(p[ v[i][j] ][0] & p[i][1]).count();
    printf("%lld\n",ans/3);
    return 0;
}