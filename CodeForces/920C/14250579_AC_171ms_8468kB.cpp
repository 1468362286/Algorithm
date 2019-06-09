#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int maxn = 2000010;
int a[maxn];
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i,j;
	string s;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		cin>>s;
		/*
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]=='1')
			{
				if(s[i-1]=='0'&&i!=0)
					l=i,r=i;
				else
					r=i;
			}
			else
			{
				if(s[i-1]=='1'&&i!=0)
				sort(a+l,a+r+2);
			}
		}
		*/
		for( i = 0 ; i < s.size() ; )
		{
			if(s[i]=='1')
			{
				int l=i,r;
				while(s[i]=='1')i++;
				r=i;
				sort(a+l,a+r+1);
			}
			else
			{
				i++;
			}
		}
		int flag=0;
		for( i = 0 ; i < n ; i++)
			if(a[i]!=i+1)
			{
				flag=1;
				break;
			}
		if(!flag)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}