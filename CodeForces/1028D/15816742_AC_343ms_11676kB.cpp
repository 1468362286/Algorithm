#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
using namespace std;
typedef _int64 ll;
const int MOD = 1e9+7;
set<int> all;
priority_queue<int> buy;
//priority_queue<int> sell;
priority_queue<int,vector<int>,greater<int> >sell; 
ll ans=1;
int n;
void add(int t)
{
	if(sell.top()<t)
		sell.push(t);
	else if(buy.top()>t)
		buy.push(t);
	else
		all.insert(t);
}

void accept(int t)
{
	if(sell.top()<t||buy.top()>t)
		ans=0;
	else if(sell.top()==t)
		sell.pop();
	else if(buy.top()==t)
		buy.pop();
	else
	{
		ans=(ans*2)%MOD;
		all.erase(t);
	}
	set<int>::iterator it;
	for(it = all.begin() ; it!=all.end() ; it++)
	{
		if(*it<t)
			buy.push(*it);
		else
			sell.push(*it);
	}
	all.clear();
}
int main()
{
	//freopen("in.txt","r",stdin);
	buy.push(0);
	sell.push(MOD);
	scanf("%d",&n);
	char op[10];
	while(n--)
	{
		int t;
		scanf("%s %d",op,&t);
		op[1]=='D'?add(t):accept(t);
	}
	ans=ans*((int)all.size()+1)%MOD;
	printf("%I64d\n",ans);
	return 0;
}