#include <stdio.h>

char map[3][4];

int main()
{
	int count, i, j, o, x, o2, x2;
	char buf[2];
	scanf("%d", &count);
	while(count--)
	{
		gets(buf);
		x = 0;
		o = 0;
		for(i=0; i<3; i++)
		{
			gets(map[i]);
			for(j=0; j<3; j++)
			{
				if(map[i][j] == 'X')
				{
					x++;
				}
				else if(map[i][j] == 'O')
				{
					o++;
				}
			}
		}
		if(o > x || x - o > 1)
		{
			printf("no\n");
		}
		else
		{
			o2 = 0;
			x2 = 0;
			for(i=0; i<3; i++)
			{
				if(map[i][0] == map[i][1] && map[i][1] == map[i][2])
				{
					if(map[i][0] == 'X')
					{
						if(x == o)
						{
							printf("no\n");
							break;
						}
						else
						{
							x2++;
							if(o2)
							{
								printf("no\n");
								break;
							}
						}
					}
					else if(map[i][0] == 'O')
					{
						if(x != o)
						{
							printf("no\n");
							break;
						}
						else
						{
							o2++;
							if(x2)
							{
								printf("no\n");
	       						break;
							}
						}
					}
				}
				if(map[0][i] == map[1][i] && map[1][i] == map[2][i])
				{
					if(map[0][i] == 'X')
					{
						if(x == o)
						{
							printf("no\n");
							break;
						}
						else
						{
							x2++;
							if(o2)
							{
								printf("no\n");
								break;
							}
						}
					}
					else if(map[0][i] == 'O')
					{
						if(x != o)
						{
							printf("no\n");
							break;
						}
						else
						{
							o2++;
							if(x2)
							{
								printf("no\n");
	       						break;
							}
						}
					}
				}
			}
			if(i == 3)
			{
				if(map[0][0] == map[1][1] && map[1][1] == map[2][2])
				{
					if(map[0][0] == 'X')
					{
						if(x == o)
						{
							printf("no\n");
							continue;
						}
						else
						{
							x2++;
							if(o2)
							{
								printf("no\n");
								continue;
							}
						}
					}
					else if(map[0][0] == 'O')
					{
						if(x != o)
						{
							printf("no\n");
							continue;
						}
						else
						{
							o2++;
							if(x2)
							{
								printf("no\n");
								continue;
							}
						}
					}
				}
				if(map[2][0] == map[1][1] && map[1][1] == map[0][2])
				{
					if(map[0][2] == 'X')
					{
						if(x == o)
						{
							printf("no\n");
							continue;
						}
						else
						{
							x2++;
							if(o2)
							{
								printf("no\n");
								continue;
							}
						}
					}
					else if(map[0][2] == 'O')
					{
						if(x != o)
						{
							printf("no\n");
							continue;
						}
						else
						{
							o2++;
							if(x2)
							{
								printf("no\n");
								continue;
							}
						}
					}
				}
				printf("yes\n");
			}
		}
	}
	return 0;
}
