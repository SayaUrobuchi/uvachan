#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tbl[128];
char s[1000005];

int is_symb(int c)
{
	return c == '+' || c == '-' || c == '*' || c == '/' || c == '%';
}

int recurs(int p, int q)
{
	int i, cnt, loc, prio;
	if(s[p] == '(')
	{
		for(i=p+1, cnt=1; i<=q&&cnt; i++)
		{
			if(s[i] == '(')
			{
				cnt++;
			}
			else if(s[i] == ')')
			{
				cnt--;
			}
		}
		if(i > q)
		{
			return recurs(p+1, q-1);
		}
	}
	for(i=p, cnt=0, prio=-1; i<=q; i++)
	{
		if(s[i] == '(')
		{
			cnt++;
		}
		else if(s[i] == ')')
		{
			cnt--;
		}
		else if(cnt == 0 && is_symb(s[i]))
		{
			if(tbl[s[i]] > prio)
			{
				prio = tbl[s[i]];
				loc = i;
			}
			else if(tbl[s[i]] == prio)
			{
				loc = i;
			}
		}
	}
	if(prio == -1)
	{
		return atoi(s+p);
	}
	if(s[loc] == '+')
	{
		return recurs(p, loc-1) + recurs(loc+1, q);
	}
	else if(s[loc] == '-')
	{
		return recurs(p, loc-1) - recurs(loc+1, q);
	}
	else if(s[loc] == '*')
	{
		return recurs(p, loc-1) * recurs(loc+1, q);
	}
	else if(s[loc] == '/')
	{
		return recurs(p, loc-1) / recurs(loc+1, q);
	}
	else if(s[loc] == '%')
	{
		return recurs(p, loc-1) % recurs(loc+1, q);
	}
}

int main()
{
	int i, j;
	tbl['+'] = tbl['-'] = 1;
	while(gets(s))
	{
		for(i=0, j=0; s[i]; i++)
		{
			if(s[i] != ' ')
			{
				s[j++] = s[i];
			}
		}
		s[j] = 0;
		printf("%d\n", recurs(0, strlen(s)-1));
	}
	return 0;
}
