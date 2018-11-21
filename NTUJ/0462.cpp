#include <stdio.h>
#include <string.h>

int q[100005], step[100005], used[100005];

int main()
{
	int n, m, i, j, l, s, next;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == m)
		{
			printf("0\n");
			continue;
		}
		q[0] = n;
		step[0] = 0;
		memset(used, 0, sizeof(used));
		used[0] = 1;
		for(i=0, j=1; i<j; i++)
		{
			l = q[i];
			s = step[i] + 1;
			next = l + 1;
			if(next <= 100000 && used[next] == 0)
			{
				if(next == m)
				{
					break;
				}
				used[next] = 1;
				q[j] = next;
				step[j++] = s;
			}
			next = l - 1;
			if(next >= 0 && used[next] == 0)
			{
				if(next == m)
				{
					break;
				}
				used[next] = 1;
				q[j] = next;
				step[j++] = s;
			}
			next = l * 2;
			if(next <= 100000 && used[next] == 0)
			{
				if(next == m)
				{
					break;
				}
				used[next] = 1;
				q[j] = next;
				step[j++] = s;
			}
		}
		printf("%d\n", s);
	}
	return 0;
}
