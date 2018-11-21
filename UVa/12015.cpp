#include <stdio.h>
#include <stdlib.h>

int v[15];
char s[15][150];

int main()
{
	int count, i, cas, mx;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0, mx=-2147483647; i<10; i++)
		{
			scanf("%s%d", s[i], &v[i]);
			if(v[i] > mx)
			{
				mx = v[i];
			}
		}
		printf("Case #%d:\n", ++cas);
		for(i=0; i<10; i++)
		{
			if(v[i] == mx)
			{
				printf("%s\n", s[i]);
			}
		}
	}
	return 0;
}
