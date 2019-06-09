#pragma comment(linker, "/STACK:102400000,102400000")
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string A="What are you doing at the end of the world? Are you busy? Will you save us?";
string B="What are you doing while sending \"";//zz转义符号
string C="\"? Are you busy? Will you send \""; 
string D="\"?";
typedef _int64 ll;
const int maxn = 100010;
ll k;
ll len[maxn];
ll la=75,lb=34,lc=32,ld=2;

void init()
{
	len[0]=la;
	for(int i = 1 ;  i <= 100000 ; i++)
	{
		if(i<54)
		len[i]=(ll(1)<<i)*la+((ll(1)<<i)-1)*(lb+lc+ld);
		else
			len[i]=9e18;
	}
}
void dfs(int n,ll pos)
{
	/*
	if(pos>=len[n])
	{
		cout<<".";
		return;
	}
	*/
	if(n==0)
	{
		cout<<A[pos-1];
		return;
	}
	if(pos>=1&&pos<=lb)
	{
		cout<<B[pos-1];
		return;
	}
	else if(pos>=lb+len[n-1]+1&&pos<=lb+len[n-1]+lc)
	{
		cout<<C[pos-(lb+len[n-1]+1)];
	}
	else if(pos>=lb+2*len[n-1]+lc+1&&pos<=lb+2*len[n-1]+lc+ld)
	{
		cout<<D[pos-(lb+2*len[n-1]+lc+1)];
	}
	else if(pos>=lb+1&&pos<=lb+len[n-1])
	{
		dfs(n-1,pos-lb);
	}
	else if(pos>=lb+len[n-1]+lc+1&&pos<=lb+2*len[n-1]+lc)
	{
		dfs(n-1,pos-(lb+len[n-1]+lc));
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	int q,n;
	cin>>q;
	init();
	while(q--)
	{
		scanf("%d%I64d",&n,&k);
		if(k>len[n])
			cout<<".";
		else
		{
			dfs(n,k);
		}
	}
	cout<<endl;
	return 0;
}