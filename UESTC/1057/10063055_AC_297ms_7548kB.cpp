//qscqesze
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <sstream>
#include <queue>
#include <typeinfo>
#include <fstream>
#include <map>
#include <stack>
#define LL(x) (x<<1)
#define RR(x) (x<<1|1)
#define MID(a,b) (a+((b-a)>>1))
const int N=500000;
typedef long long LL;
typedef long long ll;
using namespace std;
//freopen("D.in","r",stdin);
//freopen("D.out","w",stdout);
#define sspeed ios_base::sync_with_stdio(0);cin.tie(0)
#define maxn 200001
#define mod 10007
#define eps 1e-9
//const int inf=0x7fffffff;   //无限大
const int inf=0x3f3f3f3f;
/*

int buf[10];
inline void write(int i) {
  int p = 0;if(i == 0) p++;
  else while(i) {buf[p++] = i % 10;i /= 10;}
  for(int j = p-1; j >=0; j--) putchar('0' + buf[j]);
  printf("\n");
}
*/
//**************************************************************************************
inline ll read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}


struct node
{
    int lft,rht;
    LL sum,add;
    int mid(){return MID(lft,rht);}
    void fun(LL tmp)
    {
        add+=tmp;
        sum+=(rht-lft+1)*tmp;
    }
};

int y[N];

struct Segtree
{
    node tree[N*4];
    void relax(int ind)
    {
        if(tree[ind].add)
        {
            tree[LL(ind)].fun(tree[ind].add);
            tree[RR(ind)].fun(tree[ind].add);
            tree[ind].add=0;
        }
    }
    void build(int lft,int rht,int ind)
    {
        tree[ind].lft=lft;    tree[ind].rht=rht;
        tree[ind].sum=0;    tree[ind].add=0;
        if(lft==rht) tree[ind].sum=y[lft];
        else
        {
            int mid=tree[ind].mid();
            build(lft,mid,LL(ind));
            build(mid+1,rht,RR(ind));
            tree[ind].sum=tree[LL(ind)].sum+tree[RR(ind)].sum;
        }
    }
    void updata(int st,int ed,int ind,int add)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) tree[ind].fun(add);
        else
        {
            relax(ind);
            int mid=tree[ind].mid();
            if(st<=mid) updata(st,ed,LL(ind),add);
            if(ed> mid) updata(st,ed,RR(ind),add);
            tree[ind].sum=tree[LL(ind)].sum+tree[RR(ind)].sum;
        }
    }
    LL query(int st,int ed,int ind)
    {
        int lft=tree[ind].lft,rht=tree[ind].rht;
        if(st<=lft&&rht<=ed) return tree[ind].sum;
        else
        {
            relax(ind);
            int mid=tree[ind].mid();
            LL sum1=0,sum2=0;
            if(st<=mid) sum1=query(st,ed,LL(ind));
            if(ed> mid) sum2=query(st,ed,RR(ind));
            return sum1+sum2;
        }
    }
}seg;
int main()
{
    int n,m;
    while(scanf("%d",&n)!=EOF)
    {
        char str[5];
        int a,b,c;
        for(int i=1;i<=n;i++) scanf("%d",&y[i]);
        seg.build(1,n,1);
        scanf("%d",&m);
        while(m--)
        {
            scanf("%d%d%d",&a,&b,&c);
            seg.updata(a,b,1,c);
            printf("%lld\n",seg.query(a,b,1));
        }
    }
    return 0;
}