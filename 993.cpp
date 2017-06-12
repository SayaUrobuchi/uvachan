#include <stdio.h>

int main()
{
	int n, num[32], i, j, in;
	scanf("%d", &n);
	while(n--)
	{
		scanf("%d", &in);
		if(in<10)
		{
			printf("%d\n", in);
			continue;
		}
		else
		{
			for(i=9, j=0; i>1;)
			{
				if(in % i) i--;
				else
				{
					num[j++] = i;
					in /= i;
				}
			}
		}
		if(in == 1)
		{
			for(j--; j>-1; j--) printf("%d", num[j]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
