#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> vec;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,s,h,m,i;
	while(cin>>n>>s)
	{
		vec.clear();
		vec.push_back(0);
		for( i = 1 ; i <= n ; i++)
		{
			scanf("%d%d",&h,&m);
			vec.push_back(h*60+m);
		}
		int ans=0;
		for( i = 0 ; i <= n ; i++)
		{
			if(i==0&&1+s<=vec[1])
			{
				ans=0;
				break;
			}
			if(vec[i]+1+s+1+s<=vec[i+1]||i==n)
			{
				ans = vec[i]+1+s;
				break;
			}
		}
		cout<<ans/60<<" "<< ans%60<<endl;
	}
	return 0;
}