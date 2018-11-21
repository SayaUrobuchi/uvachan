/*
	ID: sa072682
	LANG: C
	TASK: contact
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tbl[13][5000], ary[70000][3];
char str[200001], s[100];

int comp(const void *p, const void *q)
{
	int *a, *b;
	a = (int*)p;
	b = (int*)q;
	if(a[2] == b[2])
	{
		if(a[0] == b[0])
		{
			return a[1] - b[1];
		}
		return a[0] - b[0];
	}
	return b[2] - a[2];
}

void rev()
{
	int i, j, temp;
	for(i=0, j=strlen(s)-1; i<j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

char* trans(int now, int len)
{
	int i;
	memset(s, 48, len);
	for(i=0; now; now/=2, i++)
	{
		s[i] += now % 2;
	}
	s[len] = 0;
	rev();
	return s;
}

int main()
{
	int n, m, o, i, j, k, c;
	long long temp;
	char buf[100];
	freopen("contact.in", "r", stdin);
	freopen("contact.out", "w", stdout);
	scanf("%d%d%d", &n, &m, &o);
	str[0] = 0;
	while(scanf("%s", buf) == 1)
	{
		strcat(str, buf);
	}
	for(i=0; str[i]; i++)
	{
		for(j=0, temp=0; str[i+j]&&j<n-1; j++)
		{
			temp *= 2;
			temp += str[i+j] - 48;
		}
		for(; str[i+j]&&j<=m; j++)
		{
			temp *= 2;
			temp += str[i+j] - 48;
			tbl[j+1][temp]++;
		}
	}
	for(i=n, c=0; i<=m; i++)
	{
		for(j=0; j<5000; j++)
		{
			if(tbl[i][j])
			{
				ary[c][0] = i;
				ary[c][1] = j;
				ary[c++][2] = tbl[i][j];
			}
		}
	}
	qsort(ary, c, sizeof(ary[0]), comp);
	for(i=0, j=-1, k=0, o++; o&&i<c; i++)
	{
		if(ary[i][2] != j)
		{
			if(--o)
			{
				if(i)
				{
					printf("\n");
				}
				printf("%d\n%s", ary[i][2], trans(ary[i][1], ary[i][0]));
				k = 1;
				j = ary[i][2];
			}
			else
			{
				break;
			}
		}
		else
		{
			if(k == 6)
			{
				printf("\n%s", trans(ary[i][1], ary[i][0]));
				k = 1;
			}
			else
			{
				if(k)
				{
					printf(" ");
				}
				printf("%s", trans(ary[i][1], ary[i][0]));
				k++;
			}
		}
	}
	printf("\n");
	scanf(" ");
	return 0;
}
