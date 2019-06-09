#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
const int maxn = 100010;
vector<int> a;
int main()
{
	int n,x;
	while(cin>>n)
	{
		a.clear();
		for(int i = 0 ; i < n ; i++)
		{
			cin>>x;
			if(x!=0)a.push_back(x);
		}
		sort(a.begin(),a.end());
		int ans = unique(a.begin(),a.end())-a.begin();
		cout<<ans<<endl;
	}
	return 0;
}