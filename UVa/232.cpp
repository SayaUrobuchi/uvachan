#include <stdio.h>
#include <string.h>

int main()
{
	int r, c, cas, i, j, k, count, tmp, dnum;
	char check, down[100][15], puzzle[10][12], buf[11], buf2[11], *ptr, *ptr2;
	check = 0;
	cas = 0;
	while(scanf("%d", &r)==1)
	{
		if(!r) break;
		scanf("%d", &c);
		for(i=0; i<r; i++) scanf("%s", puzzle[i]);
		if(check) printf("\n");
		check = 1;
		printf("puzzle #%d:\nAcross\n", ++cas);
		for(i=0, count=1, dnum=0; i<r; i++)
		{
			strcpy(buf2, puzzle[i]);
			ptr = strtok(buf2, "*");
			for(j=0; j<c; j++)
			{
				if(puzzle[i][j] == '*') continue;
				tmp = 0;
				if(!j || puzzle[i][j-1] == '*')
				{
					printf("%3d.%s\n", count, ptr);
					ptr = strtok(NULL, "*");
					tmp = 1;
				}
				if(!i || puzzle[i-1][j] == '*')
				{
					ptr2 = buf;
					for(k=i; puzzle[k][j] != '*' && k<r; k++)
					{
						*ptr2 = puzzle[k][j];
						ptr2++;
					}
					*ptr2 = 0;
					sprintf(down[dnum++], "%3d.%s", count, buf);
					tmp = 1;
				}
				count += tmp;
			}
		}
		printf("Down\n");
		for(i=0; i<dnum; i++) printf("%s\n", down[i]);
	}
	return 0;
}
