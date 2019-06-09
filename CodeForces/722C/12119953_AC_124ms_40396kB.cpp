#include<bits/stdc++.h>  
using namespace std;  
  
#define lson l,m,rt<<1  
#define rson m+1,r,rt<<1|1  
#define LL __int64  
const int maxn=1e5+50;  
int n;  
LL a[maxn];  
  
struct node{  
    int l,r,c;  
    LL ls,rs,ms;  
    int mark;  
}t[maxn<<3];  
  
void build(int l,int r,int rt){  
    t[rt].l=l;  
    t[rt].r=r;  
    t[rt].c=r-l+1;  
    t[rt].mark=1;  
    if (l==r){  
        t[rt].ls=t[rt].rs=t[rt].ms=a[l];  
        return;  
    }  
    int m=(l+r)>>1;  
    build(lson);  
    build(rson);  
    t[rt].ls=t[rt].rs=t[rt].ms=t[rt<<1].ms+t[rt<<1|1].ms;  
}  
  
void update(int L,int R,int l,int r,int rt){  
    if (L==l&&R==r){  
        t[rt].ls=t[rt].rs=t[rt].ms=0;  
        t[rt].mark=0;  
        return;  
    }  
    int m=(l+r)>>1;  
    if (R<=m) update(L,R,lson);  
    else if (L>m) update(L,R,rson);  
      
    t[rt].ls=t[rt<<1].ls;  
    if (t[rt<<1].mark) t[rt].ls+=t[rt<<1|1].ls;  
      
    t[rt].rs=t[rt<<1|1].rs;  
    if (t[rt<<1|1].mark) t[rt].rs+=t[rt<<1].rs;  
      
    t[rt].ms=max(t[rt<<1].ms,t[rt<<1|1].ms);  
    t[rt].ms=max(t[rt].ms,t[rt<<1|1].ls+t[rt<<1].rs);  
      
    if (!t[rt<<1].mark||!t[rt<<1|1].mark) t[rt].mark=0;  
}  
  
int main(){  
    //freopen("input.txt","r",stdin);  
    int n,x;  
    while(scanf("%d",&n)!=EOF){  
        for(int i=1;i<=n;i++) scanf("%I64d",&a[i]);  
        build(1,n,1);  
        for(int i=1;i<=n;i++){  
            scanf("%d",&x);  
            update(x,x,1,n,1);  
            printf("%I64d\n",t[1].ms);  
        }  
    }  
    return 0;  
}  
