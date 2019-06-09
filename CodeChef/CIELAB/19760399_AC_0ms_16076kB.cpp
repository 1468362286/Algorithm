#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a,b;
	while(cin>>a>>b)
	{
	    int c = a-b;
	    int tmp = c%10;
	    if(tmp==9)
	        cout<<c-1<<endl;
	    else if(tmp==0)
	        cout<<c+1<<endl;
	    else
	        cout<<c+1<<endl;
	}
	return 0;
}