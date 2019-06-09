#include<bits/stdc++.h>
using namespace std;
#define Fopen freopen("_in.txt","r",stdin); freopen("_out.txt","w",stdout);
#define LL long long
#define ULL unsigned LL
#define fi first
#define se second
#define pb push_back
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
typedef pair<int,int> pll;
const int INF = 0x3f3f3f3f;
const LL mod = 1e9+7;
const int N = 1e5+10;
int n;
int pre[N];
int cnt[N];
int vis[N];
int ss[N];
struct Node{
    int t;
    int id;
}A[N];
bool cmp(Node x,Node y){
    return x.t < y.t;
}
set<int>s ;
bool check(){
    int ttt = *s.begin();
    return ss[cnt[ttt]] == s.size();
}
int Find(int x){
    if(x == pre[x]) return x;
    return pre[x] = Find(pre[x]);
}
int main(){
    scanf("%d", &n);
    int ans = INF;
    int len = 1;
    for(int i = 1; i <= n; i++){
        cnt[i] = 1;
        pre[i] = i;
    }
    for(int i = 1; i <= n; i++){
        scanf("%d", &A[i].t);
        ans = min(ans,A[i].t+1);
        A[i].id = i;
    }
    sort(A+1,A+1+n,cmp);
    for(int i = 1; i <= n; i++){
        int now = A[i].id;
        vis[now] = 1;
        int f = 0;
        if(now+1 <= n && vis[now+1]){
            int t = Find(now), y = Find(now+1);
            pre[t] = y;
            ss[cnt[y]]--;
            cnt[y] += cnt[t];
            ss[cnt[y]]++;
            f = 1;
        }
        if(now-1 >= 1 && vis[now-1]){
            int t = Find(now), y = Find(now-1);
            if(f == 1) s.erase(t),ss[cnt[t]]--;
            ss[cnt[y]]--;
            cnt[y] += cnt[t];
            ss[cnt[y]]++;
            pre[t] = y;
            f = 2 ;
        }
        if(f == 0) s.insert(now), ss[cnt[now]]++;
        if(s.size() > len && check()){
            len = s.size();
            ans = A[i].t+1;
        }
    }
    printf("%d", ans);
    return 0;
}