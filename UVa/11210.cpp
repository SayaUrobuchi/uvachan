#include <stdio.h>
#include <string.h>

char tbl[34], ary[34], lis[34], e[34], p[2], buf2[20], ans;

void dfs(int now, int pre, int eye)
{
	int tmp;
	if(now == 34)
	{
		if(pre == 2)
		{
			if(!eye)
			{
				return;
			}
			tmp = p[0];
			if(tmp > 49)
			{
				tmp -= 50;
			}
			if(tmp % 9)
			{
				lis[tmp-1] = 1;
				printf("pp1 %d\n", tmp-1);
			}
			if((tmp+2) % 9)
			{
				lis[tmp+2] = 1;
				printf("pp2 %d\n", tmp+2);
			}
			return;
		}
		if(pre)
		{
			tmp = p[0];
			if(tmp < 50)
			{
				lis[tmp] = 1;
				printf("p %d\n", tmp);
			}
			return;
		}
		for(tmp=0; tmp<eye; tmp++)
		{
			if(e[tmp] != -1)
			{
				lis[e[tmp]] = 1;
				printf("%d\n", e[tmp]);
			}
		}
		return;
	}
	if(now < 27)
	{
		if(now % 9 < 7)
		{
			if(ary[now] == 4)
			{
				if(ary[now+1] && ary[now+2])
				{
					ary[now] = 0;
					ary[now+1]--;
					ary[now+2]--;
					dfs(now+1, pre, eye);
					ary[now] = 4;
					ary[now+1]++;
					ary[now+2]++;
				}
				return;
			}
			if(ary[now] == 3)
			{
				if(ary[now+1] && ary[now+2])
				{
					ary[now] = 0;
					ary[now+1]--;
					ary[now+2]--;
					e[eye] = -1;
					dfs(now+1, pre, eye+1);
					ary[now] = 3;
					ary[now+1]++;
					ary[now+2]++;
				}
				ary[now] = 0;
				dfs(now+1, pre, eye);
				ary[now] = 3;
				if(pre == 2)
				{
					return;
				}
				if(pre == 1 && (!(now % 9) || !ary[now-1]))
				{
					return;
				}
				ary[now] = 1;
				e[eye] = -1;
				p[pre] = now + 50;
				dfs(now+1, pre+1, eye+1);
				ary[now] = 3;
				return;
			}
			if(ary[now] == 2)
			{
				ary[now] = 0;
				e[eye] = now;
				dfs(now+1, pre, eye+1);
				ary[now] = 2;
				return;
			}
			if(ary[now] == 1)
			{
				if(ary[now+1] && ary[now+2])
				{
					ary[now] = 0;
					ary[now+1]--;
					ary[now+2]--;
					dfs(now+1, pre, eye);
					ary[now] = 1;
					ary[now+1]++;
					ary[now+2]++;
				}
				if(pre == 2)
				{
					return;
				}
				if(pre && (!(now % 9) || !ary[now-1]))
				{
					return;
				}
				p[pre] = now;
				dfs(now+1, pre+1, eye);
				return;
			}
			dfs(now+1, pre, eye);
			return;
		}
		else
		{
			if(ary[now] == 4)
			{
				return;
			}
			if(ary[now] == 3)
			{
				ary[now] = 0;
				dfs(now+1, pre, eye);
				ary[now] = 3;
				if(pre == 2)
				{
					return;
				}
				if(pre == 1 && (!(now % 9) || !ary[now-1]))
				{
					return;
				}
				ary[now] = 1;
				e[eye] = -1;
				p[pre] = now + 50;
				dfs(now+1, pre+1, eye+1);
				ary[now] = 3;
				return;
			}
			if(ary[now] == 2)
			{
				ary[now] = 0;
				e[eye] = now;
				dfs(now+1, pre, eye+1);
				ary[now] = 2;
				return;
			}
			if(ary[now] == 1)
			{
				if(pre == 2)
				{
					return;
				}
				if(pre && !ary[now-1])
				{
					return;
				}
				p[pre] = now;
				dfs(now+1, pre+1, eye);
				return;
			}
			dfs(now+1, pre, eye);
			return;
		}
	}
	else
	{
		if(ary[now] == 4)
		{
			return;
		}
		if(ary[now] == 3)
		{
			ary[now] = 0;
			dfs(now+1, pre, eye);
			ary[now] = 3;
			return;
		}
		if(ary[now] == 2)
		{
			ary[now] = 0;
			e[eye] = now;
			dfs(now+1, pre, eye+1);
			ary[now] = 2;
			return;
		}
		if(ary[now] == 1)
		{
			if(pre)
			{
				return;
			}
			p[pre] = now;
			dfs(now+1, 1, eye);
			return;
		}
		dfs(now+1, pre, eye);
		return;
	}
}

int mtoi(char* str)
{
	if(str[0] > 47 && str[0] < 58)
	{
		if(str[1] == 'T')
		{
			return str[0] - 49;
		}
		if(str[1] == 'S')
		{
			return str[0] - 40;
		}
		return str[0] - 31;
	}
	if(str[0] == 'D')
	{
		return 27;
	}
	if(str[0] == 'N')
	{
		return 28;
	}
	if(str[0] == 'X')
	{
		return 29;
	}
	if(str[0] == 'Z')
	{
		return 31;
	}
	if(str[0] == 'F')
	{
		return 32;
	}
	if(str[1] == 'E')
	{
		return 30;
	}
	return 33;
}

char* itom(int n)
{
	if(n < 27)
	{
		if(n < 9)
		{
			sprintf(buf2, "%dT", n+1);
			return buf2;
		}
		if(n < 18)
		{
			sprintf(buf2, "%dS", n%9+1);
			return buf2;
		}
		sprintf(buf2, "%dW", n%9+1);
		return buf2;
	}
	if(n == 27)
	{
		strcpy(buf2, "DONG");
		return buf2;
	}
	if(n == 28)
	{
		strcpy(buf2, "NAN");
		return buf2;
	}
	if(n == 29)
	{
		strcpy(buf2, "XI");
		return buf2;
	}
	if(n == 30)
	{
		strcpy(buf2, "BEI");
		return buf2;
	}
	if(n == 31)
	{
		strcpy(buf2, "ZHONG");
		return buf2;
	}
	if(n == 32)
	{
		strcpy(buf2, "FA");
		return buf2;
	}
	strcpy(buf2, "BAI");
	return buf2;
}

int main()
{
	int cas, i;
	char buf[10];
	cas = 0;
	while(scanf("%s", buf) == 1)
	{
		if(buf[0] == 48)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		memset(lis, 0, sizeof(lis));
		tbl[mtoi(buf)]++;
		for(i=0; i<12; i++)
		{
			scanf("%s", buf);
			tbl[mtoi(buf)]++;
		}
		memcpy(ary, tbl, sizeof(tbl));
		ans = 0;
		printf("Case %d:", ++cas);
		dfs(0, 0, 0);
		for(i=0; i<34; i++)
		{
			if(lis[i])
			{
				printf(" %s", itom(i));
				ans = 1;
			}
		}
		if(ans)
		{
			printf("\n");
		}
		else
		{
			printf(" Not ready\n");
		}
	}
	return 0;
}
