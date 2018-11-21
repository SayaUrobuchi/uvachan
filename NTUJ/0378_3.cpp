#include <stdio.h>
#include <string.h>

int num[250], used[1005], m1[1005], m2[1005];

int main()
{
	int n, m, i, j, k, c, ans, temp;
	while(scanf("%d%d%d", &n, &m, &k) == 3)
	{
		memset(num, 0, sizeof(num));
		for(i=0; i<k; i++)
		{
			scanf("%*d%d%d", &m1[i], &m2[i]);
			num[m1[i]]++;
			num[m2[i]+=n]++;
		}
		memset(used, 0, sizeof(used));
		for(c=k, ans=0; c; )
		{
			for(i=0, j=0; i<n+m; i++)
			{
				if(num[i] > j)
				{
					j = num[i];
					temp = i;
				}
			}
			ans++;
			for(i=0; i<k; i++)
			{
				if(used[i] == 0 && (m1[i] == temp || m2[i] == temp))
				{
					c--;
					used[i] = 1;
					num[m1[i]]--;
					num[m2[i]]--;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
