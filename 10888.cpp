#include <stdio.h>
#include <string.h>

int box[15][2], target[15][2], dis[15][15], queue[1600][2], step[1600], time[17], dp[65536], queue2[65536];
char map[40][41];

char valid(int x, int y, int n, int m)
{
	return x > -1 && x < n && y > -1 && y < m;
}

int main()
{
	int count, n, m, i, j, k, l, p, q, r, s, a, b, x, y, num, temp, temp2;
	time[0] = 1;
	for(i=1; i<17; i++)
	{
		time[i] = time[i-1] * 2;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		gets(map[0]);
		for(i=0, k=0, l=0; i<n; i++)
		{
			gets(map[i]);
			for(j=0; j<m; j++)
			{
				if(map[i][j] == 'B')
				{
					box[k][0] = i;
					box[k++][1] = j;
					map[i][j] = -1;
				}
				else if(map[i][j] == 'X')
				{
					target[l][0] = i;
					target[l][1] = j;
					map[i][j] += l++;
				}
				else if(map[i][j] == '.')
				{
					map[i][j] = -1;
				}
			}
		}
		memset(dis, 0, sizeof(dis));
		memset(dp, 0, sizeof(dp));
		for(i=0, num=k, p=100000, q=0, r=0; i<num; i++)
		{
			queue[0][0] = x = box[i][0];
			queue[0][1] = y = box[i][1];
			map[x][y] = i;
			for(j=0, k=0, l=1; k<l; k++)
			{
				x = queue[k][0];
				y = queue[k][1];
				s = step[k] + 1;
				if(valid(x+1, y, n, m))
				{
					if(map[x+1][y] > 80)
					{
						if(!dis[i][temp=map[x+1][y]-'X'])
						{
							dis[i][temp] = s;
							if(p == 100000)
							{
								queue2[r++] = time[temp];
								dp[time[temp]] = s;
							}
							else
							{
								for(a=p, b=q; a<b; a++)
								{
									if((queue2[a] | time[temp]) != queue2[a])
									{
										temp2 = time[temp] + queue2[a];
										if(dp[temp2] > dp[queue2[a]] + s)
										{
											dp[temp2] = dp[queue2[a]] + s;
										}
										else if(!dp[temp2])
										{
											dp[temp2] = dp[queue2[a]] + s;
											queue2[r++] = temp2;
										}
									}
								}
							}
						}
						map[x+1][y] -= 30;
						queue[l][0] = x + 1;
						queue[l][1] = y;
						step[l++] = s;
					}
					else if(map[x+1][y] < i)
					{
						queue[l][0] = x + 1;
						queue[l][1] = y;
						step[l++] = s;
						map[x+1][y] = i;
					}
				}
				if(valid(x-1, y, n, m))
				{
					if(map[x-1][y] > 80)
					{
						if(!dis[i][temp=map[x-1][y]-'X'])
						{
							dis[i][temp] = s;
							if(p == 100000)
							{
								queue2[r++] = time[temp];
								dp[time[temp]] = s;
							}
							else
							{
								for(a=p, b=q; a<b; a++)
								{
									if((queue2[a] | time[temp]) != queue2[a])
									{
										temp2 = time[temp] + queue2[a];
										if(dp[temp2] > dp[queue2[a]] + s)
										{
											dp[temp2] = dp[queue2[a]] + s;
										}
										else if(!dp[temp2])
										{
											dp[temp2] = dp[queue2[a]] + s;
											queue2[r++] = temp2;
										}
									}
								}
							}
						}
                        map[x-1][y] -= 30;
						queue[l][0] = x - 1;
						queue[l][1] = y;
						step[l++] = s;
					}
					else if(map[x-1][y] < i)
					{
						queue[l][0] = x - 1;
						queue[l][1] = y;
						step[l++] = s;
						map[x-1][y] = i;
					}
				}
				if(valid(x, y+1, n, m))
				{
					if(map[x][y+1] > 80)
					{
						if(!dis[i][temp=map[x][y+1]-'X'])
						{
							dis[i][temp] = s;
							if(p == 100000)
							{
								queue2[r++] = time[temp];
								dp[time[temp]] = s;
							}
							else
							{
								for(a=p, b=q; a<b; a++)
								{
									if((queue2[a] | time[temp]) != queue2[a])
									{
										temp2 = time[temp] + queue2[a];
										if(dp[temp2] > dp[queue2[a]] + s)
										{
											dp[temp2] = dp[queue2[a]] + s;
										}
										else if(!dp[temp2])
										{
											dp[temp2] = dp[queue2[a]] + s;
											queue2[r++] = temp2;
										}
									}
								}
							}
						}
                        map[x][y+1] -= 30;
						queue[l][0] = x;
						queue[l][1] = y + 1;
						step[l++] = s;
					}
					else if(map[x][y+1] < i)
					{
						queue[l][0] = x;
						queue[l][1] = y + 1;
						step[l++] = s;
						map[x][y+1] = i;
					}
				}
				if(valid(x, y-1, n, m))
				{
					if(map[x][y-1] > 80)
					{
						if(!dis[i][temp=map[x][y-1]-'X'])
						{
							dis[i][temp] = s;
							if(p == 100000)
							{
								queue2[r++] = time[temp];
								dp[time[temp]] = s;
							}
							else
							{
								for(a=p, b=q; a<b; a++)
								{
									if((queue2[a] | time[temp]) != queue2[a])
									{
										temp2 = time[temp] + queue2[a];
										if(dp[temp2] > dp[queue2[a]] + s)
										{
											dp[temp2] = dp[queue2[a]] + s;
										}
										else if(!dp[temp2])
										{
											dp[temp2] = dp[queue2[a]] + s;
											queue2[r++] = temp2;
										}
									}
								}
							}
						}
                        map[x][y-1] -= 30;
						queue[l][0] = x;
						queue[l][1] = y - 1;
						step[l++] = s;
					}
					else if(map[x][y-1] < i)
					{
						queue[l][0] = x;
						queue[l][1] = y - 1;
						step[l++] = s;
						map[x][y-1] = i;
					}
				}
			}
			for(j=0; j<num; j++)
			{
				if(map[target[j][0]][target[j][1]] < 80)
				{
					map[target[j][0]][target[j][1]] += 30;
				}
			}
			p = q;
			q = r;
		}
		printf("%d\n", dp[time[num]-1]);
	}
	return 0;
}
