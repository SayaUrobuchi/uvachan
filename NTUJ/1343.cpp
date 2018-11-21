#include <stdio.h>

char buf[10000005];

int main()
{
	int count, i, ans;
	gets(buf);
	sscanf(buf, "%d", &count);
	while(count--)
	{
		gets(buf);
		for(i=0, ans=0; buf[i]; i++)
		{
			if(buf[i] == ':')
			{
				if(buf[i+1] && buf[i+1] == ')')
				{
					if(buf[i+2] && buf[i+2] == ')')
					{
						ans += 4;
						i += 2;
					}
					else
					{
						ans += 2;
						i += 1;
					}
				}
				else if(buf[i+1] && buf[i+1] == '(')
				{
					if(buf[i+2] && buf[i+2] == '(')
					{
						ans -= 5;
						i += 2;
					}
					else
					{
						ans -= 1;
						i += 1;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
