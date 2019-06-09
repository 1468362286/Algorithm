//#include <stdio.h>
//#include <iostream>
//#include <math.h>
#include<bits/stdc++.h>
using namespace std;
struct Node
{
	double x,y;
	Node()
	{
		x=y=0;
	}
}node[3];

double pow1(double a,int b)
{
	double ans = 1;
	while(b--)
	{
		ans*=a;
	}
	return ans;
}
bool judge()
{
	double k1 = (node[1].x-node[0].x)*(node[2].y-node[0].y);
	double k2 = (node[1].y-node[0].y)*(node[2].x-node[0].x);
	double dis1 = pow((node[1].y-node[0].y),2)+pow((node[1].x-node[0].x),2);
	double dis2 = pow((node[1].y-node[2].y),2)+pow((node[1].x-node[2].x),2);
	if(k1==k2||dis1!=dis2)
		return false;
	else
		return true;
}

int main()
{
	//freopen("in.txt","r",stdin);
	while(~scanf("%lf%lf%lf%lf%lf%lf",&node[0].x,&node[0].y,&node[1].x,&node[1].y,&node[2].x,&node[2].y))
	{
		if(!judge())
			printf("No\n");
		else
			printf("Yes\n");
	}
	return 0;
}


