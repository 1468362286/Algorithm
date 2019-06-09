#include <stdio.h>
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <math.h>
using namespace std;
const int maxn = 10010;
const int inf = 0x3ffffff;
typedef _int64 ll;
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int t,n,i,j;
	string s;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>s;
		int cnt1=0,cnt2=0,flag;
		for( i = 0 ; i < n ; i++)
		{
			if(s[i]=='<')
			{
				if(i==0)
					cnt1++;

				else
				{
					flag=0;
					for( j = i-1 ; j >= 0 ; j--)
					{
						if(s[j]=='>')
						{
							flag=1;
							break;
						}
					}
					if(!flag)cnt1++;
				}
			}
		}
		for( i = 0 ; i < n ; i++)
		{
			if(s[i]=='>')
			{
				if(i==n-1)
					cnt2++;
				else 
				{
					flag=0;
					for( j = i+1 ; j < n ; j++)
					{
						if(s[j]=='<')
						{
							flag=1;
							break;
						}
					}
					if(!flag)cnt2++;
				}
			}
		}
		cout<<min(cnt1,cnt2)<<endl;
	}
	return 0;
}
