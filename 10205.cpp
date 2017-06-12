#include <stdio.h>
#include <stdlib.h>

char method[100][52], table[52], tmp[52], buf[10];

char* value(int n)
{
	if(n < 9)
	{
		sprintf(buf, "%d", n+2);
		return buf;
	}
	else if(n == 9)
	{
		return "Jack";
	}
	else if(n == 10)
	{
		return "Queen";
	}
	else if(n == 11)
	{
		return "King";
	}
	return "Ace";
}

char* suit(int n)
{
	if(!n)
	{
		return "Clubs";
	}
	else if(n == 1)
	{
		return "Diamonds";
	}
	else if(n == 2)
	{
		return "Hearts";
	}
	return "Spades";
}

int main()
{
	int count, n, i, j, tmp2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<52; j++)
			{
				scanf("%d", &tmp2);
				method[i][j] = tmp2-1;
			}
		}
		for(i=0; i<52; i++)
		{
			table[i] = i;
		}
		gets(buf);
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			tmp2 = atoi(buf) - 1;
			for(i=0; i<52; i++)
			{
				tmp[i] = table[method[tmp2][i]];
			}
			for(i=0; i<52; i++)
			{
				table[i] = tmp[i];
			}
		}
		for(i=0; i<52; i++)
		{
			tmp2 = table[i];
			printf("%s of %s\n", value(tmp2 % 13), suit(tmp2 / 13));
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}