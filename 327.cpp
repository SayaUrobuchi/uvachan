#include <stdio.h>
#include <string.h>

int used[128];
int value[128];
int extra[128];
char buf[1005];

int isletter(int now)
{
	return now >= 'a' && now <= 'z';
}

int main()
{
	int i, v;
	char *ptr, *back;
	while(gets(buf))
	{
		memset(used, 0, sizeof(used));
		memset(extra, 0, sizeof(extra));
		for(i=97; i<=122; i++)
		{
			value[i] = i - 96;
		}
		printf("Expression: %s\n", buf);
		for(ptr=back=buf; *ptr; ptr++)
		{
			if(*ptr != ' ')
			{
				*(back++) = *ptr;
				if(isletter(*ptr))
				{
					used[*ptr] = 1;
					if(back-buf >= 3 && *(back-2) == *(back-3))
					{
						if(*(back-2) == '+')
						{
							value[*(back-1)]++;
						}
						else
						{
							value[*(back-1)]--;
						}
						*(back-3) = *(back-1);
						back -= 2;
					}
				}
			}
		}
		*back = 0;
		for(ptr=back=buf; *ptr; ptr++)
		{
			*(back++) = *ptr;
			if(isletter(*ptr))
			{
				if(*(ptr+1) == *(ptr+2) && *(ptr+1))
				{
					if(*(ptr+1) == '+')
					{
						extra[*ptr]++;
					}
					else
					{
						extra[*ptr]--;
					}
					ptr += 2;
				}
			}
		}
		*back = 0;
		v = value[*buf];
		for(ptr=buf+1; *ptr; ptr++)
		{
			if(*ptr == '+')
			{
				v += value[*(++ptr)];
			}
			else
			{
				v -= value[*(++ptr)];
			}
		}
		printf("    value = %d\n", v);
		for(i=97; i<=122; i++)
		{
			if(used[i])
			{
				printf("    %c = %d\n", i, value[i]+extra[i]);
			}
		}
	}
	return 0;
}
