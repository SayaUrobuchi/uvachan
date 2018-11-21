#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int arr[10005][28], used[1005], dp[1005], val[10005], word[1005], from[1005], n, l, f;
int ptt[10005], bbb[1005][28];
char targ[1005], buf[10005][105];

int mx(int p, int q)
{
	return p>q ? p : q;
}

int rule(int *p, int *q)
{
	int i;
	for(i=0; i<28; i++)
	{
		if(p[i] != q[i])
		{
			return p[i] - q[i];
		}
	}
	return 0;
}

int comp(const void *p, const void *q)
{
	return rule(arr[*(int*)p], arr[*(int*)q]);
}

int bis(int *ary, int left, int right)
{
	int center, res;
	if(left > right)
	{
		return -1;
	}
	center = ((left+right) >> 1);
	if((res=rule(arr[ptt[center]], ary)) == 0)
	{
		return ptt[center];
	}
	else if(res > 0)
	{
		return bis(ary, left, center-1);
	}
	return bis(ary, center+1, right);
}

int recur(int loc)
{
	int i, t, *bb;
	if(loc == -1)
	{
		return 1;
	}
	if(used[loc])
	{
		return dp[loc];
	}
	used[loc] = 1;
	dp[loc] = 0;
	bb = bbb[loc];
	memset(bb, 0, sizeof(bbb[loc]));
	bb[27] = targ[loc]-97;
	for(i=loc; i>=0&&i>=loc-l+1; i--)
	{
		bb[targ[i]-97]++;
		bb[26] = targ[i]-97;
		t = bis(bb, 0, n-1);
		if(t != -1)
		{
			if(dp[loc] && recur(i-1))
			{
				return dp[loc]=2;
			}
			if(recur(i-1))
			{
				dp[loc] += recur(i-1) * val[t];
				word[loc] = t;
				from[loc] = i-1;
				if(dp[loc] > 1)
				{
					return dp[loc]=2;
				}
			}
		}
	}
	return dp[loc];
}

void back(int loc)
{
	if(loc == -1)
	{
		return;
	}
	back(from[loc]);
	if(f)
	{
		printf(" ");
	}
	f = 1;
	printf("%s", buf[word[loc]]);
}

int main()
{
	int count, i, tmp, ll;
	char *p;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s", targ);
		scanf("%d", &n);
		for(i=0, l=0; i<n; i++)
		{
			scanf("%s", buf[i]);
			memset(arr[i], 0, sizeof(int)*28);
			for(p=buf[i]; *p; p++)
			{
				arr[i][*p-97]++;
			}
			arr[i][26] = buf[i][0]-97;
			arr[i][27] = *(p-1)-97;
			l = mx(l, p-buf[i]);
			ptt[i] = i;
		}
		qsort(ptt, n, sizeof(int), comp);
		for(i=0; i<n; i++)
		{
			val[ptt[i]] = 1;
			if(i > 0 && rule(arr[ptt[i]], arr[ptt[i-1]]) == 0)
			{
				val[ptt[i]]++;
			}
			else if(i < n-1 && rule(arr[ptt[i]], arr[ptt[i+1]]) == 0)
			{
				val[ptt[i]]++;
			}
		}
		memset(used, 0, sizeof(used));
		tmp = recur(ll=strlen(targ)-1);
		if(tmp == 0)
		{
			printf("impossible\n");
		}
		else if(tmp == 1)
		{
			f = 0;
			back(ll);
			printf("\n");
		}
		else
		{
			printf("ambiguous\n");
		}
	}
	return 0;
}
