#include <iostream>
#include <string>
using namespace std;
const int maxn = 1000010;
int n; 
int a[maxn];
int c[maxn];
int lowbit(int x){return x&(-x);}

void update(int x)
{
	while(x<=n)
	{
		c[x]++;
		x+=lowbit(x);
	}
}

int query(int t)
{
	int sum=0;
	while(t)
	{
		sum+=c[t];
		t-=lowbit(t);
	}
	return sum;
}

int main()
{
	int i;
	while(cin>>n)
	{
		for( i = 1 ; i <= n ; i++)
			cin>>a[i];
		int ans=0;
		for( i = n ; i >= 1 ; i--)
			ans+=query(a[i]-1),update(a[i]);
		if(n%2==0)
		{
			if(ans%2==0)
				cout<<"Petr"<<endl;
			else
				cout<<"Um_nik"<<endl;
		}
		else
		{
			if(ans%2==0)
				cout<<"Um_nik"<<endl;
			else
				cout<<"Petr"<<endl;
		}
	}
	return 0;
}