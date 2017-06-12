#include <stdio.h>
#include <string.h>

int dp[9], rateo[9], ratex[9];
char map[9], chk[19683][2];
double rate[19683][2];

int calc()
{
	int i, result;
	for(i=0, result=0; i<9; i++)
	{
		result += map[i] * dp[i];
	}
	return result;
}

char chkwin(char type)
{
	int i;
	for(i=0; i<3; i++)
	{
		if(map[i] == map[i+3] && map[i] == map[i+6] && map[i] == type)
		{
			return 1;
		}
		if(map[i*3] == map[i*3+1] && map[i*3] == map[i*3+2] && map[i*3] == type)
		{
			return 1;
		}
	}
	if(map[0] == map[4] && map[4] == map[8] && map[8] == type)
	{
		return 1;
	}
	if(map[2] == map[4] && map[4] == map[6] && map[6] == type)
	{
		return 1;
	}
	return 0;
}

double drawx(int, char);

double drawo(int location, char type)
{
	int i, tmp;
	double ans, temp, temp2;
	map[location] = type;
	tmp = calc();
	if(chk[tmp][0])
	{
		map[location] = 0;
		return rate[tmp][0];
	}
	chk[tmp][0] = 1;
	if(chkwin(type))
	{
        map[location] = 0;
		return rate[tmp][0] = type == 1 ? 100.0 : 0.0;
	}
	for(i=0, ans=0; i<9; i++)
	{
		if(!map[i])
		{
			if(rateo[i])
			{
                temp = (100.0 - drawx(i, 1)) * rateo[i] / 100.0;
			}
			else
			{
				temp = 0;
			}
            if(rateo[i] == 100)
            {
				temp2 = 0;
			}
			else
			{
				temp2 = (100.0 - drawx(i, 2)) * (100.0 - rateo[i]) / 100.0;
			}
			if(temp + temp2 > ans)
			{
				ans = temp + temp2;
			}
		}
	}
	map[location] = 0;
	return rate[tmp][0] = ans;
}

double drawx(int location, char type)
{
	int i, chkans, tmp;
	double ans, temp, temp2;
	map[location] = type;
	tmp = calc();
	if(chk[tmp][1])
	{
		map[location] = 0;
		return rate[tmp][1];
	}
	chk[tmp][1] = 1;
	if(chkwin(type))
	{
        map[location] = 0;
		return rate[tmp][1] = type == 2 ? 100.0 : 0.0;
	}
	for(i=0, ans=0, chkans=1; i<9; i++)
	{
		if(!map[i])
		{
			chkans = 0;
			if(ratex[i] == 100)
			{
				temp = 0;
			}
			else
			{
            	temp = (100.0 - drawo(i, 1)) * (100.0 - ratex[i]) / 100.0;
			}
			if(ratex[i])
			{
				temp2 = (100.0 - drawo(i, 2)) * ratex[i] / 100.0;
			}
			else
			{
				temp2 = 0;
			}
			if(temp + temp2 > ans)
			{
				ans = temp + temp2;
			}
		}
	}
	map[location] = 0;
	if(chkans)
	{
		ans = 100.0;
	}
	return rate[tmp][1] = ans;
}

int main()
{
	int cas, count, i, j;
	double ans, temp, temp2;
	cas = 0;
	map[9] = 0;
	dp[0] = 1;
	for(i=1; i<9; i++)
	{
		dp[i] = dp[i-1] * 3;
	}
	scanf("%d", &count);
	while(count--)
	{
		for(i=0; i<9; i++)
		{
			scanf("%d", &rateo[i]);
		}
		for(i=0; i<9; i++)
		{
			scanf("%d", &ratex[i]);
		}
		memset(map, 0, sizeof(map));
		memset(chk, 0, sizeof(chk));
		for(i=0, ans=0; i<9; i++)
		{
			if(rateo[i])
			{
				temp = (100.0 - drawx(i, 1)) * rateo[i] / 100.0;
			}
			else
			{
				temp = 0;
			}
			if(rateo[i] == 100)
			{
				temp2 = 0;
			}
			else
			{
				temp2 = (100.0 - drawx(i, 2)) * (100.0 - rateo[i]) / 100.0;
			}
			if(temp + temp2 > ans)
			{
				ans = temp + temp2;
			}
		}
		printf("Case #%d: %.2f\n", ++cas, ans);
	}
	return 0;
}
