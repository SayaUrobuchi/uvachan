#include <iostream>
#include <algorithm>

int ary[16];

int main()
{
	int i, j, k, a, b;
	bool found;
	while (scanf("%d", &ary[0]) == 1)
	{
		for (i=1; i<6; i++)
		{
			scanf("%d", &ary[i]);
		}
		scanf("%d%*d", &a);
		std::sort(ary, ary+6, std::greater<int>());
		for (i=0, found=false; i<6; i++)
		{
			for (j=i+1; j<6; j++)
			{
				b = a - ary[i] - ary[j];
				if (b > 0)
				{
					for (k=j+1; k<6&&ary[k]>b; k++);
					//printf("!? %d => %d\n", ary[i]+ary[j], k);
					if (k < 6 && ary[k] == b)
					{
						found = true;
						break;
					}
				}
			}
			if (found)
			{
				break;
			}
		}
		printf("%d %d %d", ary[i], ary[j], ary[k]);
		for (a=0; a<6; a++)
		{
			if (a != i && a != j && a != k)
			{
				printf(" %d", ary[a]);
			}
		}
		puts("");
	}
	return 0;
}
