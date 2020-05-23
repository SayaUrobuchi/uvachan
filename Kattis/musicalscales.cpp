#include <stdio.h>

const int M = 12;

int able_int[] = {2, 2, 1, 2, 2, 2, 1};
int tbl[16], able[16];
int ary[1024];
const char *note = "CDEFGAB";
char nam[16][16], buf[16];

int notetoint(char *s)
{
	int res = tbl[*s];
	if (s[1] == '#')
	{
		++res;
	}
	return res;
}

int main()
{
	int n, i, j, sum, first;
	for (i=0, j=3, sum=0; i<7; sum+=able_int[i], i++)
	{
		able[sum] = 1;
		sprintf(nam[j%M], "%c", note[i]);
		tbl[note[i]] = j%M;
		j++;
		if (able_int[i] == 2)
		{
			sprintf(nam[j%M], "%c#", note[i]);
			j++;
		}
	}
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s", buf);
			ary[i] = notetoint(buf);
		}
		for (i=0, first=1; i<M; i++)
		{
			for (j=0; j<n; j++)
			{
				if (!able[(ary[j]+M-i)%M])
				{
					break;
				}
			}
			if (j >= n)
			{
				if (!first)
				{
					putchar(' ');
				}
				first = 0;
				printf("%s", nam[i]);
			}
		}
		if (first)
		{
			printf("none");
		}
		puts("");
	}
	return 0;
}
