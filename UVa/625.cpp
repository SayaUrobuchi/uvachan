#include <stdio.h>
#include <string.h>

int n;
char kword[16][16] = {"var", "end", "for", "then", "else", "case", "goto", "const", 
					  "label", "while", "begin", "until", "repeat", "downto", "function", "procedure"};
char iword[2005][45];
char buf[2008];
char word[2008];

int letter(char now)
{
	return (now >= 'A' && now <= 'Z') || (now >= 'a' && now <= 'z');
}

int digit(char now)
{
	return now >= '0' && now <= '9';
}

int keyword(char *s)
{
	int i;
	for(i=0; i<16; i++)
	{
		if(!strcmp(kword[i], s))
		{
			return i+1;
		}
	}
	return 0;
}

int identifier(char *s)
{
	int i;
	for(i=0; i<n; i++)
	{
		if(!strcmp(iword[i], s))
		{
			return i+1;
		}
	}
	strcpy(iword[n++], s);
	return 0;
}

int main()
{
	int count, type;
	char *ptr, *p2;
	scanf("%d", &count);
	gets(buf);
	while(count--)
	{
		gets(buf);
		n = 0;
		while(gets(buf))
		{
			for(ptr=buf, p2=word; ; ptr++)
			{
				if(letter(*ptr) || digit(*ptr))
				{
					*(p2++) = *ptr;
				}
				else
				{
					*p2 = 0;
					if(type=keyword(word))
					{
						printf("&%d", type-1);
					}
					else if(p2 - word >= 3)
					{
						if(type=identifier(word))
						{
							printf("&%d", type+15);
						}
						else
						{
							printf("%s", word);
						}
					}
					else if(p2 - word)
					{
						printf("%s", word);
					}
					if(*ptr)
					{
						putchar(*ptr);
					}
					else
					{
						putchar('\n');
					}
					p2 = word;
				}
				if(!(*ptr))
				{
					break;
				}
			}
			if(!strcmp(buf, "end."))
			{
				break;
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
