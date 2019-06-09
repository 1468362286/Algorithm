#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 500010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int nex[maxn];
char s[maxn],t[maxn];

void getnext(char ptr[])
{
	int i = 0,j=-1,len=strlen(ptr);
	nex[0]=-1;
	while(i<len)
	{
		if(j==-1||ptr[i]==ptr[j])
			nex[++i]=++j;
		else
			j=nex[j];
	}
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	scanf("%s%s",s,t);
	getnext(t);
	int zero=0,one=0;
	int len = strlen(s);
	for(int i = 0 ; i < len ; i++)
	{
		if(s[i]=='0')zero++;
		else one++;
	}
	string ans="";
	int cnt=0;
	len=strlen(t);
	while(zero>0&&one>0)
	{
		if(t[cnt]=='0')
		{
			if(zero>0)
			{
				zero--;
				ans+='0';
			}
			else break;
		}
		else
		{
			if(one>0)
			{
				one--;
				ans+='1';
			}
			else break;
		}
		cnt++;
		if(cnt==len)
		{
			cnt=nex[cnt];
		}
	}
	while(zero--)ans+='0';
	while(one--)ans+='1';
	cout<<ans<<endl;
	return 0;
}		