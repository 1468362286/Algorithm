#include <stdio.h>
#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <math.h>
#include <algorithm>
#include <time.h>
using namespace std;
const int inf = 0x3f3f3f3f;
template<class T> static T Max(T a,T b){return a>b?a:b;}
template<class T> static T Min(T a,T b){return a>b?b:a;}

int main()
{
	srand(time(NULL));	
	int n;
	while(cin>>n)
	{
		if(n%2==0)
			printf("0");
		else
			printf("1");
	//	printf("%d",rand()%2);
	//	printf("helloworld\n");
	}
	return 0;
}