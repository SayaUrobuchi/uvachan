#include <stdio.h>

char s[256];
const char *ans[] = {"ABC", "BABC", "CCAABB"};
const char *nam[] = {"Adrian", "Bruno", "Goran"};
int an[] = {3, 4, 6};
int score[8];

int main()
{
	int n, i, j, mx;
	while (scanf("%d%s", &n, s) == 2)
	{
		for (i=0, mx=-1; i<3; i++)
		{
			for (j=0, score[i]=0; s[j]; j++)
			{
				if (s[j] == ans[i][j%an[i]])
				{
					score[i]++;
				}
			}
			if (score[i] > mx)
			{
				mx = score[i];
			}
		}
		printf("%d\n", mx);
		for (i=0; i<3; i++)
		{
			if (score[i] == mx)
			{
				puts(nam[i]);
			}
		}
	}
	return 0;
}
