#include <stdio.h>
#include <string.h>

char str[1000001], s[101];
int ary[52][100000], num[52];

char calc(char ch)
{
	if(ch > 90)
	{
		return ch - 71;
	}
	else
	{
		return ch - 65;
	}
}

int bisearch(int j, int left, int right, int target)
{
	int center;
	center = left + right;
	center /= 2;
	if((!center && ary[j][center] > target) || (ary[j][center] > target && ary[j][center-1] <= target))
	{
		return ary[j][center];
	}
	else if(ary[j][center] <= target)
	{
		return bisearch(j, center+1, right, target);
	}
	return bisearch(j, left, center-1, target);
}

int main()
{
	int slen, len, q, i, j, k, l, left, right;
	gets(str);
	for(i=0; str[i]; i++)
	{
		j = calc(str[i]);
		ary[j][num[j]++] = i;
	}
	scanf("%d", &q);
	gets(s);
	while(q--)
	{
		gets(s);
		j = calc(s[0]);
		if(!num[j])
		{
			printf("Not matched\n");
		}
		else
		{
			left = k = ary[j][0];
			for(i=1; s[i]; i++)
			{
				j = calc(s[i]);
				if(!num[j] || ary[j][num[j]-1] <= k)
				{
					break;
				}
				k = bisearch(j, 0, num[j]-1, k);
			}
			if(s[i])
			{
				printf("Not matched\n");
			}
			else
			{
				printf("Matched %d %d\n", left, k);
			}
		}
	}
	return 0;
}
