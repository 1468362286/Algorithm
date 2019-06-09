#include <iostream>
#include <string>
using namespace std;
const int maxn = 200000+100;
int n,k,top;
char str[maxn];
bool vis[maxn];
int sta[maxn];

int main()
{
	int i;
	while(cin>>n>>k)
	{
		top=0;
		memset(vis,0,sizeof(vis));
		scanf("%s",str);
		for( i = 0 ; i < n ; i++)
		{
			if(str[i]=='(')
			{
				sta[top++]=i;
			}
			else
			{
				--top;
				vis[sta[top]]=true;
				vis[i]=true;
				k-=2;
				if(k==0)
					break;
			}
		}
		for( i = 0 ; i < n ; i++)
			if(vis[i])
				printf("%c",str[i]);
		printf("\n");
	}
	return 0;
}