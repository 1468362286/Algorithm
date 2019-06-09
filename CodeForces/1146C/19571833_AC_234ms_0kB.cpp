#include<cstdio>
int v1[105],v2[105];
int main()
{
    int T; scanf("%d",&T);
    while(T--)
    {
        int n,ans=0; scanf("%d",&n);
        for(int i=0;i<=6;++i)
        {
            int id1=0,id2=0;
            for(int j=1;j<=n;++j) (j&(1<<i))?v1[++id1]=j:v2[++id2]=j;
            if(id1&&id2)
            {
                printf("%d %d ",id1,id2);
                for(int i=1;i<=id1;++i) printf("%d ",v1[i]);
                for(int i=1;i<=id2;++i) printf("%d ",v2[i]);
                puts(""); fflush(stdout);
                int x; scanf("%d",&x);
                if(x>ans) ans=x;
            }
        }
        printf("-1 %d\n",ans);
        fflush(stdout);
    }
}