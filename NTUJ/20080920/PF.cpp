#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, px[50], py[50], tx[50], ty[50], id[50], l, r, d, t;
char cmd[10000];

int comp(const void *p, const void *q)
{
	return px[*(int*)p] == px[*(int*)q] ? py[*(int*)p] - py[*(int*)q] : px[*(int*)p] - px[*(int*)q];
}

int back(int targ, int xs, int ys)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(tx[targ] + xs == tx[i] && ty[targ] + ys == ty[i])
		{
			if(back(i, xs, ys))
			{
				tx[targ] += xs;
				ty[targ] += ys;
				return 1;
			}
			return 0;
		}
	}
	if(tx[targ] + xs < t || tx[targ] + xs >= d || ty[targ] + ys < l || ty[targ] + ys >= r)
	{
		return 0;
	}
	tx[targ] += xs;
	ty[targ] += ys;
	return 1;
}

int main()
{
	int cas, i, step, xx, yy;
	cas = 0;
	while(scanf("%d%d", &xx, &yy) == 2)
	{
		d = xx;
		r = yy;
		if(d == 0 && r == 0)
		{
			break;
		}
		l = t = 0;
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			id[i] = i;
		}
		while(scanf("%s", cmd) == 1)
		{
			if(strcmp(cmd, "done") == 0)
			{
				break;
			}
			if(strcmp(cmd, "left") == 0)
			{
				scanf("%d", &step);
				while(step--)
				{
					r--;
					memcpy(tx, px, sizeof(px));
					memcpy(ty, py, sizeof(py));
					for(i=0; i<n; i++)
					{
						if(py[i] == r)
						{
							if(back(i, 0, -1) == 0)
							{
								r++;
								break;
							}
						}
					}
					if(i == n)
					{
						memcpy(px, tx, sizeof(tx));
						memcpy(py, ty, sizeof(ty));
					}
				}
				r = yy;
			}
			if(strcmp(cmd, "up") == 0)
			{
				scanf("%d", &step);
				while(step--)
				{
					d--;
					memcpy(tx, px, sizeof(px));
					memcpy(ty, py, sizeof(py));
					for(i=0; i<n; i++)
					{
						if(px[i] == d)
						{
							if(back(i, -1, 0) == 0)
							{
								d++;
								break;
							}
						}
					}
					if(i == n)
					{
						memcpy(px, tx, sizeof(tx));
						memcpy(py, ty, sizeof(ty));
					}
				}
				d = xx;
			}
			if(strcmp(cmd, "right") == 0)
			{
				scanf("%d", &step);
				while(step--)
				{
					l++;
					memcpy(tx, px, sizeof(px));
					memcpy(ty, py, sizeof(py));
					for(i=0; i<n; i++)
					{
						if(py[i] == l - 1)
						{
							if(back(i, 0, 1) == 0)
							{
								l--;
								break;
							}
						}
					}
					if(i == n)
					{
						memcpy(px, tx, sizeof(tx));
						memcpy(py, ty, sizeof(ty));
					}
				}
				l = 0;
			}
			if(strcmp(cmd, "down") == 0)
			{
				scanf("%d", &step);
				while(step--)
				{
					t++;
					memcpy(tx, px, sizeof(px));
					memcpy(ty, py, sizeof(py));
					for(i=0; i<n; i++)
					{
						if(px[i] == t - 1)
						{
							if(back(i, 1, 0) == 0)
							{
								t--;
								break;
							}
						}
					}
					if(i == n)
					{
						memcpy(px, tx, sizeof(tx));
						memcpy(py, ty, sizeof(ty));
					}
				}
				t = 0;
			}
		}
		printf("Data set %d ends with boxes at locations", ++cas);
		qsort(id, n, sizeof(int), comp);
		for(i=0; i<n; i++)
		{
			printf(" (%d,%d)", px[id[i]], py[id[i]]);
		}
		printf(".\n");
	}
	return 0;
}
