#include <iostream>
#include <string>
#include <bitset>

using namespace std;
const int maxn = 210;
bitset<maxn> bit1[maxn],bit2[maxn];

int n,m,sum;

void updata()
{
	int i,j;
	for( i = 1 ; i <= n ; i++)
		bit2[i].reset();
	sum = 0;
	for( i = n ; i >0 ; i--)
	{
		bit2[i].set(i);
		for( j = 1 ; j < i ; j++)
		{
			if(bit1[j][i])
				bit2[j]|=bit2[i];
		}
		sum+=bit2[i].count();
	}
}
int main()
{
	freopen("settling.in","r",stdin);
	freopen("settling.out","w",stdout);
	int i,j,x,y,k;
	char ch[100];
//	freopen("in.txt","r",stdin);
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for( i = 1 ; i <= n ; i++)
		{
			bit1[i].reset();
			bit2[i].reset();
		}
		for( i = 0 ; i < m ; i++)
		{
			scanf("%d%d",&x,&y);
			bit1[x].set(y);
		}
		sum = 0;
		updata();
		printf("%d\n",sum-n);
		scanf("%d",&k);
		while(k--)
		{
			scanf("%s%d%d",ch,&x,&y);
			if(ch[0]=='?')
			{
				if(bit2[x].test(y))
					printf("YES\n");
				else
					printf("NO\n");
			}
			else if(ch[0]=='+')
			{
				bit1[x].set(y);
				updata();
				printf("%d\n",sum-n);
			}
			else if(ch[0]=='-')
			{
				bit1[x].reset(y);
				updata();
				printf("%d\n",sum-n);
			}
		}
	}
	return 0;
}