#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
typedef _int64 ll;
const int maxn = 300010;
const int inf = 0x3f3f3f3f;
int max(int a,int b){return a>b?a:b;}
int main()
{
	//freopen("in.txt","r",stdin);
	int n,i;
	string s,tmp;
	vector<int>vec;
	while(cin>>n)
	{
		cin>>tmp;
		int cnt=0;
		int G=0;
		vec.clear();
		s="";
		s+='S';
		s+=tmp;
		s+='S';
		for( i = 0 ; i <= n+1 ; i++)
		{
			if(s[i]=='G')
			{
				cnt++;
			}
			else
			{
				vec.push_back(cnt),G+=(cnt!=0),cnt=0;
			}
		}
		int ans=0;
		for( i = 1 ; i < vec.size() ; i++)
		{
			ans=max(ans,vec[i]+vec[i-1]+(G>(vec[i]!=0)+(vec[i-1]!=0)));
		}
		cout<<ans<<endl;
	}
	return 0;
}