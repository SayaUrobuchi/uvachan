#include <stdio.h>

char w0[1048576], w1[1048576];

int main()
{
	int n, i, prev, cur;
	while (scanf("%d", &n) == 1)
	{
		scanf("%s%s", w0, w1);
		for (i=0, prev=3; i<n; i++)
		{
			cur = ((w0[i]-'0') | ((w1[i]-'0') << 1));
			if (!(cur & prev))
			{
				break;
			}
			prev = cur;
		}
		puts(i<n?"FENESTRATION FORTIFICATION FAILURE!":"FENDED OFF!");
	}
	return 0;
}
