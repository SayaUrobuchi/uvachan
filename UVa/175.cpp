#include <stdio.h>
#include <string.h>

int between[51];
int num[51], tnum[251];
int tbl[2000];
char keyword[51][101][101];
char ary[251][101][101];
char str[2000];

int letter(char now)
{
	return (now > 64 && now < 91) || (now > 96 && now < 123);
}

int lowercase(char now)
{
	if(now < 91)
	{
		return now + 32;
	}
	return now;
}

int main()
{
	int n, m, i, j, k, l, p, q, chk, match;
	char *ptr, *pointer;
	n = 0;
	while(gets(str))
	{
		if(str[0] != 'P')
		{
			break;
		}
		sscanf(str+2, "%d", &between[n]);
		ptr = strtok(str+2, " ");
		num[n] = 0;
		while(ptr=strtok(NULL, " "))
		{
			strcpy(keyword[n][num[n]++], ptr);
		}
		n++;
	}
	m = 1;
	do
	{
		if(!strcmp(str, "#"))
		{
			break;
		}
		ptr = str + strlen(str);
		if(*(ptr-1) != '|')
		{
			while(gets(ptr))
			{
				ptr += strlen(ptr);
				if(*(ptr-1) == '|')
				{
					break;
				}
			}
		}
		tnum[m] = 0;
		ptr = strtok(str+2, " ");
		do
		{
			pointer = ary[m][tnum[m]];
			for(i=0, j=0; ptr[i]; i++)
			{
				if(letter(ptr[i]))
				{
					pointer[j++] = lowercase(ptr[i]);
				}
			}
			if(j)
			{
				pointer[j] = 0;
				tnum[m]++;
			}
		}while(ptr=strtok(NULL, " "));
		m++;
	}while(gets(str));
	for(i=0; i<n; i++)
	{
		printf("%d: ", i+1);
		for(j=1, chk=0; j<m; j++)
		{
			memset(tbl, 0, sizeof(tbl));
			for(k=0, match=0; k<tnum[j]; k++)
			{
				for(l=0; l<num[i]; l++)
				{
					if(!strcmp(ary[j][k], keyword[i][l]))
					{
						tbl[k] = l + 1;
						for(p=k-1, q=0; q<=between[i]&&p>-1; p--, q++)
						{
							if(tbl[p] && tbl[p] != tbl[k])
							{
								match = 1;
								break;
							}
						}
						if(match)
						{
							break;
						}
					}
				}
				if(match)
				{
					break;
				}
			}
			if(match)
			{
				if(chk)
				{
					printf(",");
				}
				chk = 1;
				printf("%d", j);
			}
		}
		printf("\n");
	}
	scanf(" ");
	return 0;
}
