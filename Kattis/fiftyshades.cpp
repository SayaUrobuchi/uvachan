#include <stdio.h>

const char *pink = "pink", *rose = "rose";
char s[1048576];

int main()
{
	int n, i, j, a, b, ans, res, msk;
	for (i=0, a=0, b=0; i<4; i++)
	{
		a = a*27 + (pink[i]-'a');
		b = b*27 + (rose[i]-'a');
	}
	msk = 27*27*27*27;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%s", s);
			for (j=0, res=0; s[j]; j++)
			{
				res = (res*27+((s[j]|32)-'a')) % msk;
				if (res == a || res == b)
				{
					ans++;
					break;
				}
			}
		}
		if (ans)
		{
			printf("%d\n", ans);
		}
		else
		{
			puts("I must watch Star Wars with my daughter");
		}
	}
	return 0;
}
