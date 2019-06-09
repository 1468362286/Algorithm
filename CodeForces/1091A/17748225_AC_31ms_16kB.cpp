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
const int maxn = 500010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int y,b,r;
	while(cin>>y>>b>>r)
	{
		for(int i = y ; i >= 1 ; i--)
		{
			if(b>i&&r>i+1)
			{
				cout<<3*i+3<<endl;
				break;
			}
		}
	}
	return 0;
}