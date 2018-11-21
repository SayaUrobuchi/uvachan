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
			for(i=0, j=-1; s[i]; i++)
			{	
				if(j == -1 || s[i] == s[j])
				{	
					i++;
					j++;	
					if(s[i] != s[j])
					{	
						next[i] = j;
					}
					else
					{
						next[i] = next[j];
					}
				}
				else
				{
					j = next[j];
				}
			}
			len = i;
			for(i=0, j=0; str[i]&&j<len; )
			{
				if(j == -1 || str[i] == s[j])
				{
					i++;
					j++;
				}
				else
				{
					j = next[j];
				}
			}
			if(j != len)
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

