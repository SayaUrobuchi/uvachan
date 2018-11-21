#include <stdio.h>
#include <string.h>

int group[81][4];
char chk[9];

int main()
{
	int cas, n, i, j, k, ans, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d%d", &group[i][0], &group[i][1], &group[i][2], &group[i][3]);
		}
		memset(chk, 1, sizeof(chk));
		for(i=2, ans=-1; i<n; i++)
		{
			chk[group[i][0]] = 0;
			chk[group[i][1]] = 0;
			chk[group[i][2]] = 0;
			for(j=1; j<i; j++)
			{
				if(chk[group[j][0]] && chk[group[j][1]] && chk[group[j][2]])
				{
					chk[group[j][0]] = 0;
					chk[group[j][1]] = 0;
					chk[group[j][2]] = 0;
					for(k=0; k<j; k++)
					{
						if(chk[group[k][0]] && chk[group[k][1]] && chk[group[k][2]])
						{
							temp = group[i][3] + group[j][3] + group[k][3];
							if(temp > ans)
							{
								ans = temp;
							}
						}
					}
					chk[group[j][0]] = 1;
					chk[group[j][1]] = 1;
					chk[group[j][2]] = 1;
				}
			}
			chk[group[i][0]] = 1;
			chk[group[i][1]] = 1;
			chk[group[i][2]] = 1;
		}
		printf("Case %d: %d\n", ++cas, ans);
	}
	return 0;
}
