#include <stdio.h>

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int cas, count, n, i, j, k, l, maxi, maxj, maxk, maxl, mini, minj, mink, minl;
	cas = 0;
	scanf("%d", &count);
	for(cas=1, count++; cas<count; cas++)
	{
		scanf("%d", &n);
		maxi = maxj = maxk = maxl = -1000000000;
		mini = minj = mink = minl = 1000000000;
		while(n--)
		{
			scanf("%d%d%d", &i, &j, &k);
			l = i + j + k;
			maxi = max(maxi, l);
			mini = min(mini, l);
			l = -i + j + k;
			maxj = max(maxj, l);
			minj = min(minj, l);
			l = i - j + k;
			maxk = max(maxk, l);
			mink = min(mink, l);
			l = i + j - k;
			maxl = max(maxl, l);
			minl = min(minl, l);
		}
		l = maxi - mini;
		l = max(l, maxj-minj);
		l = max(l, maxk-mink);
		l = max(l, maxl-minl);
		printf("Case #%d: %d\n", cas, l);
	}
	return 0;
}
