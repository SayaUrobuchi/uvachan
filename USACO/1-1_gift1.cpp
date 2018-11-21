/*
ID: sa072682
LANG: C
TASK: gift1
*/

#include <stdio.h>
#include <string.h>

int main()
{
	int n, get[10], i, j, in, give, own;
	char name[10][15], buf[15];
	freopen("gift1.in", "r", stdin);
	freopen("gift1.out", "w", stdout);
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		scanf("%s", name[i]);
		get[i] = 0;
	}
	for(i=0; i<n; i++)
	{
		scanf("%s%d%d", buf, &own, &give);
		for(in=0; in<n; in++)
		{
			if(!strcmp(name[in], buf)) break;
		}
		if(!give) continue;
		get[in] -= own - own % give;
		own /= give;
		while(give--)
		{
			scanf("%s", buf);
			for(j=0; j<n; j++)
			{
				if(!strcmp(buf, name[j])) break;
			}
			get[j] += own;
		}
	}
	for(i=0; i<n; i++) printf("%s %d\n", name[i], get[i]);
	return 0;
}
