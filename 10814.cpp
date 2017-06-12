#include <stdio.h>

int al, bl, cl, aal, bbl;
int a[105], b[105], c[105], aa[105], bb[105];
char s0[10055], s1[10055];

void read(char *s, int *a, int *l)
{
	*l = 0;
	for(; *s; s++)
	{
		*a++ = *s-'0';
		(*l)++;
	}
}

void gcd(int *a, int *al, int *b, int *bl, int *c, int *cl)
{
	int i, j;
	if(*bl == 1 && b[0] == 0)
	{
		return;
	}
	for(i=0; i<*bl; i++)
	{
		c[i] = b[i];
	}
	*cl = *bl;
	for(i=0; i+*bl<=*al; i++)
	{
		while(1)
		{
			if(i < 1 || a[i-1] == 0)
			{
				for(j=0; j<*bl; j++)
				{
					if(a[i+j] != b[j])
					{
						break;
					}
				}
				if(j < *bl && a[i+j] < b[j])
				{
					break;
				}
			}
			for(j=*bl-1; j>=0; j--)
			{
                a[i+j] -= b[j];
                if(a[i+j] < 0)
                {
					a[i+j] += 10;
					a[i+j-1]--;
				}
			}
		}
	}
	for(i=0; i<*al-1; i++)
	{
		if(a[i])
		{
			break;
		}
	}
	for(j=0; i<*al; i++, j++)
	{
		a[j] = a[i];
	}
	*al = j;
	gcd(b, bl, a, al, c, cl);
}

void div(int *a, int *al, int *b, int *bl, int *c, int *cl)
{
	int i, j;
	*cl = 0;
	for(i=0; i+*bl<=*al; i++)
	{
		c[*cl] = 0;
		while(1)
		{
			if(i < 1 || a[i-1] == 0)
			{
				for(j=0; j<*bl; j++)
				{
					if(a[i+j] != b[j])
					{
						break;
					}
				}
				if(j < *bl && a[i+j] < b[j])
				{
					break;
				}
			}
			c[*cl]++;
			for(j=*bl-1; j>=0; j--)
			{
                a[i+j] -= b[j];
                if(a[i+j] < 0)
                {
					a[i+j] += 10;
					a[i+j-1]--;
				}
			}
		}
		(*cl)++;
	}
}

int main()
{
	int count, i;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s / %s", s0, s1);
		read(s0, a, &al);
		read(s1, b, &bl);
		for(i=0; i<al; i++)
		{
			aa[i] = a[i];
		}
		aal = al;
		for(i=0; i<bl; i++)
		{
			bb[i] = b[i];
		}
		bbl = bl;
		gcd(a, &al, b, &bl, c, &cl);
		/*for(i=0; i<cl; i++)
		{
			printf("%d", c[i]);
		}
		printf("\n");*/
		div(aa, &aal, c, &cl, a, &al);
		div(bb, &bbl, c, &cl, b, &bl);
		for(i=0; i<al; i++)
		{
			if(!i && !a[i])
			{
				continue;
			}
			printf("%d", a[i]);
		}
		printf(" / ");
		for(i=0; i<bl; i++)
		{
			if(!i && !b[i])
			{
				continue;
			}
			printf("%d", b[i]);
		}
		printf("\n");
	}
	return 0;
}
