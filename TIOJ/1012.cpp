#include <stdio.h>

int tbl[1001], index[1001], stack[1001], ary[1001];

int main()
{
	int n, m, i, j, k, l, l2, temp, chk;
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			tbl[ary[i]] = i;
			index[i] = i + 1;
		}
		for(i=0, l=0, l2=0; i<n; i++)
		{
			if(l && tbl[stack[l-1]] == ary[i])
			{
				l--;
			}
			else
			{
				for(chk=0; l2<n; l2++)
				{
					if(index[l2] == ary[i])
					{
						l2++;
						break;
					}
					stack[l++] = index[l2];
					for(j=l-1, k=0; j&&k<=m; k++, j--)
					{
						if(tbl[stack[j]] > tbl[stack[j-1]])
						{
							temp = tbl[stack[j]];
							tbl[stack[j]] = tbl[stack[j-1]];
							tbl[stack[j-1]] = temp;
						}
						else
						{
							break;
						}
					}
					if(j && tbl[stack[j]] > tbl[stack[j-1]])
					{
						chk = 1;
						break;
					}
				}
				if(chk)
				{
					break;
				}
			}
		}
		if(i < n)
		{
			printf("no\n");
		}
		else
		{
			printf("yes\n");
		}
	}
	return 0;
}
