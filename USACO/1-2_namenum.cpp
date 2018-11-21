/*
ID: sa072682
LANG: C
TASK: namenum
*/

#include <stdio.h>
#include <string.h>

char dic[5001][13], chk[5001];

int main()
{
	int n, i, j;
	char buf[100], ch, ans;
	freopen("dict.txt", "r", stdin);
	n = 0;
	while(gets(dic[n]))
	{
		n++;
	}
	memset(chk, 1, sizeof(chk));
	freopen("namenum.in", "r", stdin);
	freopen("namenum.out", "w", stdout);
	gets(buf);
	for(i=0; buf[i]; i++)
	{
		ch = buf[i] - 50;
		for(j=0; j<n; j++)
		{
			if(chk[j] && (dic[j][i] - 65 - (dic[j][i] > 'Q')) / 3 != ch)
			{
				chk[j] = 0;
			}
		}
	}
	for(i=0, ans=0; i<n; i++)
	{
		if(chk[i] && strlen(dic[i]) == strlen(buf))
		{
			printf("%s\n", dic[i]);
			ans = 1;
		}
	}
	if(!ans)
	{
		printf("NONE\n");
	}
	return 0;
}
