#include <stdio.h>
#include <string.h>

int buff[10];
char dig[4][10][20] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX",
					   "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC",
					   "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM",
					   "", "M", "MM", "MMM", "", "", "", "", "", ""};
char num[4000][20], buf[10005], cmd[10005];

void reset()
{
	memset(buff, -1, sizeof(buff));
}

int search(char* s)
{
	int i, res;
	for(res=0; *s=='M'&&*s; s++, res+=1000);
	if(*s)
	{
		for(i=0; i<4000; i++)
		{
			if(strcmp(s, num[i]) == 0)
			{
				return i+res;
			}
		}
	}
	else
	{
		return res;
	}
	return -1;
}

int getflag(char s)
{
	if(s == '+')
	{
		return 0;
	}
	return 1;
}

int calc(char* s)
{
	int f, res, temp;
	char *ptr;
	for(f=0, res=0; *s; s=ptr)
	{
		for(ptr=s; *ptr; ptr++)
		{
			if(*ptr == '+' || *ptr == '-')
			{
				break;
			}
		}
		if(ptr == s)
		{
			temp = 0;
		}
		else
		{
			sprintf(buf, "%.*s", ptr-s, s);
			if(buf[0] >= '0' && buf[0] <= '9')
			{
				if(buff[*buf-'0'] == -1)
				{
					return -1;
				}
				temp = buff[*buf-'0'];
			}
			else
			{
				temp = search(buf);
			}
		}
		if(temp == -1)
		{
			return -1;
		}
		if(f)
		{
			res -= temp;
		}
		else
		{
			res += temp;
		}
		f = getflag(*ptr);
		if(*ptr)
		{
			ptr++;
		}
	}
	if(res > 10000 || res < 0)
	{
		res = -1;
	}
	return res;
}

void trans(char s, int res)
{
	printf("%c=", s);
	if(res == 0)
	{
		printf("%s", num[0]);
	}
	else
	{
		for(; res>=1000; res-=1000)
		{
			putchar('M');
		}
		if(res)
		{
			printf("%s", num[res]);
		}
	}
	putchar(10);
}

int main()
{
	int i, j, res;
	char *ptr;
	reset();
	strcpy(num[0], "O");
	for(i=1; i<4000; i++)
	{
		sprintf(buf, "%04d", i);
		for(j=0, ptr=num[i]; j<4; j++)
		{
			strcpy(ptr, dig[3-j][buf[j]-'0']);
			ptr += strlen(ptr);
		}
	}
	while(gets(cmd))
	{
		if(strcmp(cmd, "RESET") == 0)
		{
			reset();
			puts("Ready");
		}
		else if(strcmp(cmd, "QUIT") == 0)
		{
			puts("Bye");
			break;
		}
		else
		{
			res = calc(cmd+2);
			if(res == -1)
			{
				puts("Error");
			}
			else
			{
				buff[*cmd-'0'] = res;
				trans(*cmd, res);
			}
		}
	}
	return 0;
}
