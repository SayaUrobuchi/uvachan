/**
 * Return an array of arrays of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int ary[1200], lnk[1200];
int **pp;

int comp(const void *p, const void *q)
{
	int a = *(int*)p;
	int b = *(int*)q;
	if (pp[a][0] != pp[b][0])
	{
		return pp[a][0]-pp[b][0];
	}
	return pp[b][1]-pp[a][1];
}

int** reconstructQueue(int** people, int peopleRowSize, int peopleColSize, int* returnSize) {
    int n, m, i, j, k, l, c;
    int **res;
    n = peopleRowSize;
    m = peopleColSize;
    res = (int**)malloc(n*sizeof(int*));
    for (i=0; i<n; i++)
    {
    	ary[i] = i;
    	lnk[i] = i+1;
    	res[i] = (int*)malloc(m*sizeof(int));
	}
	*returnSize = n;
	lnk[n] = 0;
	pp = people;
	qsort(ary, n, sizeof(int), comp);
	for (i=0; i<n; i++)
	{
		j = ary[i];
		for (k=0, l=lnk[k], c=pp[j][1]; c>0; c--, k=l, l=lnk[k]);
		res[l-1][0] = people[j][0];
		res[l-1][1] = people[j][1];
		lnk[k] = lnk[l];
	}
    return res;
}
