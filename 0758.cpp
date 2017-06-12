#include <stdio.h>
#include <string.h>

int nam[1005], p1[1005], p2[1005], fre[10005], prio[10005], used[10005];
char ss[1005][1005], buf[10005], str[1005];

void travel(int t, char *pp)
{
	if(nam[t] != -1)
	{
		*pp = 0;
		strcpy(ss[nam[t]], buf);
		return;
	}
	*pp = '0';
	travel(p1[t], pp+1);
	*pp = '1';
	travel(p2[t], pp+1);
}

int main()
{
	int cas, len, i, j, k, siz, m, min, temp;
	cas = 0;
	while(scanf("%d%s", &len, str) == 2)
	{
		memset(fre, 0, sizeof(fre));
		for(i=0, siz=0; i<len; i++)
		{
			for(j=0; j<siz; j++)
			{
				if(nam[j] == str[i])
				{
					break;
				}
			}
			if(j == siz)
			{
				nam[j] = str[i];
				prio[j] = i;
				siz++;
			}
			fre[j]++;
		}
		memset(used, 0, sizeof(used));
		for(i=1, m=siz; i<siz; i++)
		{
			for(j=0, min=2147483647; j<m; j++)
			{
				if(used[j] == 0 && fre[j] < min)
				{
					min = fre[j];
					temp = j;
				}
				else if(used[j] == 0 && fre[j]==min && prio[j] < prio[temp])
				{
					temp = j;
				}
			}
			used[k=temp] = 1;
			for(j=0, min=2147483647; j<m; j++)
			{
				if(used[j] == 0 && fre[j] < min)
				{
					min = fre[j];
					temp = j;
				}
				else if(used[j] == 0 && fre[j]==min && prio[j] < prio[temp])
				{
					temp = j;
				}
			}
			used[j=temp] = 1;
			if(prio[k] > prio[j])
			{
				temp = k;
				k = j;
				j = temp;
			}
			p1[m] = k;
			p2[m] = j;
			fre[m] = fre[j]+fre[k];
			nam[m] = -1;
			prio[m] = (prio[j]<prio[k]?prio[j]:prio[k]);
			m++;
		}
		travel(m-1, buf);
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		if(siz == 1)
		{
			strcpy(ss[str[0]], "0");
		}
		for(i=0; i<len; i++)
		{
			printf("%s%s", i?" ":"", ss[str[i]]);
		}
		printf("\n");
	}
	return 0;
}
