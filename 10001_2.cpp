#include <stdio.h>
#include <string.h>

int n, id;
int value[35];
char str[35], str2[35];

int dfs(int depth, int s)
{
	int i, left, right;
	if(depth == n-1)
	{
		s += str2[0];
		if(id & (1<<s))
		{
			if(str[depth])
			{
				return 1;
			}
		}
		else
		{
			if(!str[depth])
			{
				return 1;
			}
		}
		return 0;
	}
	if(!depth)
	{
		left = n-1;
	}
	else
	{
		left = depth-1;
	}
	right = depth + 1;
	if(!depth)
	{
		for(; s<8; s++)
		{
			if(id & (1<<s))
			{
				if(str[depth])
				{
					str2[left] = (s>>2);
					str2[depth] = ((s%4)>>1);
					str2[right] = (s%2);
					if(dfs(depth+1, (s%4)<<1))
					{
						return 1;
					}
				}
			}
			else
			{
				if(!str[depth])
				{
					str2[left] = (s>>2);
					str2[depth] = ((s%4)>>1);
					str2[right] = (s%2);
					if(dfs(depth+1, (s%4)<<1))
					{
						return 1;
					}
				}
			}
		}
	}
	else
	{
		if(id & (1<<s))
		{
			if(str[depth])
			{
				str2[left] = (s>>2);
				str2[depth] = ((s%4)>>1);
				if(depth == n-2)
				{
					if(s%2 == str2[right])
					{
						if(dfs(depth+1, (s%4)<<1))
						{
							return 1;
						}
					}
				}
				else
				{
					str2[right] = (s%2);
					if(dfs(depth+1, (s%4)<<1))
					{
						return 1;
					}
				}
			}
		}
		else
		{
			if(!str[depth])
			{
				str2[left] = (s>>2);
				str2[depth] = ((s%4)>>1);
				if(depth == n-2)
				{
					if(s%2 == str2[right])
					{
						if(dfs(depth+1, (s%4)<<1))
						{
							return 1;
						}
					}
				}
				else
				{
					str2[right] = (s%2);
					if(dfs(depth+1, (s%4)<<1))
					{
						return 1;
					}
				}
			}
		}
		s++;
		if(id & (1<<s))
		{
			if(str[depth])
			{
				str2[left] = (s>>2);
				str2[depth] = ((s%4)>>1);
				if(depth == n-2)
				{
					if(s%2 == str2[right])
					{
						if(dfs(depth+1, (s%4)<<1))
						{
							return 1;
						}
					}
				}
				else
				{
					str2[right] = (s%2);
					if(dfs(depth+1, (s%4)<<1))
					{
						return 1;
					}
				}
			}
		}
		else
		{
			if(!str[depth])
			{
				str2[left] = (s>>2);
				str2[depth] = ((s%4)>>1);
				if(depth == n-2)
				{
					if(s%2 == str2[right])
					{
						if(dfs(depth+1, (s%4)<<1))
						{
							return 1;
						}
					}
				}
				else
				{
					str2[right] = (s%2);
					if(dfs(depth+1, (s%4)<<1))
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d%d%s", &id, &n, str) == 3)
	{
		for(i=0; i<n; i++)
		{
			str[i] -= '0';
		}
		if(dfs(0, 0))
		{
			printf("REACHABLE\n");
		}
		else
		{
			printf("GARDEN OF EDEN\n");
		}
	}
	return 0;
}
