#include <iostream>

int ucnt;
int tbl[16384], qq[16384], qs[16384], used[16384];
char buf[16];

int main()
{
	int count, i, j, k, l, st, ed, cur, nxt, a;
	for (i=2; i*i<=9999; i++)
	{
		if (!tbl[i])
		{
			for (j=i*i; j<=9999; j+=i)
			{
				tbl[j] = 1;
			}
		}
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &st, &ed);
		qq[0] = st;
		qs[0] = 0;
		used[st] = ++ucnt;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			if (cur == ed)
			{
				break;
			}
			sprintf(buf, "%d", cur);
			for (k=0; k<4; k++)
			{
				for (l=0; l<=9; l++)
				{
					if (k+l && buf[k] != l+'0')
					{
						for (a=0, nxt=0; a<4; a++)
						{
							nxt = nxt*10 + (a==k?l:buf[a]-'0');
						}
						if (used[nxt] != ucnt && !tbl[nxt])
						{
							used[nxt] = ucnt;
							qq[j] = nxt;
							qs[j] = qs[i] + 1;
							j++;
						}
					}
				}
			}
		}
		if (i < j)
		{
			printf("%d\n", qs[i]);
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}
