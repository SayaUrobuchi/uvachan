#include <stdio.h>

char map[500][501];

int main()
{
	int count, n, m, i, j, k, ud, now, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		gets(map[0]);
		for(i=0; i<n; i++)
		{
			gets(map[i]);
		}
		for(k=0, ans=0; k<m; k++)
		{
			i = 0;
			j = k;
			ud = 1;
			while(1)
			{
				now = map[i][j];
				if(now == '\\')
				{
					if(ud)
					{
						j++;
						if(j == m)
						{
							break;
						}
					}
					else
					{
						j--;
						if(j == -1)
						{
							break;
						}
					}
					now = map[i][j];
					if(now == '\\')
					{
						if(ud)
						{
							i++;
							if(i == n)
							{
								ans++;
								break;
							}
						}
						else
						{
							i--;
							if(i == -1)
							{
								break;
							}
						}
					}
					else
					{
						if(ud)
						{
							i--;
							if(i == -1)
							{
								break;
							}
							ud = 0;
						}
						else
						{
							i++;
							if(i == n)
							{
								ans++;
								break;
							}
							ud = 1;
						}
					}
				}
				else
				{
                    if(ud)
					{
						j--;
						if(j == -1)
						{
							break;
						}
					}
					else
					{
						j++;
						if(j == m)
						{
							break;
						}
					}
					now = map[i][j];
					if(now == '/')
					{
						if(ud)
						{
							i++;
							if(i == n)
							{
								ans++;
								break;
							}
						}
						else
						{
							i--;
							if(i == -1)
							{
								break;
							}
						}
					}
					else
					{
						if(ud)
						{
							i--;
							if(i == -1)
							{
								break;
							}
							ud = 0;
						}
						else
						{
							i++;
							if(i == n)
							{
								ans++;
								break;
							}
							ud = 1;
						}
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
