#include <stdio.h>
#include <string.h>

char s1[101], s2[101], res[101];

void rev(char *s)
{
	int i, j, temp;
	for(i=0, j=strlen(s)-1; i<j; i++, j--)
	{
		temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

int main()
{
	int cas, count, i, c;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s", s1, s2);
		rev(s1);
		rev(s2);
		for(i=0, c=0; s1[i]&&s2[i]; i++)
		{
			res[i] = s1[i] + s2[i] + c - 48;
			c = 0;
			if(res[i] > '1')
			{
				res[i] -= 2;
				c = 1;
			}
		}
		if(s1[i])
		{
			for(; s1[i]; i++)
			{
				res[i] = s1[i] + c;
				c = 0;
				if(res[i] > '1')
				{
					res[i] -= 2;
					c = 1;
				}
			}
		}
		else
		{
			for(; s2[i]; i++)
			{
				res[i] = s2[i] + c;
				c = 0;
				if(res[i] > '1')
				{
					res[i] -= 2;
					c = 1;
				}
			}
		}
		if(c)
		{
			res[i++] = '1';
		}
		for(i--; i>0&&res[i]=='0'; i--);
		res[++i] = 0;
		rev(res);
		printf("%d %s\n", ++cas, res);
	}
	return 0;
}
