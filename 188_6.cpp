#include <stdio.h>
#include <string.h>

long long n;
long long w[15];
long long tbl[15];
char buf[1005];

long long max(long long p, long long q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

long long min(long long p, long long q)
{
	if(p < q)
	{
		return p; 
	}
	return q;
}

long long getw(char *s)
{
	long long i, res;
	for(; *s; s++)
	{
		res <<= 5;
		res += *s - 96;
	}
	return res;
}

int main()
{
	long long i, p, q, flag, num, minnum, maxnum, temp;
	char *ptr;
	while(gets(buf))
	{
		puts(buf);
		n = 0;
		memset(w, 0, sizeof(w));
		for(ptr=buf, minnum=1<<30; *ptr; ptr++)
		{
			if(*ptr == ' ')
			{
				if(w[n])
				{
					if(w[n] < minnum)
					{
						minnum = w[n];
					}
					n++;
				}
			}
			else
			{
				w[n] <<= 5;
				w[n] += *ptr - 96;
			}
		}
		if(w[n])
		{
			if(w[n] < minnum)
			{
				minnum = w[n];
			}
			n++;
		}
		for(num=minnum; ; num=maxnum)
		{
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
			if(!flag)
			{
				printf("%lld\n\n", num);
				break;
			}
		}
	}
	return 0;
}
