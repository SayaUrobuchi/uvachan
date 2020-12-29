#include <iostream>
#include <cstring>

char s[1024], cur[1024], buf[1024];

int fix(char *cur, char *tar)
{
	int n, m, i;
	n = strlen(tar);
	m = strlen(cur);
	for (i=0; cur[i]&&tar[i]&&cur[i]==tar[i]; i++);
	return m-i+(n-i);
}

int main()
{
	int count, i, t, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%s", s, cur);
		ans = fix(cur, s);
		for (i=0; i<3; i++)
		{
			scanf("%s", buf);
			t = fix(buf, s) + 1;
			if (t < ans)
			{
				ans = t;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
