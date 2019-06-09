#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n,x,i;
	vector<int>ans;
	while(cin>>n)
	{
		int cnt=0;
		ans.clear();
		for( i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x==1)
			{
				if(cnt!=0)
					ans.push_back(cnt);
				cnt=1;
			}
			else
				cnt++;
		}
		if(cnt!=0)
		ans.push_back(cnt);
		cout<<ans.size()<<endl;
		for( i = 0 ; i < ans.size() ; i++)
			cout<<ans[i]<<" ";
		cout<<endl;
	}
	return 0;
}