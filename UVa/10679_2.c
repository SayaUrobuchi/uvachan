#include <stdio.h>

int next[1005];
char str[100005], s[1005];

int main()
{
	int count, m, i, j, len;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d", str, &m);
		while(m--)
		{
			scanf("%s", s);
			next[0] = -1;
			for(i=0, j=0; s[i]; i++)
			{
				if(i == 0)
				{
					next[i+1] = 0;
					continue;
				}
				if(s[i] == s[j])
				{
					next[i+1] = ++j;
				}
				else
				{
					j = 0;
					if(s[i] == s[j])
					{
						next[i+1] = ++j;
					}
					else
					{
						next[i+1] = 0;
					}
				}
				next[i+1] = next[next[i+1]];
			}
			len = i;
			for(i=0, j=0; str[i]&&s[j]; )
			{
				if(str[i] == s[j])
				{
					i++;
					j++;
				}
				else
				{
					if(next[j] == -1)
					{
						i++;
						j = 0;
					}
					else
					{
						j = next[j];
					}
				}
			}
			if(s[j])
			{
				printf("n\n");
			}
			else
			{
				printf("y\n");
			}
		}
	}
	return 0;
}

