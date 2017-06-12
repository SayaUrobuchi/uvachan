#include <stdio.h>
#include <string.h>

unsigned int n;
unsigned int w[15];
unsigned int tbl[15];
char buf[1005];

unsigned int max(unsigned int p, unsigned int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

unsigned int min(unsigned int p, unsigned int q)
{
	if(p < q)
	{
		return p; 
	}
	return q;
}

unsigned int getw(char *s)
{
	unsigned int i, res;
	for(i=0; s[i]; i++)
	{
		res <<= 5;
		res += s[i] - 96;
	}
	return res;
}

void recursion(unsigned int num)
{
	unsigned int i, p, q, maxnum, temp;
	/*printf("recurse %d\n", num);*/
	memset(tbl, 0, sizeof(tbl));
	for(i=0, maxnum=0; i<n; i++)
	{
		temp = (num / w[i]) % n;
		if(tbl[temp])
		{
			p = (num/tbl[temp]+1)*tbl[temp];
			q = (num/w[i]+1)*w[i];
			recursion(min(p, q));
			return;
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
	printf("%u\n\n", num);
}

int main()
{
	char *ptr;
	while(gets(buf))
	{
		puts(buf);
		n = 0;
		ptr = strtok(buf, " ");
		do
		{
			w[n++] = getw(ptr);
		}while(ptr=strtok(NULL, " "));
		recursion(w[0]);
	}
	return 0;
}
