#include <stdio.h>
#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

#define fst first
#define snd second
#define pb push_back
typedef _int64 ll;
#define inf 0x3f3f3f3f

int main(){
	ios::sync_with_stdio(0);
	
	ll n;
	scanf("%I64d",&n);
	ll mx = n*(n+1)/2/2, c = 0;
	vector<ll> ans;
	for (ll i = n; i >= 1; i--)
		if (c + i <= mx){
			ans.pb(i);
			c+=i;
		}
	ll tot = n*(n+1)/2;	
	cout << abs((tot-c)-c) << endl;	
	cout << ans.size();
	for (int j = 0; j < ans.size(); j++)
		printf(" %I64d",ans[j]);
	cout<<endl;	
	return 0;
}
