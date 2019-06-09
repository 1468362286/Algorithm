#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
const int maxn = 1010;
vector<int> ans;
int a[maxn];
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	while(~scanf("%d",&n))
	{
		ans.clear();
		for( i = 0 ; i < n ; i++)
			scanf("%d",a+i);
		int cnt=0;
		for( i = 0 ; i < n-1 ; i++)
		{
			int tmp=gcd(a[i],a[i+1]);
			if(tmp!=1)
			{
				ans.push_back(a[i]);
				ans.push_back(1);
				cnt++;
			}
			else
				ans.push_back(a[i]);
		}
		ans.push_back(a[n-1]);
		printf("%d\n",cnt);
		for( i = 0 ; i < ans.size() ; i++)
		{
			printf("%d%s",ans[i],i==ans.size()-1?"\n":" ");
		}
	}
	return 0;
}