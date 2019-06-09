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
const int maxn = 1010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int f[10];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int n,x,i;
	string s;
	while(cin>>n)
	{
		cin>>s;
		for( i = 1 ; i <= 9 ; i++)
		{
			cin>>x,f[i]=x;
		}
		int flag=0;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(!flag)
			{
				if(f[s[i]-'0']>(s[i]-'0'))
				{
					while(f[s[i]-'0']>=(s[i]-'0')&&i<s.size())
					{
						char c=f[s[i]-'0']+'0';
						cout<<c;
						i++;
					}
					i--;
					flag=1;
				}
				else
					cout<<s[i];
			}	
			else
				cout<<s[i];
		}
		cout<<endl;
	}
	return 0;
}		