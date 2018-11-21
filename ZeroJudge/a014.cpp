#include <stdio.h>
#include <string.h>

int map[9][9];
int tbl[10];

int main()
{
	int i, j, p, q;
	while(scanf("%d", &map[0][0]) == 1)
	{
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				if(i || j)
				{
					scanf("%d", &map[i][j]);
				}
			}
		}
		for(i=0; i<9; i++)
		{
			memset(tbl, 0, sizeof(tbl));
			for(j=0; j<9; j++)
			{
				if(tbl[map[i][j]])
				{
					break;
				}
				tbl[map[i][j]] = 1;
			}
			if(j < 9)
			{
				break;
			}
		}
		if(i == 9)
		{
			for(i=0; i<9; i++)
			{
				memset(tbl, 0, sizeof(tbl));
				for(j=0; j<9; j++)
				{
					if(tbl[map[j][i]])
					{
						break;
					}
					tbl[map[j][i]] = 1;
				}
				if(j < 9)
				{
					break;
				}
			}
			if(i == 9)
			{
				for(i=0; i<9; i+=3)
				{
					for(j=0; j<9; j+=3)
					{
						memset(tbl, 0, sizeof(tbl));
						for(p=0; p<3; p++)
						{
							for(q=0; q<3; q++)
							{
								if(tbl[map[i+p][j+q]])
								{
									break;
								}
								tbl[map[i+p][j+q]] = 1;
							}
							if(q < 3)
							{
								break;
							}
						}
						if(p < 3)
						{
							break;
						}
					}
					if(j < 9)
					{
						break;
					}
				}
				if(i == 9)
				{
					printf("yes\n");
				}
				else
				{
					printf("no\n");
				}
			}
			else
			{
				printf("no\n");
			}
		}
		else
		{
			printf("no\n");
		}
	}
	return 0;
}
