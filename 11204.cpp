#include <stdio.h>
#include <string.h>

int ary[32];

int main()
{
	int count, i, n, m, in, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(ary, 0, sizeof(ary));
		while(m--)
		{
			for(i=0; i<n; i++)
			{
				scanf("%d", &in);
				if(in == 1)
				{
					ary[i]++;
				}
			}
		}
		for(i=0, ans=1; i<n; i++)
		{
			if(ary[i] > 1)
			{
				ans *= ary[i];
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
