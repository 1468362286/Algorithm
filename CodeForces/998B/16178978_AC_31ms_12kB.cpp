#include <iostream>
#include <string>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
int a[110];
vector<int>vec;
int main()
{
//	freopen("in.txt","r",stdin);
	int n,k,i;
	while(cin>>n>>k)
	{
		vec.clear();
		for( i = 0 ; i < n ; i++)
			cin>>a[i];
		int l=0,r=0;
		int ans=0;
		for( i = 0 ; i < n-1 ; i++)
		{
			if(a[i]%2==0)
				l++;
			else
				r++;
			if(l==r&&l!=0)
			{
				vec.push_back(abs(a[i+1]-a[i]));
			}
		}
		sort(vec.begin(),vec.end());
		int sum=0;
		int flag=0;
		for( i = 0 ; i < vec.size() ; i++)
		{
			sum+=vec[i];
			if(sum>k)
			{
				flag=1;
				ans=i;
				break;
			}
		}
		if(!flag)
			cout<<vec.size()<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}