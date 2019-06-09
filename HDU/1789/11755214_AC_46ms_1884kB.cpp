#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

const int maxn = 1010; 
struct Node
{
    int d;
    int s;
}node[maxn];

bool vist[maxn];

bool compare(struct Node x,struct Node y)
{
    return x.s>y.s;
}

int main(int argc,char* argv[])
{
    int T,n,i,j;
    scanf("%d",&T);
    while(T--)
    {
        memset(node,0,sizeof(node));
        memset(vist,0,sizeof(vist));
        scanf("%d",&n);
        for( i = 1 ; i <= n ; i++)
            scanf("%d",&node[i].d);
        for( i = 1 ; i <= n ; i++)
            scanf("%d",&node[i].s);
        sort(node+1,node+1+n,compare);
        int ans = 0;
        for( i = 1 ; i <= n ; i++)
        {
            for( j = node[i].d ; j>=1 ; j--)
            {
                if(!vist[j])
                {
                    vist[j] = 1;
                    break;
                }
            }
            if(j==0)
                ans+=node[i].s;
        }
        printf("%d\n",ans);
    }
    return 0;
}