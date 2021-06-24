#include <iostream>

int able[] = {24, 60, 60}, mul[] = {60*60, 60, 1};
int ucnt, tbl[131072];
int cnt[4], num[4][128];
char buf[1024];

int main()
{
	int n, i, j, k, l, sum, uniq, a, b, c;
	char *p;
	while (scanf("%d", &n) == 1)
	{
		++ucnt;
		for (l=0, sum=0, uniq=0; l<n; l++)
		{
			for (j=0; j<3; j++)
			{
				scanf("%s", buf);
				cnt[j] = 0;
				p = buf;
				if (*p == '*')
				{
					for (k=0; k<able[j]; k++)
					{
						num[j][cnt[j]] = k;
						++cnt[j];
					}
				}
				else
				{
					while (*p)
					{
						if (sscanf(p, "%d-%d%n", &a, &b, &c) == 2)
						{
							for (k=a; k<=b; k++)
							{
								num[j][cnt[j]] = k;
								++cnt[j];
							}
						}
						else
						{
							sscanf(p, "%d%n", &a, &c);
							num[j][cnt[j]] = a;
							++cnt[j];
						}
						p += c;
						if (!*p)
						{
							break;
						}
						++p;
					}
				}
			}
			for (i=0; i<cnt[0]; i++)
			{
				a = num[0][i] * mul[0];
				for (j=0; j<cnt[1]; j++)
				{
					b = num[1][j] * mul[1];
					for (k=0; k<cnt[2]; k++)
					{
						c = num[2][k] * mul[2];
						if (tbl[a+b+c] != ucnt)
						{
							++uniq;
							tbl[a+b+c] = ucnt;
						}
						++sum;
					}
				}
			}
		}
		printf("%d %d\n", uniq, sum);
	}
	return 0;
}
