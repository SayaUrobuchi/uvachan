#include <stdio.h>
#include <string.h>

int al[1005], al2[1005], bl[1005], bl2[1005], *t, *ap, *at, *bp, *bt;

int main()
{
	int n, i, a, b, am, bm, na, nb, temp;
	while(scanf("%d%d%d", &n, &na, &nb) == 3)
	{
		memset(al, 0, sizeof(al));
		memset(bl, 0, sizeof(bl));
		for(i=0, am=0; i<na; i++)
		{
			scanf("%d", &temp);
			al[temp]++;
			if(temp > am)
			{
				am = temp;
			}
		}
		for(i=0, bm=0; i<nb; i++)
		{
			scanf("%d", &temp);
			bl[temp]++;
			if(temp > bm)
			{
				bm = temp;
			}
		}
		ap = al;
		at = al2;
		bp = bl;
		bt = bl2;
		while(am && bm)
		{
			for(i=0, a=am, b=bm; i<n; i++)
			{
				if(!ap[a])
				{
					while(a&&!ap[a])
					{
						a--;
					}
				}
				if(!bp[b])
				{
					while(b&&!bp[b])
					{
						b--;
					}
				}
				if(!a || !b)
				{
					break;
				}
				ap[a]--;
				bp[b]--;
				if(a > b)
				{
					at[a-b]++;
				}
				else if(b > a)
				{
					bt[b-a]++;
				}
			}
			for(; a; a--)
			{
				at[a] += ap[a];
				ap[a] = 0;
			}
			for(; b; b--)
			{
				bt[b] += bp[b];
				bp[b] = 0;
			}
			t = ap;
			ap = at;
			at = t;
			t = bp;
			bp = bt;
			bt = t;
			for(; am&&!ap[am]; am--);
			for(; bm&&!bp[bm]; bm--);
		}
		if(am == bm)
		{
			printf("even\n");
		}
		else
		{
			if(am)
			{
				printf("tomurainokane wins\n");
			}
			else
			{
				printf("fureimuheizu wins\n");
				ap = bp;
				am = bm;
			}
			for(i=am; i; i--)
			{
				while(ap[i])
				{
					printf("%d\n", i);
					ap[i]--;
				}
			}
		}
	}
	return 0;
}
