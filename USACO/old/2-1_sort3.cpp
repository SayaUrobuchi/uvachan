/*
	ID: sa072682
	LANG: C
	TASK: sort3
*/
#include <stdio.h>

int ary[1001], tbl[4];

int main()
{
	int n, i, j, c, temp, left, right;
	freopen("sort3.in", "r", stdin);
	freopen("sort3.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		tbl[ary[i]]++;
	}
	left = tbl[1];
	tbl[2] += tbl[1];
	right = n - 1;
	for(i=0, c=0; i<tbl[1]; i++)
	{
		if(ary[i] == 2)
		{
			for(; ; left++)
			{
				if(ary[left] == 1)
				{
					temp = ary[left];
					ary[left] = ary[i];
					ary[i] = temp;
					c++;
					break;
				}
			}
		}
		else if(ary[i] == 3)
		{
			for(; ; right--)
			{
				if(ary[right] == 1)
				{
					temp = ary[right];
					ary[right] = ary[i];
					ary[i] = temp;
					c++;
					break;
				}
			}
		}
	}
	for(right=n-1; i<tbl[2]; i++)
	{
		if(ary[i] == 3)
		{
			for(; ; right--)
			{
				if(ary[right] == 2)
				{
					temp = ary[right];
					ary[right] = ary[i];
					ary[i] = temp;
					c++;
					break;
				}
			}
		}
	}
	printf("%d\n", c);
	scanf(" ");
	return 0;
}
