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
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	stack<int>s;
	cin>>n;
	int flag=1;
	int mx=0;
	for(int i = 1 ; i <= n ; i++)
	{
		cin>>a[i];
		mx=max(mx,a[i]);
		if(!s.empty()&&abs(s.top()-a[i])==0)
			s.pop();
		else if(!s.empty()&&s.top()<a[i])
			flag=0;
		else s.push(a[i]);
	}
	if(flag&&(s.size()==0||s.size()==1&&s.top()==mx))cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
	return 0;
}