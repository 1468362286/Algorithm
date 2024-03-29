#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>

#define MAXN 10000

using namespace std;

struct Point
{
    int x,y;
    Point(){}
    Point(int _x,int _y):x(_x),y(_y){}
}points[MAXN],o;

int tot=0,n,r,m; //m=候选的点

inline int dist(Point a,Point b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

bool cmp(Point a,Point b)
{
    return dist(a,o)>dist(b,o);
}

void init()
{
    scanf("%d%d",&n,&r);
    for(int i=-r;i<=r;i++)
        for(int j=-r;j<=r;j++)
            if(dist(Point(i,j),o)<=r*r)
                points[++tot]=Point(i,j);
    sort(points+1,points+tot+1,cmp);
    m=min(18,max(n,tot)); //!!!!取前18个距离圆心最远的点,若找到的在半径为r的圆内的点个数不到n，剩下的点用(0,0)补齐！
}

int ans[MAXN],maxans;

int numofpoint[MAXN],stack[MAXN],top=0;

void DFS(int x,int used,int sum) //搜到第x个可行点，已经选了used个点，当前的两两距离平方和为sum
{
    if(used==n)
    {
        if(maxans<sum)
        {
            maxans=sum;
            memcpy(ans,stack,sizeof(stack));
        }
        return;
    }
    for(int i=x;i<=m;i++)
    {
        stack[++top]=i;
        int tmp=0;
        for(int j=1;j<top;j++)
            tmp+=dist(points[stack[j]],points[i]);
        DFS(i,used+1,sum+tmp); //!!!!!
        top--;
    }
}

int main()
{
    init();
    DFS(1,0,0);
    printf("%d\n",maxans);
    for(int i=1;i<=n;i++)
        printf("%d %d\n",points[ans[i]].x,points[ans[i]].y);
    return 0;
}
