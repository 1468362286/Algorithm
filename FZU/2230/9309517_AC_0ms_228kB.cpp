#include <iostream>
#include <math.h>
using namespace std;

struct Node
{
	int x;
	int y;
}node[2];

char ch[4][8];

int main()
{
//	freopen("in.txt","r",stdin);
	int T,i,j;
	scanf("%d",&T);
	while(T--)
	{
		for( i = 0 ; i < 4 ; i++)
		{
			getchar();//接收换行符
			for( j = 0 ; j < 8 ; j++)
			{
				scanf("%c",&ch[i][j]);
				if(ch[i][j] == '.')
				{
					node[0].x = i;
					node[0].y = j;
				}
				else if(ch[i][j] == '*')
				{
					node[1].x = i;
					node[1].y = j;
				}			 
			}
			
		}
		int ans	= abs(node[0].x-node[1].x)+abs(node[0].y-node[1].y);
		if(ans%2==0)
			printf("Black win\n");
		else
			printf("Red win\n");
	}
	return 0;
}
/*
看题意明显找规律，wa在没有接收换行符，mdzz。
*/