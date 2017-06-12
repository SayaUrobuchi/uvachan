#include <stdio.h>
#include <string.h>

int n;
int tbl[127];
char map[30][30];
char str[100];
char buf[100];

void print()
{
	memset(buf, '-', n);
	buf[n] = 0;
	printf(" -+%s\n", buf);
}

int semigroup()
{
	int i, j, k;
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			if(!tbl[map[i][j]])
			{
				printf("NOT A SEMIGROUP: %c#%c = %c WHICH IS NOT AN ELEMENT OF THE SET\n", str[i], str[j], map[i][j]);
				return 0;
			}
		}
	}
	for(i=0; i<n; i++)
	{
		for(j=0; j<n; j++)
		{
			for(k=0; k<n; k++)
			{
				if(map[tbl[map[i][j]]-1][k] != map[i][tbl[map[j][k]]-1])
				{
					printf("NOT A SEMIGROUP: (%c#%c)#%c IS NOT EQUAL TO %c#(%c#%c)\n", str[i], str[j], str[k], str[i], str[j], str[k]);
					return 0;
				}
			}
		}
	}
	return 1;
}

int commutative()
{
	int i, j;
	for(i=0; i<n; i++)
	{
		for(j=i+1; j<n; j++)
		{
			if(map[i][j] != map[j][i])
			{
				printf("SEMIGROUP BUT NOT COMMUTATIVE (%c#%c IS NOT EQUAL TO %c#%c)\n", str[i], str[j], str[j], str[i]);
				return 0;
			}
		}
	}
	return 1;
}

int main()
{
	int cas, i;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		scanf("%s", str);
		for(i=0; i<n; i++)
		{
			scanf("%s", map[i]);
		}
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		printf("S = {%c", str[0]);
		for(i=1; str[i]; i++)
		{
			printf(",%c", str[i]);
		}
		printf("}\n");
		printf(" #|%s\n", str);
		print();
		for(i=0; str[i]; i++)
		{
			tbl[str[i]] = i + 1;
			printf(" %c|%s\n", str[i], map[i]);
		}
		printf("\n");
		if(semigroup() && commutative())
		{
			printf("COMMUTATIVE SEMIGROUP\n");
		}
		printf("------------------------------\n");
	}
	return 0;
}
