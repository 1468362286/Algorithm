#include <iostream>
#include <string>
using namespace std;
int n,k;
string s;
int vist[400010];

void solve()
{
	int i;
	memset(vist,0,sizeof(vist));
	char ch='a';
	int flag;
	while(k)
	{
		flag=0;
		while(1)
		{
			for( i = 0 ; i < n ; i++)
			{
				if(!vist[i])
				{
					if(s[i]==ch)
					{
						vist[i]=1;
						flag=1;
						k--;
						if(k==0)
							return;
					}
				}
			}
			if(flag==1)
				break;
			else
				ch++;
		}
		/*
		for( i = 0 ; i < n ; i++)
			if(!vist[i])
				cout<<s[i];
		cout<<endl;*/
	}
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>n>>k)
	{
		cin>>s;
		solve();
		for(int i = 0 ; i < n ; i++)
			if(!vist[i])
				cout<<s[i];
		cout<<endl;
	}
	return 0;
}