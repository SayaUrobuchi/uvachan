#include <stdio.h>
#include <string.h>

int fib[45];
int ary[45];
char str[200];
char final[105];

int uppercase(char now)
{
	return now > 64 && now < 91;
}

int bisearch(int left, int right, int target)
{
	int center;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	if(fib[center] == target)
	{
		return center;
	}
	else if(fib[center] > target)
	{
		return bisearch(left, center-1, target);
	}
	return bisearch(center+1, right, target);
}

int main()
{
	int count, n, i, j;
	fib[0] = 1;
	fib[1] = 2;
	for(i=2; i<45; i++)
	{
		fib[i] = fib[i-1] + fib[i-2];
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		gets(str);
		gets(str);
		memset(final, ' ', sizeof(final));
		for(i=0, j=0; str[i]&&j<n; i++)
		{
			if(uppercase(str[i]))
			{
				final[bisearch(0, 44, ary[j++])] = str[i];
			}
		}
		for(i=45; i>-1&&final[i]==' '; i--);
		final[i+1] = 0;
		puts(final);
	}
	return 0;
}
