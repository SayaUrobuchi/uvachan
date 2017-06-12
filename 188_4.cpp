#include <stdio.h>
#include <string.h>

unsigned long long n;
unsigned long long w[15];
unsigned long long tbl[15];
char buf[1005];

unsigned long long max(unsigned long long p, unsigned long long q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

unsigned long long min(unsigned long long p, unsigned long long q)
{
	if(p < q)
	{
		return p; 
	}
	return q;
}

unsigned long long getw(char *s)
{
	unsigned long long i, res;
	for(i=0; s[i]; i++)
	{
		res <<= 5;
		res += s[i] - 96;
	}
	return res;
}

void recursion(unsigned long long num)
{
	unsigned long long i, p, q, flag, maxnum, temp;
	/*printf("recurse %d\n", num);*/
	memset(tbl, 0, sizeof(tbl));
	for(i=0, flag=0, maxnum=0; i<n; i++)
	{
		temp = (num / w[i]) % n;
		if(tbl[temp])
		{
			flag = 1;
			p = (num/tbl[temp]+1)*tbl[temp];
			q = (num/w[i]+1)*w[i];
			if(q > p)
			{
				maxnum = max(maxnum, p);
				tbl[temp] = w[i];
			}
			else
			{
				maxnum = max(maxnum, q);
			}
		}
		else
		{
			tbl[temp] = w[i];
		}
	}
	if(flag)
	{
		recursion(maxnum);
	}
	else
	{
		printf("%llu\n\n", num);
	}
}

int main()
{
	unsigned long long minnum;
	char *ptr;
	while(gets(buf))
	{
		puts(buf);
		n = 0;
		ptr = strtok(buf, " ");
		minnum = 1<<30;
		do
		{
			w[n++] = getw(ptr);
			if(w[n-1] < minnum)
			{
				minnum = w[n-1];
			}
		}while(ptr=strtok(NULL, " "));
		recursion(minnum);
	}
	return 0;
}
