#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <time.h>
using namespace std;
typedef long long LL;

struct asd{
    int t, d, p, id;
}node[110];
bool cmp(asd x, asd y){
    return x.d < y.d;
}
int n;
int prex[110][2100], prey[110][2100];
pair<int,int>dp[2100];
vector<int>ans;

int main(){
    scanf("%d", &n);
    for(int i=1;i<=n;i++){
        scanf("%d%d%d",&node[i].t, &node[i].d, &node[i].p);
        node[i].id = i;
    }
    sort(node+1, node+n+1, cmp);
    for(int i=0;i<=2000;i++){
        dp[i].first = 0;
        dp[i].second = -1;
    }
    memset(prex, -1, sizeof(prex));

    for(int i=1;i<=n;i++){
        for(int j=node[i].d-node[i].t-1;j >= 0;j--){
            if(dp[j+node[i].t].first < dp[j].first + node[i].p)
            {
                prex[node[i].id][j+node[i].t] = dp[j].second;
                prey[node[i].id][j+node[i].t] = j;

                dp[j+node[i].t].first = dp[j].first + node[i].p;
                dp[j+node[i].t].second = node[i].id;
            }
        }
    }
    int Max = 0, pos;
    for(int i=0;i<=2000;i++)
        if(dp[i].first > Max){
            Max = dp[i].first;
            pos = i;
        }
    printf("%d\n", Max);
    int x, y, xx, yy;
    x = dp[pos].second;
    y = pos;
    while(x != -1){
        ans.push_back(x);
        xx = x;yy = y;
        x = prex[xx][yy];
        y = prey[xx][yy];
    }
    printf("%d\n", (int)ans.size());
    for(int i=(int)ans.size()-1;i>=0;i--)
        printf("%d ", ans[i]);
    return 0;
}