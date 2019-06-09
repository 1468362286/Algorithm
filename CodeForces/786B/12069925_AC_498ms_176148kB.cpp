#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>


#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r
#define FIN freopen("input.txt", "r", stdin)
using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;
const LL INF = 0x3f3f3f3f3f3f3f3fLL;
const int MAXN = 3e5 + 5;
int n,q, s, t, qn;
vector<PLL> E[MAXN << 2];
int ID[MAXN << 2], IDD[MAXN << 2];
LL d[MAXN << 2];
bool vis[MAXN << 2];

void init(){
    for(int i= 0;i < MAXN;i ++){
        E[i].clear();
    }
}

void build(int rt, int l, int r, int flag){
    if(flag == 0) ID[rt] = ++ qn;//给每一个节点编号
    else IDD[rt] = ++ qn;
    for(int i = l;i <= r;i ++){
        if(flag == 0) E[ID[rt]].push_back(make_pair(i, 0));
        else E[i].push_back(make_pair(IDD[rt], 0));
    }
    if(l == r) return;
    int mid = (l + r) >> 1;
    build(lson, flag);
    build(rson, flag);
}

void update(int rt, int l, int r,int u, int L, int R, int w, int flag){
    if(L <= l && r <= R){
        if(flag == 0){
            E[u].push_back(make_pair(ID[rt], w));
        }
        else{
            E[IDD[rt]].push_back(make_pair(u, w));
        }
        return ;
    }

    int mid = (l + r) >> 1;
    if(L <= mid) update(lson, u, L, R, w, flag);
    if(R > mid) update(rson, u, L, R, w, flag);
}

priority_queue<PLL, vector<PLL>, greater<PLL> > Q;

int main(){
    //  FIN;
    int u, v, w, l, r;
    while(~scanf("%d%d%d", &n, &q, &s)){
        init();
        qn = n;
        build(1, 1, n, 0);
        build(1, 1, n, 1);
        for(int i = 0;i < q;i ++){
            scanf("%d", &t);
            if(t == 1){
                scanf("%d%d%d", &u, &v, &w);
                E[u].push_back(make_pair(v, w));
            }
            else if(t == 2){//u -> [l, r]
                scanf("%d%d%d%d", &u, &l, &r, &w);
                update(1, 1, n, u, l, r, w, 0);
            }
            else if(t == 3){//[l, r] -> u;
                scanf("%d%d%d%d", &u, &l, &r, &w);
                update(1, 1, n, u, l, r, w, 1);
            }
        }
        memset(d, INF, sizeof(d));
        memset(vis, false, sizeof(vis));
        d[s] = 0;
        while(!Q.empty()) Q.pop();
        Q.push(make_pair(0, s));
        while(!Q.empty()){
            PLL e = Q.top();
            Q.pop();
            int u = e.second;
            if(vis[u]) continue;
            vis[u] = true;
            for(int i = 0;i < E[u].size();i ++){
                PLL &ed = E[u][i];
                if(!vis[ed.first] && d[ed.first] > d[u] + ed.second){
                    d[ed.first] = d[u] + ed.second;
                    Q.push(make_pair(d[ed.first], ed.first));
                }
            }
        }

        for(int i = 1;i <= n;i ++){
            printf("%lld%c", d[i] == INF ? -1 : d[i], i == n ? '\n' : ' ');
        }

    }
    return 0;
}