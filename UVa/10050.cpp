#include <stdio.h>
#include <string.h>

char ary[3651];

int main()
{
	int count, n, m, h, i, j, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		memset(ary, 1, ++n);
		ans = 0;
		for(i=0; i<m; i++)
		{
			scanf("%d", &h);
			for(j=h; j<n; j+=h)
			{
				if(j % 7 && j % 7 != 6)
				{
					if(ary[j])
					{
						ans++;
						ary[j] = 0;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
