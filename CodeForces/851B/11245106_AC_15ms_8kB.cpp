#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define mod 1000000007
#define pb push_back
#define MAX 70004
#define inf 1e18
#define f first
#define mp make_pair
#define pii pair<int,int>
#define s second


int main()
{
    double x1,y1,x2,y2,x3,y3,d1,d2,d3;

    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    d1=((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
    d2=((x2-x3)*(x2-x3)+(y2-y3)*(y2-y3));
    d3=((x3-x1)*(x3-x1)+(y3-y1)*(y3-y1));


    if(d1!=d2)
    {
        cout<<"NO\n";
        return 0;
    }
    if((x2-x1)*(y3-y1) == (y2-y1)*(x3-x1))
        {
		cout << "No";
		return 0;
	}
    cout<<"Yes\n";
    return 0;
}