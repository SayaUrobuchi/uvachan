#include <stdio.h>
#include <string.h>

double ary[26] = {12.53, 1.42, 4.68, 5.86, 13.68, 0.69, 1.01, 0.70, 6.25, 0.44, 0.00, 4.97, 3.15,
				  6.71, 8.68, 2.51, 0.88, 6.87, 7.98, 4.63, 3.93, 0.90, 0.02, 0.22, 0.90, 0.52};
char str[8], tbl[26], odd[26] = {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1};
int n;
double sum;

void dfs(int now, double s)
{
	int i;
	if(str[now])
	{
		if(now % 2)
		{
			dfs(now+1, s+(double)(now+1)*ary['a'-97]);
			dfs(now+1, s+(double)(now+1)*ary['e'-97]);
			dfs(now+1, s+(double)(now+1)*ary['i'-97]);
			dfs(now+1, s+(double)(now+1)*ary['o'-97]);
			dfs(now+1, s+(double)(now+1)*ary['u'-97]);
		}
		else
		{
			for(i=0; i<26; i++)
			{
				if(odd[i] && tbl[i] < 2)
				{
					tbl[i]++;
					dfs(now+1, s+(double)(now+1)*ary[i]);
					tbl[i]--;
				}
			}
		}
	}
	else
	{
		sum += s;
		n++;
	}
}

double calc()
{
	int i;
	double res;
	for(i=1, res=0; str[i]; i++)
	{
		res += (i+1) * ary[str[i]-97];
	}
	return res;
}

int main()
{
	int count;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		n = 0;
		sum = 0;
		memset(tbl, 0, sizeof(tbl));
		tbl[str[0]-97]++;
		dfs(1, 0);
		if(sum / n > calc())
		{
			printf("below\n");
		}
		else
		{
			printf("above or equal\n");
		}
	}
	return 0;
}
