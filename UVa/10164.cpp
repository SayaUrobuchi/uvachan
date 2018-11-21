#include <stdio.h>

int ary[10][2047], ans[1024], n, num;

void recursion(int depth, int two, int lim)
{
	int index[2047], source[1023], i, j, k, l;
	if(lim == 1)
	{
		ans[0] = 0;
		return;
	}
	for(i=0, j=lim-1, k=0; k<lim; k++)
	{
		if(ary[depth][k] % 2)
		{
			index[i++] = k;
		}
		else
		{
			index[j--] = k;
		}
	}
	l = depth + 1;
	for(i=1, j++, k=0; i<j; i+=2, k++)
	{
		ary[l][k] = (ary[depth][index[i]] + ary[depth][index[i-1]]) / 2;
		source[k] = i;
	}
	for(i=j+1; i<lim; i+=2, k++)
	{
		ary[l][k] = (ary[depth][index[i]] + ary[depth][index[i-1]]) / 2;
		source[k] = i;
	}
	recursion(depth+1, two*2, lim/2);
	for(i=0, j=two*2, k=(lim+1)/4, l=two; k>0; i+=j, k--)
	{
		ans[i+l] = index[source[ans[i]]];
		ans[i] = index[source[ans[i]] - 1];
	}
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		num = n * 2 - 1;
		for(i=0; i<num; i++)
		{
			scanf("%d", &ary[0][i]);
		}
		recursion(0, 1, num);
		printf("Yes\n%d", ary[0][ans[0]]);
		for(i=1; i<n; i++)
		{
			printf(" %d", ary[0][ans[i]]);
		}
		printf("\n");
	}
	return 0;
}
