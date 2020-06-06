#include <stdio.h>
#include <string.h>

const char *nam[] = {"A#", "Bb", "C#", "Db", "D#", "Eb", "F#", "Gb", "G#", "Ab"};
char s0[64], s1[64];

int main()
{
	int cas, i;
	cas = 0;
	while (scanf("%s%s", s0, s1) == 2)
	{
		printf("Case %d: ", ++cas);
		for (i=0; i<10; i++)
		{
			if (strcmp(s0, nam[i]) == 0)
			{
				printf("%s %s\n", nam[i^1], s1);
				break;
			}
		}
		if (i >= 10)
		{
			puts("UNIQUE");
		}
	}
	return 0;
}
