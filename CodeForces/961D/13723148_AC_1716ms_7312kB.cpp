#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <time.h>
using namespace std;
const int maxn = 100010;
typedef _int64 ll;
struct Point
{
	ll x,y;
}point[maxn];
vector<ll> vec;

bool same(int i,int j,int k)
{
	return (point[j].x-point[i].x)*(point[k].y-point[i].y)-(point[k].x-point[i].x)*(point[j].y-point[i].y);
}
int main()
{
	//freopen("in.txt","r",stdin);
	srand(time(NULL));
	int n,i;
	while(cin>>n)
	{
		for( i = 0 ; i < n ; i++)
		{
			scanf("%I64d%I64d",&point[i].x,&point[i].y);
		}
		if(n<=4)
		{
			cout<<"yes"<<endl;
			continue;
		}
		while(clock()<1.7*CLOCKS_PER_SEC)
		{
			ll t1,t2;
			do{
				t1=rand()%n;
				t2=(t1*RAND_MAX+rand())%n;
				t2=rand()%n;
				t2=(t2*RAND_MAX+rand())%n;
			}
			while(t1==t2);
			for( i = 0 ; i < n ; i++)
			{
				if(same(t1,t2,i))
					vec.push_back(i);
			}
			if(vec.size()<=1)
			{
				return cout<<"yes\n",0;
			}
			else
			{
				int x=vec[0];
				int y=vec[1];
				for( i = 0 ; i < vec.size() ; i++)
				{
					if(same(x,y,vec[i]))
						break;
				}
				if(i==vec.size())
				{
					return cout<<"yes\n",0;
				}
				vec.clear();
			}

		}
		cout<<"no\n";
	}
	return 0;
}
