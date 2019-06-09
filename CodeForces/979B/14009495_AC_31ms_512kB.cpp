#include <iostream>
#include <string>
using namespace std;
int min(int a,int b){return a>b?b:a;}
int n;
int Hash[300];
int solve(string s)
{
	memset(Hash,0,sizeof(Hash));
	char ansi;
	int maxi = 0;
	for(int i = 0 ; i < s.size() ; i++)
	{
		Hash[s[i]]++;
		if(maxi<Hash[s[i]])
		{
			maxi = Hash[s[i]];
			ansi = s[i];
		}
	}
	if(maxi==s.size()&&n==1)
		return maxi-1;
	else
		return min(n+maxi,s.size());
}
int main()
{
	//freopen("in.txt","r",stdin);
	string s1,s2,s3;
	while(cin>>n)
	{
		cin>>s1>>s2>>s3;
		int a = solve(s1);
		int b = solve(s2);
		int c = solve(s3);
		if(a>b&&a>c)
		{
			printf("Kuro\n");
		}
		else if(b>a&&b>c)
		{
			printf("Shiro\n");
		}
		else if(c>a&&c>b)
		{
			printf("Katie\n");
		}
		else
			printf("Draw\n");
	}
	return 0;
}