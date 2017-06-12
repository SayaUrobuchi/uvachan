#include <stdio.h>
#include <string.h>

int main()
{
	int cas, count, n, sco, spe;
	char str[100];
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		printf("Hand #%d\n", ++cas);
		scanf("%d", &n);
		gets(str);
		sco = 0;
		spe = 0;
		while(n--)
		{
			gets(str);
			if(str[0] == 'f' && str[3] == 'l')
			{
				sco += 9;
				spe++;
			}
			else if(str[0] == 't' && str[6] == '-')
			{
				sco += 9;
				spe++;
			}
			else if(str[0] == 'o')
			{
				sco += 9;
				spe++;
			}
			else if(str[0] == 'k' && str[1] == 'i')
			{
				sco += 9;
			}
			else if(str[0] == 'q')
			{
				sco += 7;
			}
			else if(str[0] == 'k' && str[1] == 'n')
			{
				sco += 5;
			}
			else if(str[0] == 'j')
			{
				sco += 3;
			}
			else
			{
				sco++;
			}
		}
		sco /= 2;
		if(spe == 3)
		{
			sco -= 36;
		}
		else if(spe == 2)
		{
			sco -= 41;
		}
		else if(spe == 1)
		{
			sco -= 51;
		}
		else
		{
			sco -= 56;
		}
		if(sco < 0)
		{
			printf("Game lost by %d point(s).\n", -sco);
		}
		else
		{
			printf("Game won by %d point(s).\n", sco);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
