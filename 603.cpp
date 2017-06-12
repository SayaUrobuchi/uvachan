#include <stdio.h>

int orig[25];
int loc[25];
int used[25];
char str[25];

int main()
{
	int count, n, i, temp, ntemp, mtemp, maxnum, nearest;
	scanf("%d", &count);
	while(count--)
	{
		n = 0;
		while(scanf("%d", &temp) == 1)
		{
			if(temp == 99)
			{
				break;
			}
			orig[n] = temp;
			loc[n] = temp - 1;
			used[n++] = 0;
		}
		gets(str);
		while(gets(str))
		{
			if(sscanf(str, "%d", &temp) != 1)
			{
				break;
			}
			temp--;
			for(i=0, nearest=-1, maxnum=-1; i<n; i++)
			{
				if(!used[i])
				{
					if(loc[i] > maxnum)
					{
						maxnum = loc[i];
						mtemp = i;
					}
					if(loc[i] <= temp && loc[i] > nearest)
					{
						nearest = loc[i];
						ntemp = i;
					}
				}
			}
			if(nearest != -1)
			{
				used[ntemp] = 1;
				loc[ntemp] = temp + 1;
				temp -= nearest;
				for(i=0; i<n; i++)
				{
					if(!used[i])
					{
						loc[i] += temp;
						if(loc[i] > 19)
						{
							loc[i] -= 20;
						}
					}
				}
			}
			else if(maxnum != -1)
			{
				used[mtemp] = 1;
				loc[mtemp] = temp + 1;
				temp += 20 - maxnum;
				for(i=0; i<n; i++)
				{
					if(!used[i])
					{
						loc[i] += temp;
						if(loc[i] > 19)
						{
							loc[i] -= 20;
						}
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			if(used[i])
			{
				printf("Original position %d parked in %d\n", orig[i], loc[i]);
			}
			else
			{
				printf("Original position %d did not park\n", orig[i]);
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
