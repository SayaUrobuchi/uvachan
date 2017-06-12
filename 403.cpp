#include <stdio.h>
#include <string.h>

#define SHIFT 10

char letter[5][300] = {".***..****...****.****..*****.*****..****.*...*.*****...***.*...*.*.....*...*.*...*..***..****...***..****...****.*****.*...*.*...*.*...*.*...*.*...*.*****.......", 
					   "*...*.*...*.*...*.*...*.*.....*.....*.....*...*...*......*..*..*..*.....**.**.**..*.*...*.*...*.*...*.*...*.*.....*.*.*.*...*.*...*.*...*..*.*...*.*.....*........",
					   "*****.****..*.....*...*.***...***...*..**.*****...*......*..***...*.....*.*.*.*.*.*.*...*.****..*...*.****...***....*...*...*..*.*..*.*.*...*.....*.....*.........",
					   "*...*.*...*.*.....*...*.*.....*.....*...*.*...*...*...*..*..*..*..*.....*...*.*..**.*...*.*.....*..**.*..*......*...*...*...*..*.*..**.**..*.*....*....*..........",
					   "*...*.****...****.****..*****.*......***..*...*.*****..**...*...*.*****.*...*.*...*..***..*......****.*...*.****...***...***....*...*...*.*...*...*...*****......."};
char page[100][100];
char buf[1005];

int main()
{
	int i, p, q, r, fsize, pr, pc;
	char *str;
	while(scanf("%s", buf) == 1)
	{
		memset(page, '.', sizeof(page));
		do
		{
			if(!strcmp(buf, ".EOP"))
			{
				break;
			}
			else if(!strcmp(buf, ".P"))
			{
				scanf("%s%d%d", buf, &pr, &pc);
				sscanf(buf+1, "%d", &fsize);
				gets(buf);
				strtok(buf, "|");
				str = strtok(NULL, "|");
				pc += SHIFT;
			}
			else if(!strcmp(buf, ".L"))
			{
				scanf("%s%d", buf, &pr);
				sscanf(buf+1, "%d", &fsize);
				gets(buf);
				strtok(buf, "|");
				str = strtok(NULL, "|");
				pc = 1 + SHIFT;
			}
			else if(!strcmp(buf, ".R"))
			{
				scanf("%s%d", buf, &pr);
				sscanf(buf+1, "%d", &fsize);
				gets(buf);
				strtok(buf, "|");
				str = strtok(NULL, "|");
				pc = 61+SHIFT;
				if(fsize == 1)
				{
					pc -= strlen(str);
				}
				else
				{
					pc -= strlen(str) * 6;
				}
			}
			else
			{
				scanf("%s%d", buf, &pr);
				sscanf(buf+1, "%d", &fsize);
				gets(buf);
				strtok(buf, "|");
				str = strtok(NULL, "|");
				pc = 31 + SHIFT;
				if(fsize == 1)
				{
					pc -= (strlen(str) >> 1);
				}
				else
				{
					pc -= ((strlen(str) * 6) >> 1);
				}
			}
			pc--;
			pr--;
			/*printf("%d %d %d\n", fsize, pr, pc);*/
			if(fsize == 1)
			{
				for(; *str&&pc<SHIFT; pc++, str++);
				for(; *str&&pc<60+SHIFT; pc++, str++)
				{
					if(*str != ' ')
					{
						page[pr][pc] = *str;
					}
				}
			}
			else
			{
				for(; *str&&pc+6<SHIFT; pc+=6, str++);
				for(; *str&&pc<60+SHIFT; pc+=6, str++)
				{
					if(*str != ' ')
					{
						for(p=(*str-65)*6, r=0; r<5&&pr+r<60; r++)
						{
							for(q=0; q<5&&pc+q<60+SHIFT; q++)
							{
								if(letter[r][p+q] == '*')
								{
									page[pr+r][pc+q] = letter[r][p+q];
								}
							}
						}
					}
				}
			}
		}while(scanf("%s", buf) == 1);
		for(i=0; i<60; i++)
		{
			printf("%.60s\n", page[i]+SHIFT);
		}
		printf("\n------------------------------------------------------------\n\n");
	}
	return 0;
}
