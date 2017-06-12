#include <stdio.h>

char s[105];

int main()
{
	int count, n, last, ans, i, cas;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%s", &n, s);
		last = -2;
		ans = 0;
		for(i=0; s[i]; i++)
		{
			if(s[i] == '.' && last+1 < i)
			{
				ans++;
				last = i+1;
			}
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
