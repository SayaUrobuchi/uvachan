#include <stdio.h>
#include <string.h>

int n, m, used[101], start[101], step[101], queue[101];

int gcd(int p, int q)
{
	if(p % q)
	{
		return gcd(q, p%q);
	}
	return q;
}

int arrive(int x, int y, int t)
{
	return t >= x && (t-x) % y == 0;
}

int connect(int x1, int y1, int x2, int y2)
{
	int i, temp;
	if((x1-x2) % gcd(y1, y2))
	{
		return 0;
	}
	if(y1 < y2)
	{
		temp = x1;
		x1 = x2;
		x2 = temp;
		temp = y1;
		y1 = y2;
		y2 = temp;
	}
	for(i=x1; i<x2; i+=y1);
	for(; i<m&&(i-x2)%y2; i+=y1);
	return i < m;
}

int main()
{
	int count, i, s, t, p, q, now;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d", &m, &n, &s, &t);
		memset(used, 0, sizeof(used));
		for(i=0, q=0; i<n; i++)
		{
			scanf("%d%d", &step[i], &start[i]);
			if(arrive(start[i], step[i], s))
			{
				queue[q++] = i;
				used[i] = 1;
			}
		}
		for(p=0; p<q; p++)
		{
			now = queue[p];
			if(arrive(start[now], step[now], t))
			{
				break;
			}
			for(i=0; i<n; i++)
			{
				if(!used[i])
				{
					if(connect(start[now], step[now], start[i], step[i]))
					{
						used[i] = 1;
						queue[q++] = i;
					}
				}
			}
		}
		if(p == q)
		{
			printf("The furniture cannot be moved.\n");
		}
		else
		{
			printf("It is possible to move the furniture.\n");
		}
	}
	return 0;
}
