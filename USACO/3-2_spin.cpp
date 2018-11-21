/*
	ID: sa072682
	LANG: C
	TASK: spin
*/
#include <stdio.h>
#include <string.h>

int speed[5], num[5], start[5][5], length[5][5], chk[5][360];

int main()
{
	int i, j, k, l;
	freopen("spin.in", "r", stdin);
	freopen("spin.out", "w", stdout);
	for(i=0; i<5; i++)
	{
		scanf("%d%d", &speed[i], &num[i]);
		for(j=0; j<num[i]; j++)
		{
			scanf("%d%d", &start[i][j], &length[i][j]);
		}
	}
	for(i=0; i<360; i++)
	{
		memset(chk, 0, sizeof(chk));
		for(j=0; j<5; j++)
		{
			for(k=0; k<num[j]; k++)
			{
				for(l=start[j][k]+i*speed[j]; l<=i*speed[j]+start[j][k]+length[j][k]; l++)
				{
					chk[j][l%360] = 1;
				}
			}
		}
		for(j=0; j<360; j++)
		{
			for(k=0; k<5; k++)
			{
				if(!chk[k][j])
				{
					break;
				}
			}
			if(k == 5)
			{
				break;
			}
		}
		if(j < 360)
		{
			break;
		}
	}
	if(i == 360)
	{
		printf("none\n");
	}
	else
	{
		printf("%d\n", i);
	}
	scanf(" ");
	return 0;
}
