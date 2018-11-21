#include <stdio.h>

int num[3];
char s[200];

int max(int p, int q)
{
	return p>q ? p : q;
}

int min(int p, int q)
{
	return p<q ? p : q;
}

int isdig(char c)
{
	return c >= '0' && c <= '9';
}

int ischr(char c)
{
	return c >= 'P' && c <= 'R';
}

int recursion(int p, int q)
{
	int i, c;
	/*printf("calc %.*s\n", q-p+1, s+p);*/
	if(s[p] == '(')
	{
		for(i=p+1, c=1; i<=q&&c; i++)
		{
			if(s[i] == '(')
			{
				c++;
			}
			else if(s[i] == ')')
			{
				c--;
			}
		}
		if(c == 0 && i > q)
		{
			return recursion(p+1, q-1);
		}
	}
	for(i=p, c=0; i<=q; i++)
	{
		if(s[i] == '(')
		{
			c++;
		}
		else if(s[i] == ')')
		{
			c--;
		}
		else if(s[i] == '+' && c == 0)
		{
			return max(recursion(p, i-1), recursion(i+1, q));
		}
		else if(s[i] == '*' && c == 0)
		{
			return min(recursion(p, i-1), recursion(i+1, q));
		}
	}
	for(i=p; i<=q; i++)
	{
		if(s[i] == '-')
		{
			return 2 - recursion(i+1, q);
		}
		else if(isdig(s[i]))
		{
			return s[i] - 48;
		}
		else if(ischr(s[i]))
		{
			return num[s[i]-'P'];
		}
	}
}

int main()
{
	int i, j, k, ans;
	char *p;
	while(gets(s))
	{
		if(s[0] == '.')
		{
			break;
		}
		for(p=s; *p; p++);
		for(i=0, ans=0; i<=2; i++)
		{
			num[0] = i;
			for(j=0; j<=2; j++)
			{
				num[1] = j;
				for(k=0; k<=2; k++)
				{
					num[2] = k;
					if(recursion(0, p-s-1) == 2)
					{
						ans++;
					}
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
