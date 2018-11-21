/*
ID: sa072682
LANG: C
TASK: beads
*/

#include <stdio.h>

int main()
{
	int n, i, w, btmp, bnum, lasttmp, last, last2, max;
	char str[351], color;
	freopen("beads.in", "r", stdin);
	freopen("beads.out", "w", stdout);
	scanf("%d%s", &n, str);
	color = 0;
	w = 0;
	btmp = 0;
	bnum = 0;
	max = 0;
	for(i=0; i<n; i++)
	{
		if(str[i] == 'w')
		{
			w++;
		}
		else
		{
			if(str[i] != color)
			{
				color = str[i];
				/*printf("%d %d\n", i, btmp + bnum + w);*/
				if(btmp + bnum + w > max)
				{
					max = btmp + bnum + w;
				}
				btmp = bnum;
				bnum = w;
				w = 0;
			}
			bnum += w + 1;
			w = 0;
		}
	}
	/*printf("%d\n", lasttmp);*/
	/*printf("%d %d %d\n", btmp, bnum, w);*/
	for(i=0; i<n; i++)
	{
		if(btmp + bnum + w > n) break;
		if(str[i] == 'w')
		{
			w++;
		}
		else
		{
			if(str[i] != color)
			{
				color = str[i];
				/*printf("%d %d\n", i, btmp + bnum + w);*/
				if(btmp + bnum + w > max)
				{
					max = btmp + bnum + w;
				}
				btmp = bnum;
				bnum = w;
				break;
			}
			bnum += w + 1;
			w = 0;
		}
	}
	if(btmp + bnum + w > max)
	{
		max = btmp + bnum + w;
	}
	max = max > n ? n : max;
	printf("%d\n", max);
	/*while('¯ù');*/
	return 0;
}
