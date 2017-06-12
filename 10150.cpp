#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct dictionary
{
  char str[17], len;
};

dictionary dic[25144];
int path[25143][100], queue[25143], pre[25143], lcount[17];
char check[25143];

int comp(const void *p, const void *q)
{
  if((*(dictionary*)p).len == (*(dictionary*)q).len)
  {
    return strcmp((*(dictionary*)p).str, (*(dictionary*)q).str);
  }
  else return (*(dictionary*)p).len - (*(dictionary*)q).len;
}

int strcomp(char* ptr1, char* ptr2)
{
	while(*ptr1)
	{
		if(*ptr1 != *ptr2) return strcmp(ptr1+1, ptr2+1);
		ptr1++;
		ptr2++;
	}
	return 1;
}

int bisearch(char* target, int length)
{
	int left, right, center, tmp;
	left = lcount[length - 1];
	right = lcount[length] - 1;
	while(1)
	{
		center = left + right;
		center /= 2;
		tmp = strcmp(target, dic[center].str);
		if(!tmp) return center;
		else if(tmp > 0) left = center + 1;
		else right = center - 1;
	}
}

void outans(int now)
{
	if(now == -1) return;
	outans(pre[now]);
	printf("%s\n", dic[queue[now]].str);
}

int main()
{
  int i, j, k, n, tmp, target, len1, len2;
  char s1[17], s2[17], bline;
  n = 0;
  bline = 0;
  while(gets(dic[n].str))
  {
    dic[n].len = strlen(dic[n].str);
    if(!dic[n].len) break;
    path[n++][0] = 1;
  }
  qsort(dic, n, sizeof(dictionary), comp);
  lcount[0] = 0;
  for(i=0, tmp=1; i<n; i++)
  {
		if(dic[i].len > tmp)
		{
			while(dic[i].len > tmp)
			{
				lcount[tmp] = i;
				tmp++;
			}
			if(tmp == 16) break;
		}
	}
	lcount[tmp++] = n;
	for(i=1; i<tmp; i++)
	{
		for(j=lcount[i - 1]; j<lcount[i]; j++)
		{
			for(k=j+1; k<lcount[i]; k++)
			{
				if(!strcomp(dic[j].str, dic[k].str))
				{
					path[j][path[j][0]++] = k;
					path[k][path[k][0]++] = j;
				}
			}
		}
	}
	while(scanf("%s%s", s1, s2) == 2)
	{
		if(bline) printf("\n");
		bline = 1;
		len1 = strlen(s1);
		len2 = strlen(s2);
		if(len1 == len2)
		{
			queue[0] = bisearch(s1, len1);
			target = bisearch(s2, len2);
			pre[0] = -1;
			memset(check, 1, sizeof(check));
			check[queue[0]] = 0;
			for(i=0, j=1; i<j; i++)
			{
				tmp = queue[i];
				for(k=1; k<path[tmp][0]; k++)
				{
					if(check[path[tmp][k]])
					{
						check[path[tmp][k]] = 0;
						queue[j] = path[tmp][k];
						pre[j++] = i;
						if(path[tmp][k] == target) break;
					}
				}
				if(k < path[tmp][0]) break;
			}
			if(i == j) printf("No solution.\n");
			else outans(j - 1);
		}
		else printf("No solution.\n");
	}
  return 0;
}
