#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char buf[11], buf2[11], stack[200000][11];
int index;

char pop()
{
	if(index)
	{
		strcpy(buf, stack[--index]);
		return 1;
	}
	return 0;
}

void push()
{
	strcpy(stack[index++], buf2);
}

int main()
{
	int cas, n, m, i, line;
	char ans, str, *str2, end;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		ans = 0;
		gets(buf2);
		index = 0;
		for(m=0; m<n; m++)
		{
			if(ans)
			{
				gets(buf);
			}
			else
			{
				while(scanf("%c", &str) == 1)
				{
					if(str == '<')
					{
						scanf("%c", &str);
						end = 0;
						if(str == '/')
						{
							end = 1;
							scanf("%c", &str);
						}
						for(i=0, str2=buf2; ; i++)
						{
							if(str == '>')
							{
								if(!i)
								{
									ans = 2;
									line = m + 1;
								}
								break;
							}
							if(str < 65 || str > 90)
							{
								ans = 1;
								line = m + 1;
								break;
							}
							if(i == 10)
							{
								ans = 2;
								line = m + 1;
								break;
							}
							*(str2++) = str;
							scanf("%c", &str);
							if(str == 10)
							{
								break;
							}
						}
						if(str == 10)
						{
							ans = 1;
							line = m + 1;
							break;
						}
						if(ans)
						{
							gets(buf);
							break;
						}
						*str2 = 0;
						if(end)
						{
							if(pop())
							{
								if(strcmp(buf, buf2))
								{
									strcpy(buf2, buf);
									push();
									ans = 4;
									line = m + 1;
									gets(buf);
									break;
								}
							}
							else
							{
								ans = 3;
								line = m + 1;
								gets(buf);
								break;
							}
						}
						else
						{
							push();
						}
					}
					if(str == 10)
					{
						break;
					}
				}
			}
		}
		printf("Test Case %d\n", ++cas);
		if(ans)
		{
			if(ans == 1)
			{
				printf("line %d: bad character in tag name.\n", line);
			}
			else if(ans == 2)
			{
				printf("line %d: too many/few characters in tag name.\n", line);
			}
			else if(ans == 3)
			{
				printf("line %d: no matching begin tag.\n", line);
			}
			else
			{
				pop();
				printf("line %d: expected </%s>\n", line, buf2);
			}
		}
		else
		{
			if(index)
			{
				pop();
				printf("line %d: expected </%s>\n", n, buf);
			}
			else
			{
				printf("OK\n");
			}
		}
	}
	return 0;
}
