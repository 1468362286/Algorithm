#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
int main()
{
    int t,n;
    cin>>t;
    while(t--)
	{
        cin>>n;
        if(n==1){cout<<"1"<<endl; continue;}
        int k=sqrt(2*(n-1));
        for(int i=k;;i++)
		{
            if(i*(i+1)==2*(n-1))
			{
                cout<<"1"<<endl;
                break;
            }
            if(i*(i+1)>2*(n-1)){
                cout<<"0"<<endl;
                break;
            }
        }

    }
    return 0;
}


