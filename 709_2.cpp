#include <stdio.h>
#include <string.h>

#define N 50000

int n, m;
int dp[N];
int length[N];
int used[N];
int from[N];
char ary[N][81];
char buf[200008];
char sstr[100];

int count(int space, int step)
{
	int s, unbalance;
	s = space / step;
	unbalance = space % step;
	return (s-1)*(s-1)*(step-unbalance) + s*s*unbalance;
}

int recursion(int now)
{
	int i, sum, step, temp;
	if(used[now])
	{
		return dp[now];
	}
	used[now] = 1;
	if(now >= m)
	{
		return dp[now]=0;
	}
	dp[now] = 1147483647;
	for(i=now, sum=length[now], step=0; i<m&&sum+step<=n; i++, sum+=length[i], step++)
	{
		if(!step)
		{
			if(sum == n)
			{
				temp = 0;
			}
			else
			{
				temp = 500;
			}
			if(recursion(i+1) + temp <= dp[now])
			{
				dp[now] = recursion(i+1) + temp;
				/*printf("%d\n", dp[now]);*/
				from[now] = i + 1;
			}
		}
		else
		{
			temp = count(n-sum, step);
			/*printf("%d %d => %d\n", n-sum, step, temp);*/
			/*printf("%d + %d = %d comp %d\n", recursion(i-1), temp, recursion(i-1)+temp, dp[now]);*/
			if(recursion(i+1) + temp <= dp[now])
			{
				dp[now] = recursion(i+1) + temp;
				from[now] = i + 1;
			}
		}
	}
	return dp[now];
}

void backtracking(int now)
{
	int temp, i, l, step, space, unbalance;
	temp = from[now] - 1;
	for(i=now, l=0, step=temp-now; i<=temp; i++)
	{
		l += length[i];
	}
	/*printf("%d %d: %d, %d\n", n-l, step, space, unbalance);*/
	printf("%s", ary[now]);
	if(step)
	{
		space = (n-l) / step;
		unbalance = (n-l) % step;
		/*printf("%d %d %d %d\n", n-l, step, temp, now);*/
		for(i=now+1; i<=temp; i++)
		{
			printf("%.*s%s", space+(i>temp-unbalance), sstr, ary[i]);
		}
	}
	printf("\n");
	if(temp < m-1)
	{
		backtracking(temp+1);
	}
}

int main()
{
	char *ptr;
	memset(sstr, ' ', sizeof(sstr)-1);
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		m = 0;
		gets(buf);
		while(gets(buf))
		{
			if(!buf[0])
			{
				break;
			}
			ptr = strtok(buf, " ");
			do
			{
				length[m] = strlen(ptr);
				strcpy(ary[m++], ptr);
			}while(ptr=strtok(NULL, " "));
		}
		memset(used, 0, sizeof(used));
		recursion(0);
		backtracking(0);
		/*printf("ANS %d\n", recursion(0));*/
		printf("\n");
	}
	return 0;
}
