#include <stdio.h>
#include <string.h>

int arr[105];

int main()
{
	int n, i, f, t;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(arr, 0, sizeof(arr));
		for(i=0; i<n; i++)
		{
			scanf("%d", &t);
			arr[t]++;
		}
		for(i=1, f=0; i<105; i++)
		{
			if(arr[i])
			{
				while(arr[i]--)
				{
					if(f)
					{
						printf(" ");
					}
					f = 1;
					printf("%d", i);
				}
			}
		}
		printf("\n");
	}
	return 0;
}
