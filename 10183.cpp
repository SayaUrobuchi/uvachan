#include <stdio.h>
#include <string.h>

int fib[1000][120], len[1000], str[120];
char s1[120], s2[120];

int comp(int* n1, int* n2, int l1, int l2)
{
	int i;
	if(l1 == l2)
	{
		for(i=l1-1; i>-1; i--)
		{
			if(n1[i] != n2[i])
			{
				return n1[i] - n2[i];
			}
		}
		return 0;
	}
	return l1 - l2;
}

int bisearch1(int left, int right, int l)
{
	int center, cmp;
	while(1)
	{
		center = left + right;
		center /= 2;
		cmp = comp(fib[center], str, len[center], l);
		if(!cmp)
		{
			return center;
		}
		else if(cmp > 0)
		{
			right = center - 1;
			if(left > right)
			{
				return center;
			}
		}
		else
		{
			left = center + 1;
			if(left > right)
			{
				return center + 1;
			}
		}
	}
}

int bisearch2(int left, int right, int l)
{
	int center, cmp;
	while(1)
	{
		center = left + right;
		center /= 2;
		cmp = comp(fib[center], str, len[center], l);
		if(!cmp)
		{
			return center;
		}
		else if(cmp > 0)
		{
			right = center - 1;
			if(left > right)
			{
				return center - 1;
			}
		}
		else
		{
			left = center + 1;
			if(left > right)
			{
				return center;
			}
		}
	}
}

int main()
{
	int n, i, j, k, l1, l2;
	fib[0][0] = 1;
	fib[1][0] = 2;
	len[0] = len[1] = 1;
	for(i=2; i<500; i++)
	{
		for(j=0; j<len[i-1]; j++)
		{
			fib[i][j] += fib[i-1][j] + fib[i-2][j];
			if(fib[i][j] > 999999999)
			{
				fib[i][j+1]++;
				fib[i][j] -= 1000000000;
			}
		}
		for(; fib[i][j]; j++)
		{
			if(fib[i][j] > 999999999)
			{
				fib[i][j+1]++;
				fib[i][j] -= 1000000000;
			}
		}
		len[i] = j;
	}
	while(scanf("%s%s", s1, s2) == 2)
	{
		if(s1[0] == '0' && s2[0] == '0')
		{
			break;
		}
		for(i=0, j=l1=strlen(s1)-1; i<j; i++, j--)
		{
			k = s1[i];
			s1[i] = s1[j];
			s1[j] = k;
		}
		for(i=0, j=l2=strlen(s2)-1; i<j; i++, j--)
		{
			k = s2[i];
			s2[i] = s2[j];
			s2[j] = k;
		}
		for(i=0, j=8>l1?l1:8, str[0]=0, k=0; s1[i]; i++)
		{
			if(i > j)
			{
				j += 9;
				if(j > l1)
				{
					j = l1;
				}
				k++;
				str[k] = 0;
			}
			str[k] *= 10;
			str[k] += s1[j-i%9] - 48;
		}
		if(str[k])
		{
			k++;
		}
		l1 = bisearch1(0, 499, k);
		for(i=0, j=8>l2?l2:8, str[0]=0, k=0; s2[i]; i++)
		{
			if(i > j)
			{
				j += 9;
				if(j > l2)
				{
					j = l2;
				}
				k++;
				str[k] = 0;
			}
			str[k] *= 10;
			str[k] += s2[j-i%9] - 48;
		}
		if(str[k])
		{
			k++;
		}
		l2 = bisearch2(0, 499, k);
		/*printf("%d %d\n", l1, l2);
		printf("%d", fib[l1][len[l1]-1]);
		for(i=len[l1]-2; i>-1; i--)
		{
			printf("%09d", fib[l1][i]);
		}
		printf("\n");
		printf("%d", fib[l2][len[l2]-1]);
		for(i=len[l2]-2; i>-1; i--)
		{
			printf("%09d", fib[l2][i]);
		}
		printf("\n");*/
		printf("%d\n", l2-l1+1);
	}
	return 0;
}
