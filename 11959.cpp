#include <stdio.h>
#include <string.h>

int tbl[6][6] = {
	{0, 1, 2, 3, 4, 5}, 
	{1, 0, 5, 4, 3, 2}, 
	{2, 4, 1, 3, 0, 5}, 
	{3, 5, 2, 1, 4, 0}, 
	{4, 2, 0, 3, 1, 5}, 
	{5, 3, 2, 0, 4, 1}
};
char s[16], s0[16], s1[16];

int main()
{
	int count, i, j, k;
	s[6] = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%s", s0, s1);
		for (i=0; i<6; i++)
		{
			s[0] = s1[tbl[i][0]];
			s[1] = s1[tbl[i][1]];
			for (j=0; j<4; j++)
			{
				for (k=0; k<4; k++)
				{
					s[2+k] = s1[tbl[i][2+((k+j)&3)]];
				}
				if (!strcmp(s0, s))
				{
					break;
				}
			}
			if (j < 4)
			{
				break;
			}
		}
		puts(i<6 ? "Equal" : "Not Equal");
	}
	return 0;
}
