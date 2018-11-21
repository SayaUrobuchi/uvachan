#include <stdio.h>

char s[1048576];

int main()
{
	int i, cc, mx, ans;
	while (gets(s))
	{
		cc = 0;
		mx = 0;
		for (i=0; ; i++)
		{
			if (s[i] == ' ')
			{
				++cc;
			}
			else
			{
				if (cc > mx)
				{
					mx = cc;
				}
				cc = 0;
			}
			if (!s[i])
			{
				break;
			}
		}
		ans = 0;
		while (mx > 1)
		{
			mx = ((mx+1)>>1);
			++ans;
		}
		printf("%d\n", ans);
	}
	return 0;
}
