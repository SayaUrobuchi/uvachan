#include <stdio.h>
#include <string.h>

#define SK_MAX 35

int sk_learn_level[SK_MAX], sk_pre_n[SK_MAX], sk_level[SK_MAX];
char sk_name[SK_MAX][65], sk_pre_str[SK_MAX][SK_MAX][65];

int max(int p, int q)
{
	return p > q ? p : q;
}

int find(char *s)
{
	int i;
	for(i=0; i<SK_MAX; i++)
	{
		if(strcmp(sk_name[i], s) == 0)
		{
			return i;
		}
	}
	return -1;
}

void level_up(int *level, int targ, int *sk_point)
{
	if(*level < targ)
	{
		*sk_point += targ - *level;
		*level = targ;
	}
}

void learn_sk(int targ, int req_level, int *level, int *sk_point)
{
	int i, l_level;
	if(sk_level[targ] < req_level)
	{
		for(i=0; i<sk_pre_n[targ]; i++)
		{
			learn_sk(find(sk_pre_str[targ][i]), 1, level, sk_point);
		}
		l_level = max(sk_learn_level[targ] + req_level - 1, *level + req_level - *sk_point);
		level_up(level, l_level, sk_point);
		*sk_point -= req_level - sk_level[targ];
		sk_level[targ] = req_level;
	}
}

int main()
{
	int n, m, i, j, t, targ, level, sk_point, req_level;
	char req_sk[65];
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s%d%d", sk_name[i], &sk_learn_level[i], &sk_pre_n[i]);
			for(j=0, t=sk_pre_n[i]; j<t; j++)
			{
				scanf("%s", sk_pre_str[i][j]);
			}
		}
		memset(sk_level, 0, sizeof(sk_level));
		scanf("%d", &m);
		for(i=0, level=1, sk_point=0; i<m; i++)
		{
			scanf("%s%d", req_sk, &req_level);
			targ = find(req_sk);
			learn_sk(targ, req_level, &level, &sk_point);
		}
		if(level > 99)
		{
			printf("IMPOSSIBLE\n");
		}
		else
		{
			printf("%d\n", level);
		}
	}
	return 0;
}
