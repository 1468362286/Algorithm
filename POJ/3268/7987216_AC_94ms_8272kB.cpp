#include<stdio.h>
#include <string.h>
#define inf 9999999

int map[1003][1003],dis[1003],find[1003],map1[1003][1003];

void dijkstra(int sourse,int n)//dijkstra求最短路径
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        find[i]=0;//初始化全部点都没有访问过
        dis[i]=map[sourse][i];//
    }
    find[sourse]=1;//更换访问记录
    dis[sourse]=0;//自己到自己 的 距离为0
    int min=inf,u;
    for(i=2;i<=n;i++)//依次将未放入S集合的结点中，取dist[]最小值的结点，放入结合S中
    {//一旦S包含了所有V中顶点，dis就记录了从源点到所有其他顶点之间的最短路径长度
        min=inf;
        for(j=1;j<=n;j++)// 找出当前未使用的点j的dist[j]最小值
        {
            if(!find[j]&&dis[j]<min)//更新最小到sourse点的坐标
            {
                min=dis[j];
                u=j;//u保存当前邻接点中距离最小的点的号码
            }
        }
        if(min==inf)//如果 都不连通，结束
            return ;
        find[u]=1;//更改u的访问记录表示将u点已存入S集合中
        for(j=1;j<=n;j++)
        {
            if(!find[j]&&map[u][j]!=inf)
			{
			 if(!find[j]&&min+map[u][j]<dis[j])//更新最小值
                dis[j]=min+map[u][j];
			}
        }
    }
}

int main()
{
    int a,b,c,n,m,i,j,x,max;
    while(scanf("%d %d %d",&n,&m,&x)!=EOF)//n(点数)，m(边数)
    {
        for(i=1;i<=n;i++)//初始化
        {
            for(j=1;j<=n;j++)
			{
                map[i][j]=inf;
				map1[i][j]=inf;
			}
        }
        for(i=1;i<=m;i++)//输入T条边
        {
            scanf("%d %d %d",&a,&b,&c);//a弧头,b弧尾,c距离（权值),d花费
            if(map[a][b]>c)//判断重边
            {
                map[a][b]=c;
				map1[b][a]=c;
            }
        }	
		dijkstra(x,n);//dijkstra函数参数只有起点和总点数
		int Dis[1003];
		memcpy(Dis,dis,sizeof(dis));
		memcpy(map,map1,sizeof(map1));
		max= -9999999;
		dijkstra(x,n);
		for( i = 1; i <= n ; i++)
		{
			if(Dis[i]+dis[i]>max)
			{
				max = Dis[i]+dis[i];
			}
		}
	
		printf("%d\n",max);
    }
    return 0;
}