#include <iostream>

char s[1024];

int main()
{
	int count, i, t, u, r, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (i=0, t=0, ans=0; s[i]; i++)
		{
			t = (t*10) + (s[i]-'0');
			for (u=t, r=0; u; ++r, u-=u&-u);
			if (r > ans)
			{
				ans = r;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
