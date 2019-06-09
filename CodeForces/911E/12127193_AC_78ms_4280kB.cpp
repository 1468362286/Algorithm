#include <stdio.h>
#include <stack>
using namespace std;
const int N = 200010;
int n,k,a[N];
stack<int>st;

int main()
{
	while(~scanf("%d%d",&n,&k))
	{
		int cur = 1;
		st.push(N);
		st.push(n+1);
		for(int i = 0 ; i < n ; i++)
		{
			if(i<k)scanf("%d",a+i);
			else a[i] = st.top()-1;
			st.push(a[i]);
			while(st.top()==cur)
				st.pop(),cur++;
		}
		if(st.size()>1)
		{
			printf("-1\n");
		}
		else
		{
			for(int j = 0 ; j < n ; j++)
				printf("%d ",a[j]);
		}
	}
	return 0;
}
