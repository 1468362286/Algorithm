#include<cstdio>
#include<algorithm>
#include <vector>
using namespace std;
const int maxn=400005,maxe=800005;
vector<int> st[maxn];
int n,m,len[maxn];
int fir[maxn],nxt[maxe],son[maxe],tot,ans[maxn];
int dfn[maxn],low[maxn],Tim,stk[maxn],top,G,blg[maxn];
bool instk[maxn];
int min(int a,int b){return a>b?b:a;}
void add(int x,int y){
    son[++tot]=y; nxt[tot]=fir[x]; fir[x]=tot;
}
void Tarjan(int x){
    dfn[x]=low[x]=++Tim; stk[++top]=x; instk[x]=true;
    for(int j=fir[x];j;j=nxt[j]){
        if(!dfn[son[j]]) Tarjan(son[j]), low[x]=min(low[x],low[son[j]]); else
        if(instk[son[j]]) low[x]=min(low[x],dfn[son[j]]);
    }
    if(dfn[x]==low[x]){
        G++; 
        do{
            blg[stk[top]]=G;
            instk[stk[top]]=false;
        }while(stk[top--]!=x);
    }
}
int main(){
	//freopen("in.txt","r",stdin);
	int i,j;
    scanf("%d%d",&n,&m);
    for( i=1;i<=n;i++){
        scanf("%d",&len[i]);
        for( j=1;j<=len[i];j++){
            int x; scanf("%d",&x);
            st[i].push_back(x); 
        }
    }
    for( i=1;i<=n-1;i++){
        int pos=-1;
        for( j=0;j<min(len[i],len[i+1]);j++) if(st[i][j]!=st[i+1][j]){ pos=j; break; }
        if(pos==-1){
            if(st[i].size()<=st[i+1].size()) continue; else return printf("No\n"),0; 
        }
        if(st[i][pos]>st[i+1][pos]){ // x:   x<<1:没变  x<<1|1：变大写
            add(st[i][pos]<<1,st[i][pos]<<1|1);
            add(st[i+1][pos]<<1|1,st[i+1][pos]<<1); 
        } else{
            add(st[i+1][pos]<<1|1,st[i][pos]<<1|1);
            add(st[i][pos]<<1,st[i+1][pos]<<1);
        }
    }
    for( i=2;i<=m*2+1;i++) if(!dfn[i]) Tarjan(i);
    for( i=2;i<=m*2+1;i+=2) if(blg[i]==blg[i^1]) return printf("No\n"),0; else ans[i>>1]=blg[i]<blg[i+1]?i:i+1;
    printf("Yes\n");
    int cnt=0; for( i=1;i<=m;i++) if(ans[i]==(i<<1|1)) cnt++;
    printf("%d\n",cnt);
    for( i=1;i<=m;i++) if(ans[i]==(i<<1|1)) printf("%d ",i);
    return 0;
}
