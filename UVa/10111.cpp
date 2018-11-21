#include <stdio.h>

char column[2][4], row[2][4], positive[2], negative[2], chess[2], map[4][5];

char play(char color)
{
	char i, j, check;
	if(column[1-color][j] == 4) return color ? i * 10 + j + 1 : 0;
	if(row[1-color][i] == 4) return color ? i * 10 + j + 1 : 0;
	if(i == j)
	{
		if(positive[1-color] == 4) return color ? i * 10 + j + 1 : 0;
	}
	else if(i + j == 3)
	{
		if(negative[1-color] == 4) return color ? i * 10 + j + 1 : 0;
	}
	for(i=0, check=0; i<4; i++)
	{
		for(j=0; j<4; j++)
		{
			if(map[i][j] == '.')
			{
				map[i][j] = chess[color];
				column[color][j]++;
    		row[color][i]++;
				if(i == j) positive[color]++;
				else if(i + j == 3) negative[color]++;
				check = play(1 - color);
				column[color][j]--;
				row[color][i]--;
				if(i == j) positive[color]--;
				else if(i + j == 3) negative[color]--;
				map[i][j] = '.';
				if(color ^ (check ? 1 : 0)) return color ? 0 : i * 10 + j + 1;
			}
		}
	}
	return color;
}

int main()
{
	char buf[2], i, j, check;
	chess[0] = 'x';
	chess[1] = 'o';
	while(gets(buf))
	{
		if(buf[0] == '$') break;
		for(i=0; i<4; i++)
		{
			column[0][i] = 0;
			column[1][i] = 0;
			row[0][i] = 0;
			row[1][i] = 0;
		}
		positive[0] = 0;
		positive[1] = 0;
		negative[0] = 0;
		negative[1] = 0;
		for(i=0; i<4; i++)
		{
			gets(map[i]);
			for(j=0; j<4; j++)
			{
				if(map[i][j] == 'x')
				{
					if(i == j) positive[0]++;
					else if(i + j == 3) negative[0]++;
					column[0][j]++;
					row[0][i]++;
				}
				else if(map[i][j] == 'o')
				{
          if(i == j) positive[1]++;
					else if(i + j == 3) negative[1]++;
					column[1][j]++;
					row[1][i]++;
				}
			}
		}
		check = play(0);
		if(check) printf("(%d,%d)\n", check / 10, check % 10 - 1);
		else printf("#####\n");
	}
	return 0;
}
