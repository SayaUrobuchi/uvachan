#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int val[1000][1000];
int used[1000][1000];
char *str[1000][1000];
char buf[10000000];

int is_digit(int c)
{
	return c >= '0' && c <= '9';
}

int is_alphabet(int c)
{
	return (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z');
}

int to_int(char *s)
{
	int res, f;
	f = 0;
	if(*s == '-')
	{
		f = 1;
		s++;
	}
	else if(*s == '+')
	{
		s++;
	}
	for(res=0; is_digit(*s); s++)
	{
		res *= 10;
		res += *s - '0';
	}
	return f?-res:res;
}

int calc_val(int p, int q, char *s)
{
	int sum, t, t2;
	int r, c;
	char *p1, *p2;
	if(p >= 0 && used[p][q])
	{
		return val[p][q];
	}
	if(*s == '=')
	{
		sum = 0;
		for(p1=++s, p2=p1; *p2; p2++)
		{
			if(*(p2+1) == '+' || *(p2+1) == '\0')
			{
				t = *(p2+1);
				sum += calc_val(-1, -1, p1);
				p1 = (++p2)+1;
				if(!t)
				{
					break;
				}
			}
		}
		used[p][q] = 1;
		return val[p][q]=sum;
	}
	else if(is_alphabet(*s))
	{
		for(r=0, t=0; is_alphabet(*s); s++, t++)
		{
			r *= 26;
			r += *s - 'A';
		}
		t2 = 26;
		while(--t>0)
		{
			r += t2;
			t2 *= 26;
		}
		for(c=0; is_digit(*s); s++)
		{
			c *= 10;
			c += *s - '0';
		}
		c--;
		return val[c][r]=calc_val(c, r, str[c][r]);
	}
	else
	{
		used[p][q] = 1;
		return val[p][q]=to_int(s);
	}
}

int main()
{
	int count, n, m, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%s", buf);
				if(str[i][j])
				{
					free(str[i][j]);
				}
				str[i][j] = (char*)malloc(strlen(buf)+1);
				strcpy(str[i][j], buf);
				used[i][j] = 0;
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(j)
				{
					printf(" ");
				}
				if(!used[i][j])
				{
					val[i][j]=calc_val(i, j, str[i][j]);
				}
				printf("%d", val[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}
