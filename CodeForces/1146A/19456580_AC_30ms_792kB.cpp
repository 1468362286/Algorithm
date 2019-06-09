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
const int maxn = 200010;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int c[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	string s;
	while(cin>>s)
	{
		int cnt=0;
		for(int i = 0 ; i < s.size() ; i++)
			if(s[i]=='a')
				cnt++;
		cout<<cnt+min(cnt-1,s.size()-cnt)<<endl;
	}
	return 0;
}