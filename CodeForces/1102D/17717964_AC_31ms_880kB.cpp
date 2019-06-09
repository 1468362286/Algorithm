#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
#include <assert.h>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 5010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int n;

int needRep(const vector<int> &cnt,const vector<int> &need)
{
	int res=0;
	for(int i = 0 ; i < 3 ; ++i)
		res+=abs(cnt[i]-need[i]);
	assert(res%2==0);
	return res/2;
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	string s;
	int i,j;
	cin>>n>>s;
	vector<int>cnt(3),cur(3,n/3);
	for( i = 0 ; i < s.size() ; i++)
		++cnt[s[i]-'0'];

	int need=needRep(cnt,cur);
	int curRep=0;
	for( i = 0 ; i < n ; ++i)
	{
		--cnt[s[i]-'0'];
		for( j = 0 ; j < 3 ; ++j)
		{
			if(cur[j]==0)continue;
			int rep=j!=s[i]-'0';
			--cur[j];
			if(curRep+rep+needRep(cnt,cur)==need)
			{
				s[i]=j+'0';
				curRep+=rep;
				break;
			}
			++cur[j];
		}
	}
	cout<<s<<endl;
	return 0;
}