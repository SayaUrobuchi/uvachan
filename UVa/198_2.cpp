#include <stdio.h>
#include <string.h>

#define VARNUM 1000

int n, undef;
int used[VARNUM];
char name[VARNUM][55];
char exp[VARNUM][1001];
char str[1001];
char buf1[1001], buf2[1001];

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

int expression(char* s)
{
	int i, j, c, parsis, temp, addr;
	int ary[500];
	char buf[1001], *ptr;
	char opera[500];
	for(i=0; sscanf(s, "%s", buf)!=EOF; s+=strlen(buf)+1)
	{
		if(buf[0] == '(')
		{
			parsis = 1;
			ptr = s += 2;
			for(; ; s++)
			{
				if(*s == '(')
				{
					parsis++;
				}
				else if(*s == ')')
				{
					parsis--;
					if(!parsis)
					{
						break;
					}
				}
			}
			*s = 0;
			ary[i] = expression(ptr);
			if(undef)
			{
				return 0;
			}
			*s = ')';
		}
		else if(letter(buf[0]))
		{
			temp = n;
			addr = getaddr(buf);
			if(temp == n)
			{
				if(!used[addr])
				{
					used[addr] = 1;
					ary[i] = expression(exp[addr]);
					used[addr] = 0;
				}
				else
				{
					undef = 1;
					return 0;
				}
			}
			else
			{
				n--;
				undef = 1;
				return 0;
			}
		}
		else if(buf[1] || digit(buf[0]))
		{
			sscanf(buf, "%d", &ary[i]);
		}
		else
		{
			opera[++i] = buf[0];
		}
	}
	c = i + 1;
	for(i=1, j=1; i<c; i++)
	{
		if(opera[i] == '*')
		{
			ary[j-1] *= ary[i];
		}
		else
		{
			ary[j] = ary[i];
			opera[j++] = opera[i];
		}
	}
	for(i=1; i<j; i++)
	{
		if(opera[i] == '+')
		{
			ary[0] += ary[i];
		}
		else
		{
			ary[0] -= ary[i];
		}
	}
	return ary[0];
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
				ans = expression(exp[addr]);
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
