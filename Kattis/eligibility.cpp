#include <stdio.h>

char nam[1024];

int main()
{
	int count, study, birth, seme;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%d%*s%d%*s%d", nam, &study, &birth, &seme);
		if (study >= 2010 || birth >= 1991)
		{
			printf("%s eligible\n", nam);
		}
		else if (seme >= 41)
		{
			printf("%s ineligible\n", nam);
		}
		else
		{
			printf("%s coach petitions\n", nam);
		}
	}
	return 0;
}
