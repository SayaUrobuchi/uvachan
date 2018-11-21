int cnt;
int used[1205][1205], q[2048576], qk[2048576];
int *ary;

int bisearch(int p, int q, int t)
{
	int r;
	while (p <= q)
	{
		r = ((p+q) >> 1);
		if (ary[r] == t)
		{
			return r;
		}
		if (ary[r] > t)
		{
			q = r-1;
		}
		else
		{
			p = r+1;
		}
	}
	return -1;
}

bool canCross(int* stones, int stonesSize) {
	int i, j, k, pos, step, next, idx;
	ary = stones;
    cnt++;
    used[0][0] = cnt;
    q[0] = 0;
    qk[0] = 0;
    for (i=0, j=1; i<j; i++)
    {
    	pos = stones[q[i]];
    	for (k=-1; k<=1; k++)
    	{
    		step = qk[i] + k;
    		if (step <= 0)
    		{
    			continue;
    		}
			next = pos + step;
			if (next >= 0 && next <= stones[stonesSize-1])
			{
				idx = bisearch(q[i]+1, stonesSize-1, next);
				if (idx >= 0 && used[idx][step] != cnt)
				{
					if (idx == stonesSize-1)
					{
						return true;
					}
					used[idx][step] = cnt;
					q[j] = idx;
					qk[j] = step;
					j++;
				}
			}
    	}
    }
    return false;
}
