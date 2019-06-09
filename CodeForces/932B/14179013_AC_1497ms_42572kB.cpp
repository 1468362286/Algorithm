#include <iostream>
#include <string>
using namespace std;
int pre_sum[10][1000010];
int fun_f(int x)
{
	int ans=1;
	while(x)
	{
		int tmp=x%10;
		if(tmp!=0)
		{
			ans*=tmp;
		}
		x/=10;
	}
	return ans;
}

int fun_g(int x)
{
	if(x<10)
		return x;
	else
		return fun_g(fun_f(x));
}

void init()
{
	memset(pre_sum,0,sizeof(pre_sum));
	for(int k = 1 ; k <= 9 ; k++)
	{
		for(int i = 1 ; i <= 1000000 ; i++)
			pre_sum[k][i]=pre_sum[k][i-1]+(fun_g(i)==k);
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	int	q,i,l,r,k;
	cin>>q;
	init();
	while(q--)
	{
		cin>>l>>r>>k;
		int ans=0;
		ans=pre_sum[k][r]-pre_sum[k][l-1];
		cout<<ans<<endl;
	}
	return 0;
}