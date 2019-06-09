#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>
using namespace std;
const int maxn=1000010;
char s[maxn];
struct Node
{
	int num;
	char c;
}node[maxn],tmp[maxn],temp[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	while(~scanf("%s",&s))
	{
		int ans=0;
		int n=strlen(s);
		int cn=0;
		for( i = 0 ; i < n ; i++)
		{
			if(i==0||(s[i]!=s[i-1]))
			{
				node[cn].c=s[i];
				node[cn++].num++;
			}
			else if(s[i]==s[i-1]&&i>0)
			{
				node[cn-1].num++;
			}
		}
		if(cn==1)
		{
			printf("0\n");
			continue;
		}
		while(1)
		{
			ans++;
			for( i = 0 ; i < cn ; i++)
			{
				if(i==0||i==cn-1)
					node[i].num--;
				else 
				{
					if(node[i].num>=2)
					{
						node[i].num-=2;
					}
					else
					{
						node[i].num--;
					}
				}
			}
			int cnt=0;
			for( i = 0 ; i < cn ; i++)
			{
				if(node[i].num==0)
					continue;
				tmp[cnt].c=node[i].c;
				tmp[cnt++].num=node[i].num;
			}
			if(cnt==0)
				break;
			int zz=1;
			temp[0].c=tmp[0].c;
			temp[0].num=tmp[0].num;
			for( i = 1 ; i < cnt ; i++)
			{
				if(temp[zz-1].c==tmp[i].c)
				{
					temp[zz-1].num+=tmp[i].num;
				}
				else
				{
					temp[zz].c=tmp[i].c;
					temp[zz++].num=tmp[i].num;
				}
			}
			for( i = 0 ; i < zz ; i++)
			{
				node[i].c=temp[i].c;
				node[i].num=temp[i].num;
			}
			cn=zz;
			if(cn==1)
				break;
		}
		cout<<ans<<endl;
	}
	return 0;
}