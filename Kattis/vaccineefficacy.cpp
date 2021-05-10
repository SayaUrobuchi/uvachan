#include <iostream>
#include <cstring>

int ary[8][4];
char s[8];

int main()
{
	int n, i, j, k;
	while (scanf("%d", &n) == 1)
	{
		memset(ary, 0, sizeof(ary));
		for (i=0; i<n; i++)
		{
			scanf("%s", s);
			k = 0;
			if (*s == 'Y')
			{
				k = 1;
			}
			++ary[0][k];
			for (j=1; j<4; j++)
			{
				if (s[j] == 'Y')
				{
					++ary[j][k];
				}
			}
		}
		for (i=1; i<4; i++)
		{
			if ((ary[i][1]*1.0/ary[0][1]) >= (ary[i][0]*1.0/ary[0][0]))
			{
				puts("Not Effective");
			}
			else
			{
				printf("%.10lf\n", (1.0-(ary[i][1]*1.0/ary[0][1])/(ary[i][0]*1.0/ary[0][0]))*100.0);
			}
		}
	}
	return 0;
}
