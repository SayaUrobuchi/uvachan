#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m;
int ary[3000][30];
int setnum[3000];
int list[30];
int index[3000];
int used[30];
int fnum[30];
int fmap[30][30];
int num[30];
int map[30][30];
char buf[2008];
char str[30][30];
char *ptr[30];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int scomp(const void *p, const void *q)
{
	int i;
	if(setnum[*(int*)p] == setnum[*(int*)q])
	{
		for(i=0; i<setnum[*(int*)p]; i++)
		{
			if(ary[*(int*)p][i] != ary[*(int*)q][i])
			{
				return ary[*(int*)p][i] - ary[*(int*)q][i];
			}
		}
		return 0;
	}
	return setnum[*(int*)q] - setnum[*(int*)p];
}

void dfs(int now, int depth)
{
	int i, j, temp;
	if(now > n)
	{
		memcpy(ary[m], list, sizeof(int)*depth);
		qsort(ary[m], depth, sizeof(int), comp);
		index[m] = m;
		setnum[m++] = depth;
		return;
	}
	if(used[now])
	{
		dfs(now+1, depth);
	}
	else
	{
		used[now]++;
		for(i=0; i<fnum[now]; i++)
		{
			used[fmap[now][i]]++;
		}
		list[depth] = now;
		dfs(now+1, depth+1);
		used[now]--;
		for(i=0; i<fnum[now]; i++)
		{
			used[fmap[now][i]]--;
		}
		for(i=0; i<num[now]; i++)
		{
			temp = map[now][i];
			if(!used[temp])
			{
				used[temp]++;
				for(j=0; j<fnum[temp]; j++)
				{
					used[fmap[temp][j]]++;
				}
				list[depth] = temp;
				dfs(now+1, depth+1);
				used[temp]--;
				for(j=0; j<fnum[temp]; j++)
				{
					used[fmap[temp][j]]--;
				}
			}
		}
	}
}

int main()
{
	int i, j, s, now, last;
	while(scanf("%d", &n) == 1)
	{
		memset(num, 0, sizeof(num));
		memset(fnum, 0, sizeof(fnum));
		for(i=1; i<=n; i++)
		{
			scanf("%s", buf);
			for(j=0; j<n; j++)
			{
				if(buf[j] == '*')
				{
					map[i][num[i]++] = j+1;
					fmap[i][fnum[i]++] = j+1;
					fmap[j+1][fnum[j+1]++] = i;
				}
			}
		}
		m = 0;
		memset(used, 0, sizeof(used));
		dfs(1, 0);
		qsort(index, m, sizeof(int), scomp);
		for(i=1; i<=n; i++)
		{
			ptr[i] = str[i];
		}
		for(i=0, s=0; i<m; i++)
		{
			now = index[i];
			if(i)
			{
				last = index[i-1];
				if(setnum[now] != setnum[last] || memcmp(ary[now], ary[last], sizeof(int)*setnum[now]))
				{
					for(j=0; j<setnum[now]; j++)
					{
						/*printf("%d ", ary[now][j]);*/
						*(ptr[ary[now][j]]++) = s + 'a';
					}
					/*printf("\n");*/
					s++;
				}
			}
			else
			{
				for(j=0; j<setnum[now]; j++)
				{
					/*printf("%d ", ary[now][j]);*/
					*(ptr[ary[now][j]]++) = s + 'a';
				}
				/*printf("\n");*/
				s++;
			}
		}
		for(i=1; i<=n; i++)
		{
			*(ptr[i]) = 0;
			puts(str[i]);
		}
		puts("-----");
	}
	return 0;
}
