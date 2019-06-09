#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;

const int maxn = 200010;
int n,a[maxn];

int main()
{
	//freopen("in.txt","r",stdin);
	stack<int>s;
	cin>>n;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i];
		if(!s.empty()&&abs(s.top()-a[i])%2==0)s.pop();
		else s.push(a[i]);
	}
	if(s.size()<=1)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}