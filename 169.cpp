#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[200000];
int word[200000][26];
int start[200000], end[200000];
int appear[2000];
int trueword[200000];
int final[200000];
int temptbl[26];
char str[20000];

int comp(const void *p, const void *q)
{
	int cmp;
	cmp = memcmp(word[*(int*)p], word[*(int*)q], sizeof(temptbl));
	if(cmp)
	{
		return cmp;
	}
	return *(int*)p - *(int*)q;
}

int comp2(const void *p, const void *q)
{
	if(trueword[*(int*)p] == trueword[*(int*)q])
	{
		return end[*(int*)p] - end[*(int*)q];
	}
	return trueword[*(int*)q] - trueword[*(int*)p];
}

int lowercase(char now)
{
	return now > 96 && now < 123;
}

int gethead(int now)
{
	if(now < 0)
	{
		return 0;
	}
	return str[now];
}

int gettail(int now)
{
	return str[now];
}

void print(int i, int j)
{
	int temp;
	temp = str[j+1];
	str[j+1] = 0;
	printf("%s\n", str+i);
	str[j+1] = temp;
}

int main()
{
	int m, i, j, k, p, q, item1, item2, chk, head, tail;
	char *ptr;
	while(gets(str))
	{
		if(!strcmp(str, "#"))
		{
			break;
		}
		ptr = str + strlen(str);
		if(ptr > str && *(ptr-1) == '-')
		{
			ptr--;
			while(gets(ptr))
			{
				ptr += strlen(ptr);
				if(ptr > str && *(ptr-1) != '-')
				{
					break;
				}
				ptr--;
			}
		}
		for(i=0, j=0; str[i]; i++)
		{
			if(lowercase(str[i]))
			{
				str[j++] = str[i];
			}
		}
		str[j] = 0;
		for(i=0, k=0; str[i]; i++)
		{
			memset(temptbl, 0, sizeof(temptbl));
			temptbl[str[i]-97]++;
			head = gethead(i-1);
			if(str[i] != head)
			{
				for(j=i+1; str[j]&&j-i<250; j++)
				{
					if(str[j] == head)
					{
						break;
					}
					temptbl[str[j]-97]++;
					tail = gettail(j+1);
					if(tail && temptbl[tail-97])
					{
						continue;
					}
					if((!tail || !head) || head == tail)
					{
						index[k] = k;
						memcpy(word[k], temptbl, sizeof(temptbl));
						start[k] = i;
						end[k++] = j;
					}
				}
			}
		}
		qsort(index, k, sizeof(int), comp);
		memset(appear, 0, sizeof(appear));
		memset(trueword, 0, sizeof(trueword));
		for(i=0, m=0; i<k; i=j)
		{
			item1 = index[i];
			for(j=i+1; j<k; j++)
			{
				item2 = index[j];
				if(memcmp(word[item1], word[item2], sizeof(temptbl)))
				{
					break;
				}
			}
			if(j > i+1)
			{
				final[m++] = item1;
				for(q=i, chk=0; q<j; q++)
				{
					item2 = index[q];
					for(p=start[item2]; p<=end[item2]; p++)
					{
						if(!appear[p])
						{
							appear[p] = i + 1;
						}
						else
						{
							trueword[index[appear[p]-1]] = 1;
							chk = 1;
						}
					}
				}
				trueword[item1] = chk;
			}
		}
		qsort(final, m, sizeof(int), comp2);
		for(i=0; i<m; i++)
		{
			item1 = final[i];
			if(trueword[item1])
			{
				print(start[item1], end[item1]);
			}
			else
			{
				break;
			}
		}
		puts("*");
	}
	return 0;
}
