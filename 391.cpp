#include <stdio.h>

char str[1000000];
char final[1000000];

int digit(int now)
{
	return now >= 48 && now <= 57;
}

int main()
{
	int i, j, k, pre, dot, dig;
	pre = 1;
	while(gets(str))
	{
		for(i=0, j=0; str[i]; i++)
		{
			if(str[i] == '\\' && (pre || str[i+1] == '*'))
			{
				if(str[i+1] == 'b' || str[i+1] == 'i')
				{
					i++;
				}
				else if(str[i+1] == 's')
				{
					for(k=i, i+=2, dot=dig=0; str[i]; i++)
					{
						if(str[i] == '.')
						{
							if(dot)
							{
								break;
							}
							dot = 1;
						}
						else if(!digit(str[i]))
						{
							break;
						}
						else
						{
							dig++;
						}
					}
					if(dig || i == k + 2)
					{
						i--;
					}
					else
					{
						i = k + 1;
					}
				}
				else if(str[i+1] == '*')
				{
					i++;
					pre = 1 - pre;
				}
				else if(str[i+1] == '\\')
				{
					i++;
					final[j++] = '\\';
				}
				else if(str[i+1])
				{
					final[j++] = str[i+1];
					i++;
				}
				else
				{
					final[j++] = str[i];
				}
			}
			else
			{
				final[j++] = str[i];
			}
		}
		final[j] = 0;
		printf("%s\n", final);
	}
	return 0;
}
