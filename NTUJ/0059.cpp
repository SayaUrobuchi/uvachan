#include <stdio.h>
#include <string.h>

int ary[50], q1[2000000], q2[2000000], next[2000000], used[440][440][50];

int max(int p, int q)
{
	return p>q ? p : q;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int main()
{
	int n, i, j, v1, v2, v3, ans, sum, total;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0, total=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			total += ary[i];
		}
		sum = total;
		total /= 3;
		q1[0] = q2[0] = next[0] = 0;
		memset(used, 0, sizeof(used));
		for(i=0, j=1, ans=2147483647; i<j; i++)
		{
			if(next[i] == n)
			{
				ans = min(ans, max(q1[i], max(q2[i], sum-q1[i]-q2[i])));
				continue;
			}
			if(q1[i] <= total)
			{
				v1 = q1[i] + ary[next[i]];
				v2 = q2[i];
				v3 = next[i] + 1;
				if(used[v1][v2][v3] == 0)
				{
					used[v1][v2][v3] = 1;
					q1[j] = v1;
					q2[j] = v2;
					next[j++] = v3;
				}
			}
			if(q2[i] <= total)
			{
				v1 = q1[i];
				v2 = q2[i] + ary[next[i]];
				v3 = next[i] + 1;
				if(used[v1][v2][v3] == 0)
				{
					used[v1][v2][v3] = 1;
					q1[j] = v1;
					q2[j] = v2;
					next[j++] = v3;
				}
			}
			v1 = q1[i];
			v2 = q2[i];
			v3 = next[i] + 1;
			if(used[v1][v2][v3] == 0)
			{
				used[v1][v2][v3] = 1;
				q1[j] = v1;
				q2[j] = v2;
				next[j++] = v3;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
