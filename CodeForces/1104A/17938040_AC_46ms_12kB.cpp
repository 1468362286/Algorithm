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
const int maxn = 1010;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n;
	while(cin>>n)
	{
		cout<<n<<endl;
		for(int i = 0 ; i < n ; i++)
		{
			cout<<"1"<<" ";
		}
		cout<<endl;
	}
    return 0;
}