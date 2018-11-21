#include <stdio.h>
#include <string.h>

#define INDETERMINED 2147483647
#define ADD 0
#define SUB 1

int fail, evaluated[20][20], used[20][20], value[20][20];
char exp[20][20][80], str[80];

int ope(char ch)
{
	return ch == '+' || ch == '-';
}

int analyze(int p, int q)
{
	int temp, op;
	char *s, *ptr, buf[100];
	if(used[p][q])
	{
		return value[p][q]=INDETERMINED;
	}
	if(evaluated[p][q])
	{
		return value[p][q];
	}
	evaluated[p][q] = 1;
	used[p][q] = 1;
	s = exp[p][q];
	if(sscanf(s, "%d", &temp) == 1)
	{
		value[p][q] = temp;
	}
	else
	{
		for(value[p][q]=0, op=ADD, ptr=buf; *s; s++)
		{
			if(ope(*s))
			{
				*ptr = 0;
				if(sscanf(buf, "%d", &temp) != 1)
				{
					temp = analyze(buf[0]-65, buf[1]-48);
				}
				if(temp == INDETERMINED)
				{
					return value[p][q]=INDETERMINED;
				}
				if(op == ADD)
				{
					value[p][q] += temp;
				}
				else
				{
					value[p][q] -= temp;
				}
				if(*s == '+')
				{
					op = ADD;
				}
				else
				{
					op = SUB;
				}
				ptr = buf;
			}
			else
			{
				*(ptr++) = *s;
			}
		}
		*ptr = 0;
		if(sscanf(buf, "%d", &temp) != 1)
		{
			temp = analyze(buf[0]-65, buf[1]-48);
		}
		if(temp == INDETERMINED)
		{
			return value[p][q]=INDETERMINED;
		}
		if(op == ADD)
		{
			value[p][q] += temp;
		}
		else
		{
			value[p][q] -= temp;
		}
	}
	used[p][q] = 0;
	return value[p][q];
}

char *name(int p, int q)
{
	str[0] = p + 65;
	str[1] = q + 48;
	str[2] = 0;
	return str;
}

int main()
{
	int n, m, i, j;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				scanf("%s", exp[i][j]);
			}
		}
		memset(used, 0, sizeof(used));
		memset(evaluated, 0, sizeof(evaluated));
		fail = 0;
		for(i=0; i<n; i++)
		{
			for(j=0; j<m; j++)
			{
				if(analyze(i, j) == INDETERMINED)
				{
					fail = 1;
				}
			}
		}
		if(fail)
		{
			for(i=0; i<n; i++)
			{
				for(j=0; j<m; j++)
				{
					if(value[i][j] == INDETERMINED)
					{
						printf("%s: %s\n", name(i, j), exp[i][j]);
					}
				}
			}
		}
		else
		{
			printf(" ");
			for(i=0; i<m; i++)
			{
				printf("%6d", i);
			}
			printf("\n");
			for(i=0; i<n; i++)
			{
				printf("%c", i+65);
				for(j=0; j<m; j++)
				{
					printf("%6d", value[i][j]);
				}
				printf("\n");
			}
		}
		printf("\n");
	}
	return 0;
}
