#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int monthday[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int days[10000];
int d[10000], m[10000];
int imp[10000];
int st[10000], c[10000];
int index[10000], index2[10000], index3[10000];
char s[10000][256];
char str[256];
char star[8];

int comp3(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int comp2(const void *p, const void *q)
{
	int i, j;
	i = *(int*)p;
	j = *(int*)q;
	if(st[i] == st[j])
	{
		return c[i] - c[j];
	}
	return st[i] - st[j];
}

int comp(const void *p, const void *q)
{
	int i, j;
	i = *(int*)p;
	j = *(int*)q;
	if(days[i] == days[j])
	{
		if(imp[i] == imp[j])
		{
			return i-j;
		}
		return imp[j]-imp[i];
	}
	return days[i]-days[j];
}

int main()
{
	int cas, n, i, j, k, year, day, month, nowdays, temp, temp2;
	char *ptr;
	cas = 0;
	scanf("%d", &year);
	monthday[2] += !(year % 4);
	gets(str);
	n = 0;
	while(gets(str))
	{
		if(str[0] == 'D')
		{
			break;
		}
		index[n] = n;
		sscanf(str+2, "%d%d%d", &d[n], &m[n], &imp[n]);
		days[n] = d[n];
		for(i=1; i<m[n]; i++)
		{
			days[n] += monthday[i];
		}
		strtok(str+2, " ");
		strtok(NULL, " ");
		ptr = strtok(NULL, " ");
		for(; *ptr; ptr++);
		for(; !(*ptr)||*ptr==32; ptr++);
		strcpy(s[n++], ptr);
	}
	qsort(index, n, sizeof(int), comp);
	memset(star, '*', sizeof(star));
	star[7] = 0;
	do
	{
		if(str[0] == '#')
		{
			break;
		}
		sscanf(str+2, "%d%d", &day, &month);
		nowdays = day;
		for(i=1; i<month; i++)
		{
			nowdays += monthday[i];
		}
		if(cas)
		{
			putchar('\n');
		}
		cas = 1;
		printf("Today is:%3d%3d\n", day, month);
		for(i=0, j=0, k=0; i<n; i++)
		{
			temp = index[i];
			if(days[temp] == nowdays)
			{
				index3[k++] = temp;
			}
			else if(days[temp] > nowdays)
			{
				if((temp2 = imp[temp] - days[temp] + nowdays + 1) > 0)
				{
					st[temp] = 7 - temp2;
					c[temp] = days[temp];
					index2[j++] = temp;
				}
			}
			if(days[temp] + 365 + !(year % 4) > nowdays)
			{
				if((temp2 = !(year % 4) + imp[temp] - days[temp] - 365 - !(year % 4) + nowdays + 1) > 0)
				{
					if(temp2 <= 7)
					{
						st[temp] = 7 - temp2;
						c[temp] = days[temp] + 365 + !(year % 4);
						index2[j++] = temp;
					}
				}
			}
		}
		qsort(index2, j, sizeof(int), comp2);
		qsort(index3, k, sizeof(int), comp3);
		for(i=0; i<k; i++)
		{
			temp = index3[i];
			printf("%3d%3d *TODAY* %s\n", d[temp], m[temp], s[temp]);
		}
		for(i=0; i<j; i++)
		{
			temp = index2[i];
			printf("%3d%3d %-7s %s\n", d[temp], m[temp], star+st[temp], s[temp]);
		}
	}while(gets(str));
	scanf(" ");
	return 0;
}
