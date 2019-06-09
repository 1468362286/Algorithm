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
const int maxn = 110;
int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a>b?b:a;}
int a[maxn];
vector<pair<int,int> >vec;

void fun(int x)
{
	for(int i = 2 ; i*i<=x ; i++)
	{
		int cnt=0;
		while(x%i==0)x/=i,cnt++;
		if(cnt)
		vec.push_back(make_pair(i,cnt));
	}
	if(x>1)vec.push_back(make_pair(x,1));
}
int main()
{
#ifdef _DEBUG
    freopen("in.txt","r",stdin);
#endif
	int n,i;
	while(cin>>n)
	{
		if(n==1)
		{
			cout<<"1"<<" "<<"0"<<endl;
			continue;
		}
		int maxi=0;
		vec.clear();
		fun(n);
		int s=1;
		int flag=0;
		for( i = 0 ; i < vec.size() ; i++)
		{
			s*=vec[i].first;
			if(maxi!=0&&maxi!=vec[i].second)
				flag=1;
			maxi=max(maxi,vec[i].second);
		}
		int cnt=-1;
		for( i = 1 ;  ; i<<=1)
		{
			cnt++;
			if(maxi<=i)
				break;
		}
		if((!flag&&maxi==(1<<cnt))||maxi==1)
			cout<<s<<" "<<cnt<<endl;
		else
			cout<<s<<" "<<cnt+1<<endl;
	}
    return 0;
}