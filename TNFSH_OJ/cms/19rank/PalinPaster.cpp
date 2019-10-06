#include <stdio.h>
#include <string.h>
#include <algorithm>

char buf[200005], buf2[200005];
int jmp[200005];

int main()
{
	int n, i, j;
	while (scanf("%d", &n) == 1)
	{
		scanf("%s", buf);
		strcpy(buf2, buf);
		std::reverse(buf, buf+n);
		jmp[0] = -1;
		for (i=1, j=0; i<n; i++, j++)
		{
			jmp[i] = j;
			while (j && buf[i] != buf[j])
			{
				j = jmp[j];
			}
		}
		for (i=0, j=0; i<n; i++, j++)
		{
			while (j >= 0 && buf2[i] != buf[j])
			{
				j = jmp[j];
			}
		}
		printf("%d\n", n-j);
	}
	return 0;
}
