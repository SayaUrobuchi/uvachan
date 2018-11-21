#include <stdio.h>

char s[128];

int main()
{
	int n, i;
	double max, min, len;
	scanf("%d", &n);
	max = 200;
	min = 100;
	for (i=0; i<n; i++)
	{
		scanf("%s%lf", s, &len);
		if (*s == 'l')
		{
			if (len < max)
			{
				max = len;
			}
		}
		else
		{
			if (len > min)
			{
				min = len;
			}
		}
	}
	printf("%.1f %.1f\n", min, max);
	return 0;
}
