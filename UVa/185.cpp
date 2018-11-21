#include <stdio.h>
#include <string.h>

int c;
int appear[8];
int list[7];
int used[7];
int tbl[128];
char digit[4][10][10] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", 
						 "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", 
						 "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", 
						 "", "M", "MM", "MMM", "", "", "", "", "", ""};
char num[4000][30];
char buf[2008];
char *s1, *s2, *s3;

void getappear(char *s)
{
	for(; *s; s++)
	{
		appear[tbl[*s]] = 1;
	}
}

int getnum(char *s)
{
	int i;
	for(i=1; i<4000; i++)
	{
		if(!strcmp(s, num[i]))
		{
			return i;
		}
	}
	return 0;
}

int getanum(char *s)
{
	int res;
	if(!list[tbl[*s]])
	{
		return 0;
	}
	for(res=0; *s; s++)
	{
		res *= 10;
		res += list[tbl[*s]];
	}
	return res;
}

int chk()
{
	int i, j, k;
	i = getanum(s1);
	j = getanum(s2);
	k = getanum(s3);
	return i && j && k && i+j == k;
}

int dfs(int depth)
{
	int i;
	if(depth == 7)
	{
		c += chk();
		if(c == 2)
		{
			return 1;
		}
		return 0;
	}
	if(!appear[depth])
	{
		return dfs(depth+1);
	}
	for(i=0; i<10; i++)
	{
		if(!used[i])
		{
			used[i] = 1;
			list[depth] = i;
			if(dfs(depth+1))
			{
				return 1;
			}
			used[i] = 0;
		}
	}
	return 0;
}

int main()
{
	int i, j;
	tbl['I'] = 0;
	tbl['V'] = 1;
	tbl['X'] = 2;
	tbl['L'] = 3;
	tbl['C'] = 4;
	tbl['D'] = 5;
	tbl['M'] = 6;
	tbl['+'] = tbl['='] = 7;
	for(i=1; i<4000; i++)
	{
		sprintf(buf, "%04d", i);
		num[i][0] = 0;
		for(j=0; j<4; j++)
		{
			strcat(num[i], digit[3-j][buf[j]-48]);
		}
	}
	while(gets(buf))
	{
		if(!strcmp(buf, "#"))
		{
			break;
		}
		memset(appear, 0, sizeof(appear));
		getappear(buf);
		s1 = strtok(buf, "+");
		s2 = strtok(NULL, "=");
		s3 = strtok(NULL, "=");
		if(getnum(s1) + getnum(s2) == getnum(s3))
		{
			printf("Correct ");
		}
		else
		{
			printf("Incorrect ");
		}
		c = 0;
		memset(used, 0, sizeof(used));
		dfs(0);
		if(!c)
		{
			printf("impossible\n");
		}
		else if(c == 1)
		{
			printf("valid\n");
		}
		else
		{
			printf("ambiguous\n");
		}
	}
	return 0;
}
