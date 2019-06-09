#include <iostream>
#include <string>
using namespace std;
char map[10][10];
int p[9][9]={1,2,3,1,2,3,1,2,3,
			 4,5,6,4,5,6,4,5,6,
			 7,8,9,7,8,9,7,8,9,
			 1,2,3,1,2,3,1,2,3,
			 4,5,6,4,5,6,4,5,6,
			 7,8,9,7,8,9,7,8,9,
			 1,2,3,1,2,3,1,2,3,
			 4,5,6,4,5,6,4,5,6,
			 7,8,9,7,8,9,7,8,9};
int q[9][9]={1,1,1,2,2,2,3,3,3,
			 1,1,1,2,2,2,3,3,3,
			 1,1,1,2,2,2,3,3,3,
			 4,4,4,5,5,5,6,6,6,
             4,4,4,5,5,5,6,6,6,
			 4,4,4,5,5,5,6,6,6,
		   	 7,7,7,8,8,8,9,9,9,
			 7,7,7,8,8,8,9,9,9,
			 7,7,7,8,8,8,9,9,9};
int main()
{
	//freopen("in.txt","r",stdin);
	int i,j,k,x,y;
	char ch[10];
	for( i = 1 ; i <= 9 ; i++)
		for( j = 1 ; j <= 3 ; j++)
		{
			scanf("%s",&ch);
			for( k = 1 ; k <= 3 ; k++)
			{
				map[i][(j-1)*3+k]=ch[k-1];
			}
		}
	scanf("%d%d",&x,&y);
	int tmp = p[x-1][y-1];
	int cnt=0;
	for( i = 1 ; i <= 9 ; i++)
		for( j = 1 ; j <= 9 ; j++)
		{
			if(q[i-1][j-1]==tmp)
			{
				if(map[i][j]=='.')
				{
					map[i][j]='!';
					cnt++;
				}
			}
		}
	if(cnt==0)
	{
		for( i = 1 ; i <= 9 ; i++)
			for( j = 1 ; j <= 9 ; j++)
				if(map[i][j]=='.')
					map[i][j]='!';
	}
	for( i = 1 ; i <= 9 ; i++)
	{
		for( j = 1 ; j <= 9 ; j++)
		{
			printf("%c",map[i][j]);
			if(j==3||j==6)
				printf(" ");
		}
		if(i==3||i==6)
			printf("\n\n");
		else
			printf("\n");
	}
	return 0;
}