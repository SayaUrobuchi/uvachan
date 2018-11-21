#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[45][2000][2], num[45], stack[2000], stack2[2000], c[45], ans[2000], m;
char chk[1996];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int comp(const void *p, const void *q)
{
	return ((int*)p)[1] - ((int*)q)[1];
}

void push(int now)
{
	stack[m++] = now;
}

char pop()
{
	if(!m)
	{
		return 0;
	}
	return stack[--m];
}

int main()
{
	int n, o, i, j, k, l, s, now;
	char ch;
	while(scanf("%d%d", &i, &j) == 2)
	{
		if(!i && !j)
		{
			break;
		}
		n = 0;
		s = min(i, j);
		memset(num, 0, sizeof(num));
		memset(c, 0, sizeof(c));
		do
		{
			scanf("%d", &k);
			map[i][num[i]][0] = j;
			map[j][num[j]][0] = i;
			n = max(n, max(i, j));
			map[i][num[i]++][1] = k;
			if(i != j)
			{
				map[j][num[j]++][1] = k;
			}
			c[i]++;
			c[j]++;
		}while(scanf("%d%d", &i, &j) == 2 && i && j);
		for(i=1; i<=n; i++)
		{
			if(c[i] % 2)
			{
				break;
			}
		}
		if(i <= n)
		{
			printf("Round trip does not exist.\n\n");
		}
		else
		{
			for(i=1; i<=n; i++)
			{
				qsort(map[i][0], num[i], sizeof(map[0][0]), comp);
			}
			memset(c, 0, sizeof(c));
			memset(chk, 1, sizeof(chk));
			l = m = o = 0;
			push(s);
			while(now=pop())
			{
				for(ch=1; c[now]<num[now]; c[now]++)
				{
					if(chk[map[now][c[now]][1]])
					{
						chk[map[now][c[now]][1]] = 0;
						stack2[o++] = map[now][c[now]][1];
						push(now);
						push(map[now][c[now]][0]);
						c[now]++;
						ch = 0;
						break;
					}
				}
				if(ch)
				{
					if(o)
					{
						ans[l++] = stack2[--o];
					}
				}
			}
			printf("%d", ans[l-1]);
			for(i=l-2; i>-1; i--)
			{
				printf(" %d", ans[i]);
			}
			printf("\n\n");
		}
	}
	return 0;
}
