#include <stdio.h>
#include <string.h>

int bit, mod;
char fmt[10][10];

void get_num(char *s, int *ary, int *len)
{
	int i;
	char *ptr, *st;
	for(i=0, ptr=s+strlen(s)-1; ptr>=s; ptr-=bit, i++)
	{
		st = ptr-bit+1<s?s:ptr-bit+1;
		sscanf(st, fmt[ptr-st+1], &ary[i]);
	}
	*len = i;
}

int main()
{
	int i, j, al, bl, len;
	int na[115], nb[115], fin[230];
	char sa[105], sb[105], op[105];
	for(i=1; i<=9; i++)
	{
		sprintf(fmt[i], "%%%dd", i);
	}
	bit = 9;
	/*while(scanf("%s", sa) == 1)
	{
		get_num(sa, na, &al);
		for(i=0; i<al; i++)
		{
			printf("%0*d\n", bit, na[i]);
		}
	}*/
	while(scanf("%s%s%s", op, sa, sb) == 3)
	{
		if(*op == '+')
		{
			bit = 9;
			mod = 1000000000;
		}
		else if(*op == '*')
		{
			bit = 4;
			mod = 10000;
		}
		get_num(sa, na, &al);
		get_num(sb, nb, &bl);
		memset(fin, 0, sizeof(fin));
		if(*op == '+')
		{
			for(i=0; i<al||i<bl; i++)
			{
				if(i < al)
				{
					fin[i] += na[i];
				}
				if(i < bl)
				{
					fin[i] += nb[i];
				}
				if(fin[i] >= mod)
				{
					fin[i] -= mod;
					fin[i+1]++;
				}
			}
			if(fin[i])
			{
				i++;
			}
			len = i;
		}
		else
		{
			for(i=0; i<al; i++)
			{
				for(j=0; j<bl; j++)
				{
					fin[i+j] += na[i] * nb[j];
					if(fin[i+j] >= mod)
					{
						fin[i+j+1] += fin[i+j] / mod;
						fin[i+j] %= mod;
					}
				}
			}
			for(i=0; i<al+bl-1||fin[i]; i++)
			{
				if(fin[i] >= mod)
				{
					fin[i+1] += fin[i] / mod;
					fin[i] %= mod;
				}
			}
			for(; i>0&&!fin[i]; i--);
			len = i+1;
		}
		printf("%d", fin[len-1]);
		for(i=len-2; i>=0; i--)
		{
			printf("%0*d", bit, fin[i]);
		}
		printf("\n");
	}
	return 0;
}
