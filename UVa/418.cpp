#include <stdio.h>
#include <string.h>

int area;
int list[4];
int used[4];
char str[4][15];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

void chk()
{
	int i, j, k, l, p, q, r, s;
	char *s1, *s2, *s3, *s4;
	s1 = str[list[0]];
	s2 = str[list[1]];
	s3 = str[list[2]];
	s4 = str[list[3]];
	for(i=1; i<9; i++)
	{
		for(j=1; j<9; j++)
		{
			if(s1[i] == s2[j])
			{
				for(k=i+2; k<11; k++)
				{
					for(l=1; l<9; l++)
					{
						if(s1[k] == s3[l])
						{
							for(p=1, q=k-i+1; q<11; p++, q++)
							{
								for(r=j+2, s=l+2; r<11&&s<11; r++, s++)
								{
									if(s4[p] == s2[r] && s4[q] == s3[s])
									{
										area = max(area, (q-p-1)*(r-j-1));
									}
								}
							}
						}
					}
				}
			}
		}
	}
}

void dfs(int depth)
{
	int i;
	if(depth == 4)
	{
		chk();
		return;
	}
	for(i=0; i<4; i++)
	{
		if(!used[i])
		{
			list[depth] = i;
			used[i] = 1;
			dfs(depth+1);
			used[i] = 0;
		}
	}
}

int main()
{
	while(scanf("%s", str[0]) == 1)
	{
		if(!strcmp(str[0], "Q"))
		{
			break;
		}
		scanf("%s%s%s", str[1], str[2], str[3]);
		area = 0;
		memset(used, 0, sizeof(used));
		dfs(0);
		printf("%d\n", area);
	}
	return 0;
}
