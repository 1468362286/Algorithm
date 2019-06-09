#include <iostream>
#include <string>
using namespace std;
const int maxn = 100010;
char ch[maxn];
int main()
{
#ifdef _DEBUG
	freopen("in.txt","r",stdin);
#endif
	int i=1;
	int x=0;
	while(cin>>ch[i]&&(ch[i]>'a'||ch[i]<'z'))
	{
		if(ch[i]==ch[i-1])
		{
			i=i-2;
			x++;
		}
		i++;
	}
	if(x&1)cout<<"Yes"<<endl;
	else cout<<"No"<<endl;
	return 0;
}