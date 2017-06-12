#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int win[35], lost[35], tie[35];
int gscored[35], gagainst[35];
int index[35];
char name[35][35];
char buf[2008], title[2008];

int comp(const void *p, const void *q)
{
	return strcmp(name[*(int*)p], name[*(int*)q]);
}

int unequal(char p, char q)
{
	if(p >= 'A' && p <= 'Z')
	{
		p += 32;
	}
	if(q >= 'A' && q <= 'Z')
	{
		q += 32;
	}
	return p-q;
}

int scomp(char *p, char *q)
{
	for(; (*p)&&(*q); p++, q++)
	{
		if(unequal(*p, *q))
		{
			return unequal(*p, *q);
		}
	}
	if(*p)
	{
		return 1;
	}
	else if(*q)
	{
		return -1;
	}
	return 0;
}

int rank(const void *l, const void *r)
{
	int p, q;
	p = *(int*)l;
	q = *(int*)r;
	if(win[p]*3+tie[p] != win[q]*3+tie[q])
	{
		return win[q]*3+tie[q] - (win[p]*3+tie[p]);
	}
	if(win[p] != win[q])
	{
		return win[q] - win[p];
	}
	if(gscored[p]-gagainst[p] != gscored[q]-gagainst[q])
	{
		return gscored[q]-gagainst[q] - (gscored[p]-gagainst[p]);
	}
	if(gscored[p] != gscored[q])
	{
		return gscored[q] - gscored[p];
	}
	if(win[p]+tie[p]+lost[p] != win[q]+tie[q]+lost[q])
	{
		return win[p]+tie[p]+lost[p] - (win[q]+tie[q]+lost[q]);
	}
	return scomp(name[p], name[q]);
}

int bisearch(char *s, int left, int right)
{
	int center, cmp;
	center = left + right;
	center >>= 1;
	cmp = strcmp(name[index[center]], s);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(s, left, center-1);
	}
	return bisearch(s, center+1, right);
}

int main()
{
	int count, n, m, i, t1, t2, s1, s2, now;
	gets(buf);
	sscanf(buf, "%d", &count);
	while(count--)
	{
		gets(title);
		gets(buf);
		sscanf(buf, "%d", &n);
		for(i=0; i<n; i++)
		{
			gets(name[i]);
			index[i] = i;
		}
		memset(win, 0, sizeof(win));
		memset(tie, 0, sizeof(tie));
		memset(lost, 0, sizeof(lost));
		memset(gscored, 0, sizeof(gscored));
		memset(gagainst, 0, sizeof(gagainst));
		qsort(index, n, sizeof(int), comp);
		gets(buf);
		sscanf(buf, "%d", &m);
		while(m--)
		{
			gets(buf);
			t1 = bisearch(strtok(buf, "#"), 0, n-1);
			sscanf(strtok(NULL, "#"), "%d@%d", &s1, &s2);
			t2 = bisearch(strtok(NULL, "#"), 0, n-1);
			gscored[t1] += s1;
			gscored[t2] += s2;
			gagainst[t1] += s2;
			gagainst[t2] += s1;
			if(s1 > s2)
			{
				win[t1]++;
				lost[t2]++;
			}
			else if(s1 == s2)
			{
				tie[t1]++;
				tie[t2]++;
			}
			else
			{
				win[t2]++;
				lost[t1]++;
			}
		}
		qsort(index, n, sizeof(int), rank);
		puts(title);
		for(i=0; i<n; i++)
		{
			now = index[i];
			printf("%d) %s %dp, %dg (%d-%d-%d), %dgd (%d-%d)\n", i+1, name[now], win[now]*3+tie[now], win[now]+tie[now]+lost[now], win[now], tie[now], lost[now], gscored[now]-gagainst[now], gscored[now], gagainst[now]);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
