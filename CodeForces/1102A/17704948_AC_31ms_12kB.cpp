#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int inf=0x3f3f3f3f;
const int maxn = 200010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int n;
	while(cin>>n)
	{
		if(((n+1)>>1)&1)
			cout<<"1"<<endl;
		else cout<<"0"<<endl;
	}
	return 0;
}