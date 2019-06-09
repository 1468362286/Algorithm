#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <map>
using namespace std;
const int maxn = 100010;
const int inf=0x7fffffff;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
char ch[4]="RGB";
int vist[3];
char tmp[3];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n,cnt,i,j;
	string s,ans,Ans;
	while(cin>>n)
	{
		cin>>s;
		int mina=inf;
		sort(ch,ch+3);
		do
		{
			ans="";
			cnt=0;
			for( i = 0 ; i < n ; i+=3)
			{
				for( j = 0 ; j < 3 &&i+j<n ; j++)
				{
					ans+=ch[j];
					if(ch[j]!=s[i+j])
					{
						cnt++;
					}
				}
			}
			if(cnt<mina)
			{
				mina=cnt;
				Ans=ans;
			}
		}while(next_permutation(ch,ch+3));
		cout<<mina<<endl;
		cout<<Ans<<endl;
	}
	return 0;
}