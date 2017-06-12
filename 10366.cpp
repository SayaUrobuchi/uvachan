#include <stdio.h>
#include <string.h>

#define LEFT 0
#define RIGHT 1

int lim;
int cap[1010];
int divider[1010];

void fill(int height, int left, int right)
{
	int i;
	for(i=left; i<right; i++)
	{
		if(cap[i] < height)
		{
			cap[i] = height;
		}
	}
}

int getremain(int from, int limit, int dir)
{
	int i, j, hmax, remain, temp;
	if(dir == LEFT)
	{
		if(limit != -1)
		{
			/*printf("from %d, limit %d, divider[from] %d\n", from, limit, divider[from]);*/
			return (from-limit+1) * divider[from+1];
		}
		for(remain=0; from>limit; )
		{
			for(i=from, hmax=0; i>limit; i--)
			{
				if(divider[i] >= hmax)
				{
					hmax = divider[i];
					temp = i;
				}
			}
			/*printf("LEFT REMAIN += %d * %d, from %d to %d\n", hmax, from-temp+1, from, temp);*/
			remain += hmax * (from-temp+1);
			from = temp - 1;
		}
		/*for(i=from, remain=0; i>limit; i=j)
		{
			for(j=i, hmax=0; j>limit; j--)
			{
				if(divider[j] < hmax)
				{
					break;
				}
				else
				{
					hmax = divider[j];
				}
			}
			remain += divider[j+1] * (i-j);
		}
		if(limit >= 0)
		{
			remain += divider[limit+1];
		}*/
	}
	else
	{
		if(limit != lim)
		{
			/*printf("from %d, limit %d, divider[from] %d\n", from, limit, divider[from]);*/
			return (limit-from+1) * divider[from-1];
		}
		for(remain=0; from<limit; )
		{
			for(i=from, hmax=0; i<limit; i++)
			{
				if(divider[i] >= hmax)
				{
					hmax = divider[i];
					temp = i;
				}
			}
			/*printf("RIGHT REMAIN += %d * %d, from %d to %d\n", hmax, temp-from+1, from, temp);*/
			remain += hmax * (temp-from+1);
			from = temp + 1;
		}
		/*for(i=from, remain=0; i<limit; i=j)
		{
			for(j=i, hmax=0; j<limit; j++)
			{
				if(divider[j] < hmax)
				{
					break;
				}
				else
				{
					hmax = divider[j];
				}
			}
			remain += divider[j-1] * (j-i);
		}
		if(limit < lim)
		{
			remain += divider[limit-1];
		}*/
	}
	return remain;
}

void fit(int from, int limit, int dir)
{
	int i, j, hmax, remain;
	if(dir == LEFT)
	{
		/*printf("L fit: from %d to %d.\n", from, limit+1);*/
		for(i=from, remain=0; i>limit; )
		{
			for(j=i, hmax=0; j>limit; j--)
			{
				if(divider[j] < hmax)
				{
					break;
				}
				else
				{
					hmax = divider[j];
				}
			}
			for(; i>j; i--)
			{
				cap[i] = divider[j+1];
			}
		}
		cap[limit] = cap[limit+1];
	}
	else
	{
		/*printf("R fit: from %d to %d.\n", from, limit-1);*/
		for(i=from, remain=0; i<limit; i=j)
		{
			for(j=i, hmax=0; j<limit; j++)
			{
				if(divider[j] < hmax)
				{
					break;
				}
				else
				{
					hmax = divider[j];
				}
			}
			for(; i<j; i++)
			{
				cap[i] = divider[j-1];
			}
		}
		cap[limit] = cap[limit-1];
	}
}

int main()
{
	int i, lmost, rmost, left, right, center, height, lneed, rneed, lnext, rnext, ans;
	while(scanf("%d%d", &lmost, &rmost) == 2)
	{
		if(!lmost && !rmost)
		{
			break;
		}
		memset(cap, 0, sizeof(cap));
		for(i=lmost, lim=0; i<=rmost; i+=2, lim++)
		{
			scanf("%d", &divider[lim]);
			if(i == -1)
			{
				center = lim;
			}
		}
		lneed = rneed = 0;
		for(left=center, right=center+1; left>=0&&right<lim; )
		{
			/*printf("%d %d\n", left, right);*/
			if(divider[left] < divider[right])
			{
				height = divider[left];
				fill(height, left--, right);
			}
			else if(divider[left] == divider[right])
			{
				height = divider[left];
				/*cap[left] = cap[right-1] = height;*/
				fill(height, left, right);
				for(lnext=left-1; lnext>=0; lnext--)
				{
					if(divider[lnext] > height)
					{
						break;
					}
				}
				for(rnext=right+1; rnext<lim; rnext++)
				{
					if(divider[rnext] > height)
					{
						break;
					}
				}
				lneed = getremain(left-1, lnext, LEFT);
				rneed = getremain(right+1, rnext, RIGHT);
				/*printf("lneed: %d, rneed: %d\n", lneed, rneed);*/
				if(lnext == -1)
				{
					if(rnext == lim)
					{
						if(lneed > rneed)
						{
							lneed = rneed;
						}
						else
						{
							rneed = lneed;
						}
					}
					else
					{
						/*if(lneed > rneed)
						{
							lneed = rneed;
						}*/
						if(rneed > lneed)
						{
							rneed = lneed;
						}
					}
					break;
				}
				if(rnext == lim)
				{
					if(lneed > rneed)
					{
						lneed = rneed;
					}
					/*if(rneed > lneed)
					{
						rneed = lneed;
					}*/
					break;
				}
				fit(left-1, lnext, LEFT);
				fit(right, rnext-1, RIGHT);
				left = lnext;
				right = rnext;
			}
			else
			{
				height = divider[right];
				fill(height, left, right++);
			}
		}
		/*printf("l+r %d\n", lneed+rneed);*/
		for(i=0, ans=lneed+rneed; i<lim-1; i++)
		{
			/*printf("CAP %d: %d\n", i, cap[i]);*/
			ans += cap[i];
		}
		printf("%d\n", ans<<1);
	}
	return 0;
}
