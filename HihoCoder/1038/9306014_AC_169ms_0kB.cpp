#include <iostream>
#include <string>
using namespace std;
#define max(a,b) (a>b?a:b)
int need[501],value[501];
int best[100001];

int main()
{
	//freopen("in.txt","r",stdin);
	int N,M,i,j;
	cin>>N>>M;
	for(i = 1 ; i <= N ; i++)
	{
		cin>>need[i]>>value[i];
	}
	for( j = 0 ; j <= M ; j++)
		best[j] = 0;
	for( i = 1 ; i <= N ; i++)
		for( j = M ; j >= need[i] ; j--)
				best[j] = max(best[j],best[j-need[i]]+value[i]);
	cout<<best[M]<<endl;
	return 0;
}

