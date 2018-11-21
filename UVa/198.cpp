#include <stdio.h>
#include <string.h>

#define VARNUM 1000

int n, undef;
int used[VARNUM];
char name[VARNUM][55];
char exp[VARNUM][1001];
char str[1001];
char buf1[1001], buf2[1001];

int expression(char*, int, int);

int letter(char now)
{
	return (now > 64 && now < 91) || (now > 96 && now < 123);
}

int digit(char now)
{
	return now > 47 && now < 58;
}

int getaddr(char *s)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(!strcmp(s, name[i]))
		{
			return i;
		}
	}
	strcpy(name[n++], s);
	return i;
}

int factor(char *buf, int left, int right)
{
	int i, j, temp, addr, n1;
	char var[201];
	for(i=left; i<=right; i++)
	{
		if(buf[i] == '(')
		{
			for(j=right; j>i; j--)
			{
				if(buf[j] == ')')
				{
					return expression(buf, i+1, j-1);
				}
			}
		}
	}
	sscanf(buf+left, "%s", var);
	if(!letter(var[0]))
	{
		sscanf(var, "%d", &temp);
		return temp;
	}
	temp = n;
	addr = getaddr(var);
	if(n == temp)
	{
		if(used[addr])
		{
			undef = 1;
			return 0;
		}
		else
		{
			used[addr] = 1;
			n1 = expression(exp[addr], 0, strlen(exp[addr])-1);
			used[addr] = 0;
			return n1;
		}
	}
	else
	{
		n--;
		undef = 1;
		return 0;
	}
}

int term(char *buf, int left, int right)
{
	int i, parsis, n1, n2;
	for(i=left, parsis=0; i<=right; i++)
	{
		if(buf[i] == '(')
		{
			parsis++;
		}
		else if(buf[i] == ')')
		{
			parsis--;
		}
		else if(buf[i] == '*' && !parsis)
		{
			n1 = factor(buf, left, i-1);
			if(undef)
			{
				return 0;
			}
			n2 = factor(buf, i+1, right);
			if(undef)
			{
				return 0;
			}
			return n1 * n2;
		}
	}
	return factor(buf, left, right);
}

int expression(char* buf, int left, int right)
{
	int i, parsis, n1, n2, dig;
	for(i=left, parsis=0, dig=0; i<=right; i++)
	{
		if(buf[i] == '(')
		{
			parsis++;
			dig = 1;
		}
		else if(buf[i] == ')')
		{
			parsis--;
			dig = 1;
		}
		else if(!parsis && letter(buf[i]))
		{
			dig = 1;
		}
		else if((buf[i] == '+' || buf[i] == '-') && !parsis && dig)
		{
			n1 = term(buf, left, i-1);
			if(undef)
			{
				return 0;
			}
			n2 = term(buf, i+1, right);
			if(undef)
			{
				return 0;
			}
			if(buf[i] == '+')
			{
				return n1 + n2;
			}
			else
			{
				return n1 - n2;
			}
			dig = 0;
		}
		else if(digit(buf[i]) && !parsis)
		{
			dig = 1;
		}
	}
	return term(buf, left, right);
}

char *deal(char *s)
{
	int i, j, var;
	for(i=0, j=0, var=0; s[i]; )
	{
		if(letter(s[i]))
		{
			buf1[j++] = s[i];
			for(i++; s[i]; i++)
			{
				if(letter(s[i]) || digit(s[i]))
				{
					buf1[j++] = s[i];
				}
				else
				{
					break;
				}
			}
			buf1[j++] = ' ';
			var = 1;
		}
		else if(s[i] == '(' || s[i] == ')')
		{
			buf1[j++] = s[i++];
			buf1[j++] = ' ';
			var = 0;
		}
		else if(digit(s[i]) || (s[i] == '-' && !var))
		{
			buf1[j++] = s[i];
			for(i++; s[i]; i++)
			{
				if(digit(s[i]))
				{
					buf1[j++] = s[i];
				}
				else
				{
					break;
				}
			}
			buf1[j++] = ' ';
			var = 1;
		}
		else if(s[i] == '+' || s[i] == '-' || s[i] == '*')
		{
			buf1[j++] = s[i++];
			buf1[j++] = ' ';
			var = 0;
		}
		else
		{
			i++;
		}
	}
	buf1[j++] = 0;
	return buf1;
}

int main()
{
	int i, addr, ans, temp;
	n = 0;
	while(gets(str))
	{
		temp = sscanf(str, "%s%s", buf1, buf2);
		if(temp == EOF)
		{
			continue;
		}
		if(temp == 1 && !strcmp(buf1, "RESET"))
		{
			n = 0;
		}
		else if(strstr(str, ":="))
		{
			addr = getaddr(strtok(str, " :="));
			strcpy(exp[addr], deal(strtok(NULL, "\n")));
		}
		else
		{
			temp = n;
			addr = getaddr(buf2);
			if(temp == n)
			{
				memset(used, 0, sizeof(used));
				undef = 0;
				used[addr] = 1;
				ans = expression(exp[addr], 0, strlen(exp[addr])-1);
				if(undef)
				{
					printf("UNDEF\n");
				}
				else
				{
					printf("%d\n", ans);
				}
			}
			else
			{
				n--;
				printf("UNDEF\n");
			}
		}
	}
	return 0;
}
