#include <stdio.h>
#include <string.h>

int front[10], right[10];
int used[10];
int map[10][10];

int main()
{
	int count, n, i, j, k, minblock, extra;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &front[i]);
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &right[i]);
		}
		memset(used, 0, sizeof(used));
		memset(map, 0, sizeof(map));
		for(i=0, minblock=0; i<n; i++)
		{
			if(right[i])
			{
				for(j=0; j<n; j++)
				{
					if(front[j] == right[i] && !used[j])
					{
						minblock += (used[j] = map[j][i] = right[i]);
						break;
					}
				}
				if(j == n)
				{
					for(j=0; j<n; j++)
					{
						if(front[j] >= right[i])
						{
							minblock += (map[j][i] = right[i]);
							break;
						}
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			if(front[i] && !used[i])
			{
				for(j=0; j<n; j++)
				{
					if(right[j] >= front[i])
					{
						minblock += (map[i][j] = front[i]);
						break;
					}
				}
			}
		}
		for(i=0, extra=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				for(k=map[i][j]+1; front[i]>=k&&right[j]>=k; k++, extra++);
			}
		}
		printf("Matty needs at least %d blocks, and can add at most %d extra blocks.\n", minblock, extra);
	}
	return 0;
}
