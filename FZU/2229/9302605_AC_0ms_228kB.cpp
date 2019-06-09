#include <iostream>
using namespace std;

int main()
{
	//freopen("in.txt","r",stdin);
	int x,y,z;
	while(scanf("%d%d%d",&x,&y,&z)!=EOF)
	{
		int ans = x*3+y*2+z*6;
		if(ans>=60)
		{
			printf("I passed the exam.\n");
			printf("%d\n",ans);
		}
		else
		{
			printf("Exam was too hard.\n");
			printf("%d\n",ans);
		}
	}
	return 0;
}