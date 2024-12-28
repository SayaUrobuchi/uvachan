/*
ID: sa072682
LANG: C
TASK: transform
*/

#include <stdio.h>
#include <string.h>

char st[10][11], ed[10][11], res[10][11], temp[10][11];
int n, min;

char chkans()
{
	int i;
    for(i=0; i<n; i++)
	{
		if(strcmp(ed[i], res[i]))
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int i, j;
	freopen("transform.in", "r", stdin);
	freopen("transform.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%s", st[i]);
	}
	for(i=0; i<n; i++)
	{
		scanf("%s", ed[i]);
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			res[i][j] = st[n-1-j][i];
		}
	}
	if(chkans())
	{
		printf("1\n");
	}
	else
	{
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				res[i][j] = st[n-1-i][n-1-j];
			}
		}
		if(chkans())
		{
			printf("2\n");
		}
		else
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<n; j++)
				{
					res[i][j] = st[j][n-1-i];
				}
			}
			if(chkans())
			{
				printf("3\n");
			}
			else
			{
				for(i=0; i<n; i++)
				{
					for(j=0; j<n; j++)
					{
						temp[i][j] = res[i][j] = st[i][n-1-j];
					}
				}
				if(chkans())
				{
					printf("4\n");
				}
				else
				{
                    for(i=0; i<n; i++)
					{
						for(j=0; j<n; j++)
						{
							res[i][j] = temp[n-1-j][i];
						}
					}
					if(chkans())
					{
						printf("5\n");
					}
					else
					{
						for(i=0; i<n; i++)
						{
							for(j=0; j<n; j++)
							{
								res[i][j] = temp[n-1-i][n-1-j];
							}
						}
						if(chkans())
						{
							printf("5\n");
						}
						else
						{
							for(i=0; i<n; i++)
							{
								for(j=0; j<n; j++)
								{
									res[i][j] = temp[j][n-1-i];
								}
							}
							if(chkans())
							{
								printf("5\n");
							}
							else
							{
								for(i=0; i<n; i++)
								{
									strcpy(res[i], st[i]);
								}
								if(chkans())
								{
									printf("6\n");
								}
								else
								{
									printf("7\n");
								}
							}
						}
					}
				}
			}
		}
	}
	return 0;
}
