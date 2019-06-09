#include <stdio.h>
#include <string.h>

int main()
{
	//freopen("in.txt", "r", stdin);
	char ch[60];
	while (~scanf("%s", ch))
	{
		int len = strlen(ch);
		int cnt = 0;
		for (int i = 0; i < len; i++)
		{
			if (ch[i] == 'a' || ch[i] == 'e' || ch[i] == 'i' || ch[i] == 'o' || ch[i] == 'u')
				cnt++;
			else if(ch[i]>='0'&&ch[i]<='9'&&(ch[i] - '0') % 2 != 0)
				cnt++;
		}
		printf("%d\n", cnt);
	}
    return 0;
}
