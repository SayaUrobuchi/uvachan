#include <stdio.h>
#include <string.h>

char ary[10], ans[100], limd;

int dis(int p, int q)
{
	int i, j;
	i = p % 3 - q % 3;
	j = p / 3 - q / 3;
	if(i < 0)
	{
		i = -i;
	}
	if(j < 0)
	{
		j = -j;
	}
	return i + j;
}

char idfs(int loc, int depth, char last, int stat)
{
	int tmp, temp, plus;
	if(!stat)
	{
		ans[depth+1] = 0;
		ans[depth] = last;
		return 1;
	}
	if(limd - depth < stat)
	{
		return 0;
	}
	if(last != 'd' && loc > 2)
	{
		tmp = loc - 3;
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
		if((ary[loc]-1)/3 > tmp/3)
		{
			plus = -1;
		}
		else
		{
			plus = 1;
		}
		if(idfs(tmp, depth+1, 'u', stat+plus))
		{
			ans[depth] = last;
			return 1;
		}
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
	}
	if(last != 'u' && loc < 6)
	{
		tmp = loc + 3;
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
		if((ary[loc]-1)/3 < tmp/3)
		{
			plus = -1;
		}
		else
		{
			plus = 1;
		}
		if(idfs(tmp, depth+1, 'd', stat+plus))
		{
			ans[depth] = last;
			return 1;
		}
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
	}
	if(last != 'r' && loc % 3)
	{
		tmp = loc - 1;
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
		if((ary[loc]-1)%3 > tmp%3)
		{
			plus = -1;
		}
		else
		{
			plus = 1;
		}
		if(idfs(tmp, depth+1, 'l', stat+plus))
		{
			ans[depth] = last;
			return 1;
		}
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
	}
	if(last != 'l' && (loc % 3) != 2)
	{
		tmp = loc + 1;
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
		if((ary[loc]-1)%3 < tmp%3)
		{
			plus = -1;
		}
		else
		{
			plus = 1;
		}
		if(idfs(tmp, depth+1, 'r', stat+plus))
		{
			ans[depth] = last;
			return 1;
		}
		temp = ary[loc];
		ary[loc] = ary[tmp];
		ary[tmp] = temp;
	}
	return 0;
}

int main()
{
	int count, i, j, s, sum, stat;
	char buf[2];
	ary[9] = 0;
	scanf("%d", &count);
	while(count--)
	{
		for(i=0, sum=0, stat=0; i<9; i++)
		{
			scanf("%s", buf);
			if(buf[0] == 'x')
			{
				ary[i] = 9;
				s = i;
			}
			else
			{
				ary[i] = buf[0] - 48;
				for(j=0; j<i; j++)
				{
					if(ary[j] < ary[i])
					{
						sum++;
					}
				}
				stat += dis(ary[i]-1, i);
			}
		}
		if(sum % 2)
		{
			printf("unsolvable\n");
		}
		else
		{
			for(limd=stat; ; limd+=2)
			{
				if(idfs(s, 0, 0, stat))
				{
					printf("%s\n", ans+1);
					break;
				}
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}
