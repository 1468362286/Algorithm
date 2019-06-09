#include <iostream>
#include <string>
using namespace std;
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	string s;
	int n,k,l,r,i;
	while(cin>>n>>k)
	{
		cin>>s;
		r=0,l=0;
		int cnt=0;
		int maxi=-1;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]!='a')
			{
				if(cnt<k)
				{
					r++;
					cnt++;
				}
				else
				{
					while(l<s.size()&&s[l]!='b')
						l++;
					l++;
					r++;
				}
			}
			else 
				r++;
			maxi=max(maxi,r-l);
		}
		l=0,r=0,cnt=0;
		for( i = 0 ; i < s.size() ; i++)
		{
			if(s[i]!='b')
			{
				if(cnt<k)
				{
					r++;
					cnt++;
				}
				else
				{
					while(l<s.size()&&s[l]!='a')
						l++;
					l++;
					r++;
				}
			}
			else 
				r++;
			maxi=max(maxi,r-l);
		}
		printf("%d\n",maxi);
	}
	return 0;
}
