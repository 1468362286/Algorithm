#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <utility>
using namespace std;
const int maxn = 110;
const int inf = 0x7fffffff;
typedef _int64 ll;
int max(int a,int b){return a>b?a:b;}


int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin); 
#endif
	int w1,h1,w2,h2;
	while(cin>>w1>>h1>>w2>>h2)
	{
		int c = w1+w2+2*(h1+h2)+(w1-w2);
		cout<<c+4<<endl;
	}
	return 0;
}	