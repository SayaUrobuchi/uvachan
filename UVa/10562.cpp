#include <stdio.h>
#include <string.h>

char pic[201][201];
int n, slen[200];

void recursion(int left, int right, int depth)
{
	int i, j, k, l;
	for(i=depth, j=left; j<right; j++)
	{
		if(pic[i][j] != 32 && pic[i][j] != '|' && pic[i][j] != '-')
		{
			printf("%c(", pic[i][j]);
			if(i+1 < n && j < slen[i+1] && pic[i+1][j] == '|')
			{
				for(i+=2, k=j-1; k>-1 && pic[i][k]=='-'; k--);
				for(l=j+1; pic[i][l]=='-'; l++);
				if(l > slen[i+1]) l = slen[i+1];
				recursion(k+1, l, depth + 3);
				i-=2;
			}
			printf(")");
		}
	}
}

int main()
{
	int count;
	scanf("%d", &count);
	gets(pic[0]);
	while(count--)
	{
		n = 0;
		while(gets(pic[n]))
		{
			if(pic[n][0] == '#') break;
			slen[n] = strlen(pic[n]);
			n++;
		}
		printf("(");
		if(n)
		{
			recursion(0, slen[0], 0);
		}
		printf(")\n");
	}
	return 0;
}