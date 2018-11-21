#include <stdio.h>
#include <string.h>

int len;
int back[50000007];
char s[50000007];

int main()
{
	int i, p, ans;
	while (scanf("%s", s) == 1)
	{
		back[0] = -1;
		p = 0;
		for (i=1; s[i]; i++)
		{
			back[i] = p;
			//printf("back[%d] = %d\n", i, p);
			while (p >= 0 && s[p] != s[i])
			{
				p = back[p];
			}
			++p;
		}
		//printf("%d\n", p);
		ans = i;
		if (p == back[i-1]+1 && i%(i-1-back[i-1]) == 0)
		{
			ans = i-1-back[i-1];
		}
		printf("%.*s\n", ans, s);
	}
	return 0;
}
