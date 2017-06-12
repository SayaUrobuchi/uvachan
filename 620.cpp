#include <stdio.h>
#include <string.h>

char str[10000];

int mutagenic(int, int);

int simple(int left, int right)
{
	return left == right && str[left] == 'A';
}

int fully(int left, int right)
{
	return right - left > 1 && (simple(left, right-2) || fully(left, right-2) || mutagenic(left, right-2)) && str[right-1] == 'A' && str[right] == 'B';
}

int mutagenic(int left, int right)
{
	return right - left > 1 && str[left] == 'B' && str[right] == 'A' && (simple(left+1, right-1) || fully(left+1, right-1) || mutagenic(left+1, right-1));
}

int main()
{
	int count, len;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		len = strlen(str);
		if(simple(0, len-1))
		{
			printf("SIMPLE\n");
		}
		else if(fully(0, len-1))
		{
			printf("FULLY-GROWN\n");
		}
		else if(mutagenic(0, len-1))
		{
			printf("MUTAGENIC\n");
		}
		else
		{
			printf("MUTANT\n");
		}
	}
	return 0;
}
