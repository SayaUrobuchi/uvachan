#include <stdio.h>

char target[100];
char ope[100];
char s1[100], s2[100];

int decode(char now)
{
	if(now == 'V')
	{
		return 0;
	}
	if(now == 'U')
	{
		return 1;
	}
	if(now == 'C')
	{
		return 2;
	}
	return 3;
}

int trans(char *s)
{
	int i, result;
	for(i=0, result=0; s[i]; i++)
	{
		result <<= 2;
		result += decode(s[i]);
	}
	return result;
}

int main()
{
	int count, n1, n2, i, tar;
	printf("COWCULATIONS OUTPUT\n");
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s%s%s%s%s", s1, s2, ope, ope+1, ope+2, target);
		n1 = trans(s1);
		n2 = trans(s2);
		tar = trans(target);
		for(i=0; i<3; i++)
		{
			if(ope[i] == 'A')
			{
				n2 += n1;
			}
			else if(ope[i] == 'R')
			{
				n2 >>= 2;
			}
			else if(ope[i] == 'L')
			{
				n2 <<= 2;
			}
		}
		if(n2 == tar)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
	}
	printf("END OF OUTPUT\n");
	return 0;
}
