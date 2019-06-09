#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int n,m,x,i;
	while(cin>>n>>m)
	{
		vector<int>ans;
		ans.clear();
		int now=0;
		for( i = 0 ; i < n ; i++)
		{
			int t=0;
			cin>>x;
			if(now+x<m)
			{
				now+=x;
			}
			else
			{
				t+=(now+x)/m;
				now = (now+x)%m;
			}
			ans.push_back(t);
		}
		for( i = 0 ; i < n ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}