#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
vector<int> vec;
int n;
string s;

void solve()
{
	int i;
	vec.clear();
	for( i = 1 ; i<=n ; i++)
	{
		if(n%i==0)
			vec.push_back(i);
	}
	for( i = 0 ; i < vec.size() ; i++)
	{
		int d = vec[i];
		reverse(s.begin(),s.begin()+d);
	//	cout<<d<<" "<<s<<endl;
	}
}
int main()
{
	//freopen("in.txt","r",stdin);
	while(cin>>n)
	{
		cin>>s;
		solve();
		cout<<s<<endl;
	}
	return 0;
}