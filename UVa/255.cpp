#include <stdio.h>
#include <string.h>

int map[64];

int main()
{
	int i, k, q, target;
	while(scanf("%d%d%d", &k, &q, &target) == 3)
	{
		if(k == q)
		{
			printf("Illegal state\n");
		}
		else
		{
			if(target == k || target == q)
			{
				printf("Illegal move\n");
			}
			else
			{
				memset(map, 0, sizeof(map));
				if(k % 8 > 0)
				{
					map[k-1]++;
				}
				if(k % 8 < 7)
				{
					map[k+1]++;
				}
				if(k + 8 < 64)
				{
					map[k+8]++;
				}
				if(k - 8 >= 0)
				{
					map[k-8]++;
				}
				if(q % 8 > 0)
				{
					for(i=q-1; i%8>0; i--)
					{
						if(i == k)
						{
							break;
						}
						map[i] += 2;
					}
					if(i != k)
					{
						map[i] += 2;
					}
				}
				if(q % 8 < 7)
				{
					for(i=q+1; i%8<7; i++)
					{
						if(i == k)
						{
							break;
						}
						map[i] += 2;
					}
					if(i != k)
					{
						map[i] += 2;
					}
				}
				if(q >= 8)
				{
					for(i=q-8; i>=8; i-=8)
					{
						if(i == k)
						{
							break;
						}
						map[i] += 2;
					}
					if(i != k)
					{
						map[i] += 2;
					}
				}
				if(q < 56)
				{
					for(i=q+8; i<56; i+=8)
					{
						if(i == k)
						{
							break;
						}
						map[i] += 2;
					}
					if(i != k)
					{
						map[i] += 2;
					}
				}
				if((map[target] & 2) == 0)
				{
					printf("Illegal move\n");
				}
				else if((map[target] & 1) == 0)
				{
					q = target;
					if((k == 56 && q == 49) || (k == 63 && q == 54) || (k == 0 && q == 9) || (k == 7 && q == 14))
					{
						printf("Stop\n");
					}
					else
					{
						printf("Continue\n");
					}
				}
				else if(map[target] == 3)
				{
					printf("Move not allowed\n");
				}
			}
		}
	}
	return 0;
}
