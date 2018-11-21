#include <stdio.h>

int fri[200], ene[200], frinum[200];

int getfri(int now)
{
	if(fri[now] == -1)
	{
		return now;
	}
	return fri[now] = getfri(fri[now]);
}

int main()
{
	int count, n, m, i, j, in, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			fri[i] = -1;
			ene[i] = -1;
			frinum[i] = 0;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &m);
			for(j=0; j<m; j++)
			{
				scanf("%d", &in);
				if(in > n)
				{
					continue;
				}
				in--;
				if(ene[getfri(i)] == -1)
				{
					if(ene[getfri(in)] == -1)
					{
						ene[getfri(i)] = getfri(in);
						ene[getfri(in)] = getfri(i);
					}
					else
					{
						fri[getfri(i)] = getfri(ene[getfri(in)]);
					}
				}
				else if(getfri(ene[getfri(i)]) != getfri(in))
				{
					if(ene[getfri(in)] == -1)
					{
						fri[getfri(in)] = getfri(ene[getfri(i)]);
					}
					else
					{
						if(ene[getfri(i)] == ene[getfri(in)])
						{
							if(getfri(i) != getfri(ene[getfri(i)]))
							{
								fri[getfri(i)] = getfri(ene[getfri(i)]);
							}
							if(getfri(in) != getfri(ene[getfri(in)]))
							{
								fri[getfri(in)] = getfri(ene[getfri(in)]);
							}
						}
						else
						{
							fri[getfri(ene[getfri(i)])] = getfri(in);
							fri[getfri(ene[getfri(in)])] = getfri(i);
							ene[getfri(i)] = getfri(in);
							ene[getfri(in)] = getfri(i);
						}
					}
				}
			}
		}
		for(i=0; i<n; i++)
		{
			frinum[getfri(i)]++;
		}
		for(i=0, ans=0; i<n; i++)
		{
			if(frinum[i])
			{
				if(ene[getfri(i)] == -1)
				{
					ans += frinum[i];
				}
				else if(getfri(i) != getfri(ene[getfri(i)]))
				{
					if(frinum[i] > frinum[getfri(ene[getfri(i)])])
					{
						ans += frinum[i];
					}
					else
					{
						ans += frinum[getfri(ene[getfri(i)])];
					}
					frinum[getfri(ene[getfri(i)])] = 0;
					frinum[i] = 0;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
