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
const int maxn = 100;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}

int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,l,r;
	cin>>n;
	while(n--)
	{
		cin>>l>>r;
		cout<<l<<" "<<2*l<<endl;
	}
    return 0;
}