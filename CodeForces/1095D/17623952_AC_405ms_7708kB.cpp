#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <map>
#include <string.h>
#include <algorithm>
using namespace std;
int n;
vector<vector<int> >a;

void check(int l,int r)
{
	int i;
	vector<int>ans;
	for( i = 0 ; i < n ; i++)
	{
		int nxt=-1;
		if(a[l][0]==r)
			nxt=a[l][1];
		else if(a[l][1]==r)
			nxt=a[l][0];
		else return;
		ans.push_back(nxt);
		l=r,r=nxt;
	}
	for( i = 0 ; i < ans.size() ; i++)
		cout<<ans[i]+1<<" ";
	cout<<endl;
	exit(0);
}
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int i;
	while(cin>>n)
	{
		a=vector<vector<int> >(n,vector<int>(2));
		for( i = 0 ; i < n ; i++)
		{
			cin>>a[i][0]>>a[i][1];
			--a[i][0];
			--a[i][1];
		}
		check(0,a[0][0]);
		check(0,a[0][1]);
	}
	return 0;
}