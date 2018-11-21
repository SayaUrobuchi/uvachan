#include <stdio.h>
#include <string.h>

char chk[10000];
int queue[10000], step[10000];

int main()
{
	int count, i, j, k, l, m, n, p, q, s, t, x;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d%d%d%d", &i, &j, &k, &l, &m, &n, &p, &q);
		s = i * 1000 + j * 100 + k * 10 + l;
		t = m * 1000 + n * 100 + p * 10 + q;
		memset(chk, 1, sizeof(chk));
		chk[s] = 0;
		scanf("%d", &m);
		while(m--)
		{
			scanf("%d%d%d%d", &i, &j, &k, &l);
			chk[i*1000+j*100+k*10+l] = 0;
		}
		if(s == t)
		{
			printf("0\n");
			continue;
		}
		queue[0] = s;
		step[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			k = queue[i];
			x = step[i] + 1;
			m = k / 1000;
			n = (k % 1000) / 100;
			p = (k % 100) / 10;
			q = k % 10;
			if(m == 9)
			{
				l = k - 9000;
			}
			else
			{
				l = k + 1000;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
			if(!m)
			{
				l = k + 9000;
			}
			else
			{
				l = k - 1000;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
			if(n == 9)
			{
				l = k - 900;
			}
			else
			{
				l = k + 100;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
			if(!n)
			{
				l = k + 900;
			}
			else
			{
				l = k - 100;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
			if(p == 9)
			{
				l = k - 90;
			}
			else
			{
				l = k + 10;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
			if(!p)
			{
				l = k + 90;
			}
			else
			{
				l = k - 10;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
			if(q == 9)
			{
				l = k - 9;
			}
			else
			{
				l = k + 1;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
			if(!q)
			{
				l = k + 9;
			}
			else
			{
				l = k - 1;
			}
			if(chk[l])
			{
				if(l == t)
				{
					break;
				}
				chk[l] = 0;
				step[j] = x;
				queue[j++] = l;
			}
		}
		if(i == j)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", x);
		}
	}
	return 0;
}
