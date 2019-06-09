#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

const int N=3005,Log=12;

typedef long long LL;

int n,m,q,h[N],e[N],nxt[N],D[N],tot,H[N],E[N],Nxt[N];

short Fa[N][N][Log];

bool g[N][N],In[N];

char c;

int read()
{
    int x=0,sig=1;
    for (c=getchar();c<'0' || c>'9';c=getchar()) if (c=='-') sig=-1;
    for (;c>='0' && c<='9';c=getchar()) x=x*10+c-48;
    return x*sig;
}

void add(int x,int y)
{
    E[++tot]=y; Nxt[tot]=H[x]; H[x]=tot;
}

int main()
{
    n=read(); m=read(); q=read();
    for (int i=1;i<=m;i++)
    {
        int x=read(); e[i]=read();
        nxt[i]=h[x]; h[x]=i;
    }
    for (int i=1;i<=n;i++)
    {
        D[tot=1]=i; g[i][i]=1;
        for (int j=1;j<=tot;j++)
        {
            int x=D[j];
            for (int k=h[x];k;k=nxt[k]) if (!g[i][e[k]])
            {
                g[i][e[k]]=1; D[++tot]=e[k];
            }
        }
    }
    for (int i=1;i<=n;i++)
    {
        tot=0;
        for (int j=1;j<=n;j++) H[j]=In[j]=0;
        for (int j=1;j<=n;j++)
        {
            if (g[j][i] && j!=i)
            {
                for (int k=h[j];k;k=nxt[k])
                    if (g[e[k]][i] && (Fa[i][j][0]==0 || e[k]<Fa[i][j][0])) Fa[i][j][0]=e[k];
                add(Fa[i][j][0],j);
            }
        }
        D[tot=1]=i;
        for (int j=1;j<=tot;j++)
        {
            int x=D[j]; In[x]=1;
            for (int k=H[x];k;k=Nxt[k]) D[++tot]=E[k];
        }
        for (int j=1;j<=n;j++) if (!In[j]) Fa[i][j][0]=0;
        for (int k=1;k<Log;k++) for (int j=1;j<=n;j++) Fa[i][j][k]=Fa[i][Fa[i][j][k-1]][k-1];
    }
    for (;q--;)
    {
        int x=read(),y=read(),rk=read();
        if (!Fa[y][x][0])
        {
            printf("-1\n"); continue;
        }
        for (int i=Log-1,j=2048;i>=0;i--,j>>=1) if (rk>j)
        {
            rk-=j; x=Fa[y][x][i];
        }
        printf("%d\n",(!x)?-1:x);
    }
    return 0;
}