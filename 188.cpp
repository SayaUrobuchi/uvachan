#include <stdio.h>
#include <string.h>

int n;
int w[15];
int tbl[15];
char buf[1005];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p; 
	}
	return q;
}

int getw(char *s)
{
	int i, res;
	for(i=0; s[i]; i++)
	{
		res <<= 5;
		res += s[i] - 96;
	}
	return res;
}

void recursion(int num)
{
	int i, p, q, flag, maxnum, temp;
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
		printf("%d\n\n", num);
	}
}

int main()
{
	char *ptr, i, minnum, temp;
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
