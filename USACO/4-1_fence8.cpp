/*
	TASK: fence8
	LANG: C
	ID: sa072682
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int ans, n, m, id, c[130], ary[55];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int dfsid(int ap, int loc, int counter, int remain)
{
	int i, j, f, temp;
	/*printf("id %d: %d, %d, %d, %d\n", id, ap, loc, counter, remain);*/
	if(counter >= id)
	{
		return 1;
	}
	if(ap == n)
	{
		if(counter > ans)
		{
			ans = counter;
		}
		return 0;
	}
	for(i=loc, f=0; i<=128&&i<=remain; i++)
	{
		if(c[i])
		{
			if(i + i > remain)
			{
				for(j=remain; j>=i; j--)
				{
					if(c[j])
					{
						c[j]--;
						temp = dfsid(ap+1, 1, counter+1, ary[ap+1]);
						c[j]++;
						return temp;
					}
				}
			}
			else
			{
				if(f == 0)
				{
					if(c[i] > 1)
					{
						temp = i;
					}
					else
					{
						for(j=i+1, temp=0; j<=128&&j<=remain; j++)
						{
							if(c[j])
							{
								temp = j;
								break;
							}
						}
					}
					if(i + temp > remain)
					{
						for(j=remain; j>=i; j--)
						{
							if(c[j])
							{
								c[j]--;
								temp = dfsid(ap+1, 1, counter+1, ary[ap+1]);
								c[j]++;
								return temp;
							}
						}
					}
				}
			}
			f = 1;
			c[i]--;
			if(dfsid(ap, i, counter+1, remain-i))
			{
				c[i]++;
				return 1;
			}
			c[i]++;
		}
	}
	if(f == 0)
	{
		return dfsid(ap+1, 1, counter, ary[ap+1]);
	}
	return 0;
}

int main()
{
	int i, j, temp, left, right, rec, sum;
	freopen("fence8.in", "r", stdin);
	freopen("fence8.out", "w", stdout);
	while(scanf("%d", &n) == 1)
	{
		for(i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
		}
		qsort(ary, n, sizeof(int), comp);
		memset(c, 0, sizeof(c));
		scanf("%d", &m);
		for(i=0, rec=0; i<m; i++)
		{
			scanf("%d", &temp);
			if(temp <= ary[n-1])
			{
				c[temp]++;
			}
		}
		for(i=1, temp=0; i<=128&&temp<=sum; i++)
		{
			if(c[i])
			{
				for(j=0; j<c[i]; j++, rec++)
				{
					sum += i;
					if(temp > sum)
					{
						break;
					}
				}
				if(temp > sum)
				{
					c[i] = j;
					for(i++; i<=128; i++)
					{
						c[i] = 0;
					}
					break;
				}
			}
		}
		for(left=1, right=rec, ans=0; left<=right; )
		{
			id = left + right;
			id >>= 1;
			if(dfsid(0, 1, 0, ary[0]))
			{
				left = id + 1;
				ans = id;
			}
			else
			{
				break;
				right = id - 1;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
