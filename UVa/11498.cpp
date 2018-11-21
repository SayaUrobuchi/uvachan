#include <stdio.h>

int main()
{
	int n, i, x, y, ox, oy;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		scanf("%d%d", &ox, &oy);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			if(x == ox || y == oy)
			{
				printf("divisa\n");
			}
			else if(x < ox && y < oy)
			{
				printf("SO\n");
			}
			else if(x < ox && y > oy)
			{
				printf("NO\n");
			}
			else if(x > ox && y < oy)
			{
				printf("SE\n");
			}
			else
			{
				printf("NE\n");
			}
		}
	}
	return 0;
}
