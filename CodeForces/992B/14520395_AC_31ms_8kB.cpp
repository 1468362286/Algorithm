#include <iostream>
#include <string>
using namespace std;
typedef _int64 ll;
int gcd(int a,int b){return b==0?a:gcd(b,a%b);}
int main()
{
	//freopen("in.txt","r",stdin);
	int l,r,x,y;
	while(cin>>l>>r>>x>>y)
	{
		if(y%x!=0)
		{
			cout<<"0"<<endl;
			break;
		}

		int sum = y/x;
		int cnt=0;
		int to = (r%x==0?r/x:r/x+1);
		for(int i = (l%x==0?l/x:l/x+1) ; i <= r/x ; i++)
		{
			if(sum<i)
				break;
			if(sum%i==0)
			{
				int d = sum/i;
				if(i>d)
					break;
				if(gcd(i,d)==1)
				{
					if(d<=r/x)
					{
						if(d==i)
							cnt++;
						else
							cnt+=2;
					}
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}