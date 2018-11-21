#include <stdio.h>
#include <string.h>

int c, ans, num, qnum;
int value[9];
int queue[9];
char buf[2008];
char shape[9][8];
char nshape[10][8] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};

void getinput()
{
	int i, j;
	memset(buf, ' ', sizeof(buf));
	gets(buf);
	for(i=1, j=0; i<27; i+=3, j++)
	{
		if(buf[i] == '_')
		{
			shape[j][0] = '1';
		}
		else
		{
			shape[j][0] = '0';
		}
	}
	memset(buf, ' ', sizeof(buf));
	gets(buf);
	for(i=1, j=0; i<27; i+=3, j++)
	{
		if(buf[i-1] == '|')
		{
			shape[j][1] = '1';
		}
		else
		{
			shape[j][1] = '0';
		}
		if(buf[i] == '_')
		{
			shape[j][3] = '1';
		}
		else
		{
			shape[j][3] = '0';
		}
		if(buf[i+1] == '|')
		{
			shape[j][2] = '1';
		}
		else
		{
			shape[j][2] = '0';
		}
	}
	memset(buf, ' ', sizeof(buf));
	gets(buf);
	for(i=1, j=0; i<27; i+=3, j++)
	{
		if(buf[i-1] == '|')
		{
			shape[j][4] = '1';
		}
		else
		{
			shape[j][4] = '0';
		}
		if(buf[i] == '_')
		{
			shape[j][6] = '1';
		}
		else
		{
			shape[j][6] = '0';
		}
		if(buf[i+1] == '|')
		{
			shape[j][5] = '1';
		}
		else
		{
			shape[j][5] = '0';
		}
	}
}

int getvalue(char *s)
{
	int i;
	for(i=0; i<10; i++)
	{
		if(!strcmp(s, nshape[i]))
		{
			return i;
		}
	}
	return -1;
}

int getnum()
{
	int i, res;
	for(i=0, res=0; i<9; i++)
	{
		if(value[i] != -1)
		{
			res += value[i] * (9-i);
		}
	}
	return res;
}

int getans()
{
	int i, j, res;
	for(i=8, j=1, res=0; i>=0; i--, j*=10)
	{
		res += value[i] * j;
	}
	return res;
}

void dochange(int now)
{
	int i, j;
	for(i=0; i<10; i++)
	{
		for(j=0; j<7; j++)
		{
			if(shape[now][j] == '1' && nshape[i][j] == '0')
			{
				break;
			}
		}
		if(j == 7)
		{
			if(!((num + i * (9-now)) % 11))
			{
				if(c++)
				{
					return;
				}
				value[now] = i;
				ans = getans();
			}
		}
	}
}

int main()
{
	int count, i, temp;
	scanf("%d", &count);
	gets(buf);
	while(count--)
	{
		getinput();
		for(i=0, qnum=0; i<9; i++)
		{
			shape[i][7] = 0;
			/*puts(shape[i]);*/
			value[i] = getvalue(shape[i]);
			if(value[i] == -1)
			{
				queue[qnum++] = i;
			}
		}
		/*printf("%d\n", qnum);*/
		if(qnum > 1)
		{
			puts("failure");
		}
		else if(qnum == 1)
		{
			c = 0;
			num = getnum();
			dochange(queue[0]);
			if(!c)
			{
				puts("failure");
			}
			else if(c == 1)
			{
				printf("%09d\n", ans);
			}
			else
			{
				puts("ambiguous");
			}
		}
		else
		{
			c = 0;
			num = getnum();
			if(!(num % 11))
			{
				c++;
				ans = getans();
			}
			else
			{
				for(i=0; i<9&&c<2; i++)
				{
					temp = value[i];
					value[i] = -1;
					num = getnum();
					dochange(i);
					value[i] = temp;
				}
			}
			if(!c)
			{
				puts("failure");
			}
			else if(c == 1)
			{
				printf("%09d\n", ans);
			}
			else
			{
				puts("ambiguous");
			}
		}
	}
	return 0;
} 
