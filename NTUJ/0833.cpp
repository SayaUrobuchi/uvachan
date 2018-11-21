#include <stdio.h>
#include <string.h>

char s1[10000001], s2[10000001];

int illegal(char *s)
{
	int i;
	for(i=0; s[i]; i++)
	{
		if(s[i] < 65)
		{
			break;
		}
	}
	if(i != 3 && i != 5)
	{
		return 1;
	}
	if(i == 3)
	{
		return s[4] >= 65;
	}
	else if(i == 5)
	{
		for(i=0; s[i]; i++)
		{
			if(s[i] == 'A' || s[i] == 'C' || s[i] == 'M' || s[i] == 'I' || s[i] == 'P')
			{
				return 1;
			}
		}
	}
	return 0;
}

int get_id(int c)
{
	int r;
	r = 0;
	if(c > 'A')
	{
		r++;
	}
	if(c > 'C')
	{
		r++;
	}
	if(c > 'M')
	{
		r++;
	}
	if(c > 'I')
	{
		r++;
	}
	if(c > 'P')
	{
		r++;
	}
	return c-r-65;
}

long long translate(char *s)
{
	int i;
	long long res;
	for(i=0; s[i]; i++)
	{
		if(s[i] < 65)
		{
			break;
		}
	}
	if(i == 3)
	{
		res = 0;
		res += (s[0]-65) * 26 * 26 * 10 * 10 * 10 * 10;
		res += (s[1]-65) * 26 * 10 * 10 * 10 * 10;
		res += (s[2]-65) * 10 * 10 * 10 * 10;
		res += (s[3]-48) * 10 * 10 * 10;
		res += (s[4]-48) * 10 * 10;
		res += (s[5]-48) * 10;
		res += (s[6]-48);
	}
	else
	{
		res = 26 * 26 * 26 * 10 * 10 * 10 * 10;
		res += get_id(s[0]) * 21 * 21 * 21 * 21 * 10 * 10;
		res += get_id(s[1]) * 21 * 21 * 21 * 10 * 10;
		res += get_id(s[2]) * 21 * 21 * 10 * 10;
		res += get_id(s[3]) * 21 * 10 * 10;
		res += get_id(s[4]) * 10 * 10;
		res += (s[5]-48) * 10;
		res += s[6]-48;
	}
	return res;
}

int main()
{
	int c;
	long long n1, n2;
	while(scanf("%s%s%d", s1, s2, &c) == 3)
	{
		if(strcmp(s1, "*") == 0 && strcmp(s2, "*") == 0 && c == 0)
		{
			break;
		}
		if(illegal(s2))
		{
			printf("N\n");
			continue;
		}
		n1 = translate(s1);
		n2 = translate(s2);
		if(n2 > n1 && n2 <= n1+c)
		{
			printf("Y\n");
		}
		else
		{
			printf("N\n");
		}
	}
	return 0;
}
