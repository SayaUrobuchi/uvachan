#include <stdio.h>

char s[1024];

int main()
{
	int len, b, i, val, v2, j, t;
	while (scanf("%d%s", &b, s) == 2)
	{
		for (len=0; s[len]; len++);
		for (i=0, val=0, v2=0; s[i]; val=val*b+(s[i++]-'0'))
		{
			for (j=0, t=1; j<len; j++, t*=s[i]-'0');
			v2 += t;
		}
		puts(val!=v2?"NO":"YES");
	}
	return 0;
}
