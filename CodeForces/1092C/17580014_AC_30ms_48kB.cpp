#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
typedef _int64 ll;

const int maxn =307;
struct node
{
	string s;
	int id;
}a[maxn];
char ans[maxn];
int n;
bool cmp(node x,node y)
{
	return x.s.size()<y.s.size();
}
bool isPre(string s,string t)
{
	for(int i = 0 ; i < t.size() ; i++)
		if(s[i]!=t[i])
			return false;
		return true;
}
bool isSuf(string s,string t)
{
	for(int i = t.size()-1 ; i >= 0 ; i--)
		if(s[s.size()-t.size()+i]!=t[i])
			return false;
		return true;
}

void solve(string S)
{
	for(int i = 1 ; i <= n ; i+=2)
	{
		if(isPre(S,a[i].s)&&isSuf(S,a[i+1].s))
		{
			ans[a[i].id]='P';
			ans[a[i+1].id]='S';
			continue;
		}
		if(isPre(S,a[i+1].s)&&isSuf(S,a[i].s))
		{
			ans[a[i].id]='S';
			ans[a[i+1].id]='P';
			continue;
		}
		return;
	}
	for(int j = 1 ; j <= n ; j++)
		cout<<ans[j];
	cout<<endl;
	exit(0);
}
int main()
{
	//freopen("in.txt","r",stdin);
	int i;
	cin>>n;
	n=n*2-2;
	for( i = 1 ; i <= n ; i++)
	{
		cin>>a[i].s;
		a[i].id=i;
	}
	sort(a+1,a+n+1,cmp);
	if(n==2)
	{
		puts("PS");
		return 0;
	}
	solve(a[1].s+a[n-1].s);
	solve(a[1].s+a[n].s);
	solve(a[2].s+a[n-1].s);
	solve(a[2].s+a[n].s);
	return 0;
}