#include <stdio.h>
#include <string.h>

char str[101], ary[120000][101];

int bisearch(char* s, int left, int right)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	cmp = strcmp(ary[center], s);
	if(!cmp)
	{
		return center;
	}
	else if(cmp > 0)
	{
		return bisearch(s, left, center-1);
	}
	return bisearch(s, center+1, right);
}

int main()
{
	int n, i, j;
	n = 0;
	while(gets(ary[n]))
	{
		n++;
	}
	for(i=0; i<n; i++)
	{
		for(j=0; ary[i][j+1]; j++)
		{
			str[j] = ary[i][j];
			str[j+1] = 0;
			if(bisearch(str, 0, n-1) != -1)
			{
				if(bisearch(ary[i]+j+1, 0, n-1) != -1)
				{
					printf("%s\n", ary[i]);
					break;
				}
			}
		}
	}
	scanf(" ");
	return 0;
}
