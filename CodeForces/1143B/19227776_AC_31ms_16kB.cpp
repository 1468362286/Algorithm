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
const int maxn=200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
vector<int>vec;
ll max(ll a,ll b){return a>b?a:b;}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	string s;
	int x,i,j;
	while(cin>>s)
	{
		ll sum=1;
		for( i = 0 ; i < s.size() ; i++)
		{
			x = s[i]-'0';
			vec.push_back(x);
			sum*=x;
		}
		ll tmp=1;
		for( i = 0 ; i < vec.size() ; i++)
		{
			if(vec[i]==0)
				break;
			ll temp=tmp;
			if(vec[i]==1&&i!=0)
			{
				continue;
			}
			if(vec[i]!=1)
				temp*=vec[i]-1;
			for( j = i+1 ; j < vec.size() ; j++)
				temp*=9;
			tmp*=vec[i];
			sum=max(sum,temp);
		}
		printf("%I64d\n",sum);
	}
	return 0;
}	