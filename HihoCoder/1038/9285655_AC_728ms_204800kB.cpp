#include <iostream>
#include <string>
using namespace std;
#define max(a,b) (a>b?a:b)
int need[501],value[501];
int best[501][100001];

int main()
{
//	freopen("in.txt","r",stdin);
	int N,M,i,j;
	cin>>N>>M;
	for(i = 1 ; i <= N ; i++)
	{
		cin>>need[i]>>value[i];
	}
	for( j = 0 ; j <= M ; j++)
		best[0][j] = 0;
	for( i = 1 ; i <= N ; i++)
		for( j = 0 ; j <= M ; j++)
			if(j < need[i])
				best[i][j] = best[i-1][j];
			else
				best[i][j] = max(best[i-1][j],best[i-1][j-need[i]]+value[i]);
	cout<<best[N][M]<<endl;
	return 0;
}