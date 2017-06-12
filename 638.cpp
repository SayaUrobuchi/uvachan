#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int x[26], y[26], iden[26];
int index[26], index2[100000];
char final[100000][5];
char str[10000];

int comp(const void *p, const void *q)
{
	if(x[*(int*)p] == x[*(int*)q])
	{
		return y[*(int*)p] - y[*(int*)q];
	}
	return x[*(int*)p] - x[*(int*)q];
}

int comp2(const void *p, const void *q)
{
	return strcmp(final[*(int*)p], final[*(int*)q]);
}

int main()
{
	int cas, n, i, j, k, p, q, id1, id2, id3, id4;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s%d%d", str, &x[i], &y[i]);
			iden[i] = str[0];
			index[i] = i;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=0, k=0; i<n; i++)
		{
			id1 = index[i];
			for(j=i+1; j<n; j++)
			{
				id2 = index[j];
				if(x[id1] != x[id2])
				{
					break;
				}
				for(p=j+1; p<n; p++)
				{
					id3 = index[p];
					if(y[id3] == y[id1])
					{
						for(q=p+1; q<n; q++)
						{
							id4 = index[q];
							if(x[id3] != x[id4])
							{
								break;
							}
							if(y[id4] == y[id2])
							{
								final[k][0] = iden[id2];
								final[k][1] = iden[id4];
								final[k][2] = iden[id3];
								final[k][3] = iden[id1];
								final[k][4] = 0;
								index2[k] = k;
								k++;
								break;
							}
						}
					}
				}
			}
		}
		if(!k)
		{
			printf("Point set %d: No rectangles\n", ++cas);
		}
		else
		{
			qsort(index2, k, sizeof(int), comp2);
			printf("Point set %d:\n", ++cas);
			for(i=0; i<k; i+=10)
			{
				for(j=i, p=0; j<k&&p<10; j++, p++)
				{
					printf(" %s", final[index2[j]]);
				}
				printf("\n");
			}
		}
	}
	return 0;
}
