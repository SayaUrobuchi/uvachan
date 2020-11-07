#include <iostream>

char buf[1048576];

int main()
{
	int i, j, ans;
	while (scanf("%s", buf) == 1)
	{
		for (i=0, j=0, ans=0; buf[i]; i++, j++)
		{
			if (buf[i] >= 'A' && buf[i] <= 'Z')
			{
				while (j&3)
				{
					++j;
					++ans;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
