#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

char map[60][60];
char ch[110];
int dir[4][2] = { 0,1,0,-1,1,0,-1,0 };
struct Node
{
	int x, y;
}s,t;
int main()
{
	//freopen("in.txt", "r", stdin);
	int n, m,ansx,ansy;
	while (~scanf("%d%d", &n, &m))
	{
		getchar();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				scanf("%c", &map[i][j]);
				if (map[i][j] == 'S')
				{
					s.x = i;
					s.y = j;
				}
				else if (map[i][j] == 'E')
				{
					t.x = i;
					t.y = j;
				}
			}
			getchar();
		}
		scanf("%s", ch);
		int len = strlen(ch);
		int a[4] = { 0,1,2,3 };
		int cnt = 0;
		for (int k = 0; k < 24; k++)
		{
			int flag = 0;
			ansx = s.x;
			ansy = s.y;
			for (int i = 0; i < len; i++)
			{
				int tmp = ch[i] - '0';
				ansx += dir[a[tmp]][0];
				ansy += dir[a[tmp]][1];
				if (map[ansx][ansy] == '#' || ansx < 0 || ansx >= n || ansy < 0 || ansy >= m)
				{
					flag = 1;
					break;
				}
				else if (map[ansx][ansy] == 'E')
				{
					flag = 2;
					break;
				}
			}
			if (flag==2)cnt++;
			next_permutation(a, a + 4);
		}
		printf("%d\n", cnt);
	}
    return 0;
}
