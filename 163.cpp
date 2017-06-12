#include <stdio.h>
#include <string.h>

int go, step, dir;
int wayx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int wayy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
char dirstr[8][5] = {"N", "NE", "E", "SE", "S", "SW", "W", "NW"};
char str[1000];
char b1[256], b2[256], b3[256], b4[256];
char s1[256], s2[256], s3[256];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int adjust(int now)
{
	if(now < 0)
	{
		return now + 8;
	}
	else if(now > 7)
	{
		return now - 8;
	}
	return now;
}

int boulevard(int x, int y, int d)
{
	if(x == y)
	{
		if(d == 3 || d == 7)
		{
			return 1;
		}
	}
	if(x + y == 100)
	{
		if(d == 1 || d == 5)
		{
			return 1;
		}
	}
	x -= 50;
	y -= 50;
	if(ab(x) + ab(y) == 50)
	{
		if(x < 0 && y < 0)
		{
			if(d == 1 || d == 5)
			{
				return 1;
			}
		}
		else if(x < 0 && y > 0)
		{
			if(d == 3 || d == 7)
			{
				return 1;
			}
		}
		else if(x > 0 && y < 0)
		{
			if(d == 3 || d == 7)
			{
				return 1;
			}
		}
		else if(x > 0 && y > 0)
		{
			if(d == 1 || d == 5)
			{
				return 1;
			}
		}
	}
	return 0;
}

int throughway(int x, int y, int d)
{
	if(x == 0 || x == 50 || x == 100)
	{
		if(d == 2 || d == 6)
		{
			return 1;
		}
	}
	if(y == 0 || y == 50 || y == 100)
	{
		if(d == 0 || d == 4)
		{
			return 1;
		}
	}
	if(x == y)
	{
		if(d == 3 || d == 7)
		{
			return 1;
		}
	}
	if(x + y == 100)
	{
		if(d == 1 || d == 5)
		{
			return 1;
		}
	}
	return 0;
}

int valid(int x, int y, int d)
{
	if(d % 2)
	{
		return boulevard(x, y, d);
	}
	else
	{
		return 1;
	}
}

int legalcmd()
{
	int c, i;
	c = sscanf(str, "%s%s%s%s", b1, b2, b3, b4);
	if(c == 2 || c == 3)
	{
		if(!strcmp(b1, "GO"))
		{
			go = 1;
			if(c == 2)
			{
				for(i=0, step=0; b2[i]; i++)
				{
					if(b2[i] < 48 || b2[i] > 57)
					{
						break;
					}
					step *= 10;
					step += b2[i] - 48;
				}
				if(!b2[i])
				{
					return 1;
				}
			}
			else
			{
				if(!strcmp(b2, "STRAIGHT"))
				{
					for(i=0, step=0; b3[i]; i++)
					{
						if(b3[i] < 48 || b3[i] > 57)
						{
							break;
						}
						step *= 10;
						step += b3[i] - 48;
					}
					if(!b3[i])
					{
						return 1;
					}
				}
			}
		}
		else if(!strcmp(b1, "TURN"))
		{
			go = 0;
			if(c == 2)
			{
				if(!strcmp(b2, "LEFT"))
				{
					dir = -2;
					return 1;
				}
				else if(!strcmp(b2, "RIGHT"))
				{
					dir = 2;
					return 1;
				}
			}
			else
			{
				if(!strcmp(b2, "SHARP"))
				{
					if(!strcmp(b3, "LEFT"))
					{
						dir = -3;
						return 1;
					}
					else if(!strcmp(b3, "RIGHT"))
					{
						dir = 3;
						return 1;
					}
				}
				else if(!strcmp(b2, "HALF"))
				{
					if(!strcmp(b3, "LEFT"))
					{
						dir = -1;
						return 1;
					}
					else if(!strcmp(b3, "RIGHT"))
					{
						dir = 1;
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
	int i, x, y, face, tx, ty, td, ttx, tty, d, temp, temp2, ignore;
	while(gets(str))
	{
		if(!strcmp(str, "END"))
		{
			break;
		}
		sscanf(str, "%s%s%s", s1, s2, s3);
		sscanf(s1, "%*c%d%c", &temp, &d);
		if(d == 'E')
		{
			y = 50 + temp;
		}
		else
		{
			y = 50 - temp;
		}
		sscanf(s2, "%*c%d%c", &temp, &d);
		if(d == 'N')
		{
			x = 50 + temp;
		}
		else
		{
			x = 50 - temp;
		}
		for(i=0; i<8; i++)
		{
			if(!strcmp(dirstr[i], s3))
			{
				break;
			}
		}
		face = i;
		while(gets(str))
		{
			if(!strcmp(str, "STOP"))
			{
				break;
			}
			if(legalcmd())
			{
				tx = x + wayx[face];
				ty = y + wayy[face];
				if(go)
				{
					x = tx + wayx[face] * step;
					y = ty + wayy[face] * step;
				}
				else
				{
					ignore = 0;
					if(!((tx == 0 || tx == 50 || tx == 100) && (ty == 0 || ty == 50 || ty == 100)))
					{
						td = adjust(face+dir);
						temp = throughway(tx, ty, face);
						temp2 = throughway(ttx=tx+wayx[td], tty=ty+wayy[td], td);
						if(temp ^ temp2)
						{
							if(temp)
							{
								if(boulevard(tx, ty, face))
								{
									if(dir != -3)
									{
										ignore = 1;
									}
								}
								else
								{
									if(dir != -2)
									{
										ignore = 1;
									}
								}
							}
							else
							{
								if(boulevard(ttx, tty, td))
								{
									if(dir != -3)
									{
										ignore = 1;
									}
								}
								else
								{
									if(dir != -2)
									{
										ignore = 1;
									}
								}
							}
						}
						else
						{
							if(!valid(ttx, tty, td))
							{
								ignore = 1;
							}
						}
					}
					if(!ignore)
					{
						x = tx;
						y = ty;
						face = td;
					}
				}
			}
		}
		if(throughway(x, y, face))
		{
			printf("Illegal stopping place\n");
		}
		else
		{
			printf("%s %s %s\n", getystr(y), getxstr(x), dirstr[face]);
		}
	}
	return 0;
}
