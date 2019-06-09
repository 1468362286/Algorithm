#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define M 500
#define INF 0x3f3f3f3f

int map_t[M][M], map_b[M][M], n, m;
int dist[M];
int dijkstra(int map_s[][M])
{
    bool vis[M];
    memset(vis, 0, sizeof(vis));
    for(int i=0; i<=n; i++) dist[i] = INF;
    for(int i=1; i<=n; i++)
    {
        dist[i] = map_s[1][i];
    }
    vis[1] = 1;
    for(int i=1; i<=n; i++)
    {
        int mins = INF, _next = 1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && mins > dist[j])
            {
                _next = j;
                mins = dist[j];
            }
        }
        vis[_next] = 1;
        for(int j=1; j<=n; j++)
        {
            if(!vis[j] && dist[j] > mins + map_s[_next][j])
            {
                dist[j] = mins + map_s[_next][j];
            }
        }
    }
    return dist[n];
}
void init()//初始化
{
    for(int i=0; i<=n; i++)
    {
        for(int j=0; j<=n; j++)
        {
            if(i == j)
            {
                map_t[i][j] = 0;
                map_b[i][j] = 0;
            }
            else
            {
                map_t[i][j] = INF;
                map_b[i][j] = 1;
            }
        }
    }
}
int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        init();
        int a, b;
        for(int i=0; i<m; i++)
        {
            scanf("%d%d", &a, &b);
            map_t[a][b] = map_t[b][a] = 1;
            map_b[a][b] = map_b[b][a] = INF;
        }
        int anst = dijkstra(map_t);
        int ansb = dijkstra(map_b);
        if(anst == INF || ansb == INF)
        {
            printf("-1\n");
        }
        else
        {
            ansb = max(anst, ansb);
            printf("%d\n", ansb);
        }
    }

    return 0;
}