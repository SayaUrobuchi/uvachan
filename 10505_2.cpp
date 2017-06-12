#include <stdio.h>

short fri[200], ene[200], frinum[200], temp;

short getfri(short now)
{
	temp = fri[now];
	if(temp == -1)
	{
		return now;
	}
	return fri[now] = getfri(temp);
}

int main()
{
	int in;
	short count, n, m, i, ans, itemp, intemp, eitemp, eintemp;
	scanf("%d", &in);
	count = in;
	while(count--)
	{
		scanf("%d", &in);
		n = in;
		for(i=0; i<n; ++i)
		{
			fri[i] = -1;
			ene[i] = -1;
		}
		for(i=0; i<n; ++i)
		{
			frinum[i] = 0;
			scanf("%d", &in);
			m = in;
			while(m--)
			{
				scanf("%d", &in);
				if(--in < n)
				{
					itemp = getfri(i);
					intemp = getfri(in);
					eitemp = ene[itemp];
					eintemp = ene[intemp];
					if(eitemp == -1)
					{
						if(eintemp == -1)
						{
							ene[itemp] = intemp;
							ene[intemp] = itemp;
						}
						else
						{
							fri[itemp] = getfri(eintemp);
						}
					}
					else if(getfri(eitemp) != intemp)
					{
						if(eintemp == -1)
						{
							fri[intemp] = getfri(eitemp);
						}
						else
						{
							if(eitemp == eintemp)
							{
								if(itemp != getfri(eitemp))
								{
									fri[itemp] = getfri(eitemp);
								}
								if(intemp != getfri(eintemp))
								{
									fri[intemp] = getfri(eintemp);
								}
							}
							else
							{
								fri[getfri(eitemp)] = intemp;
								fri[getfri(eintemp)] = itemp;
								ene[itemp] = intemp;
								ene[intemp] = itemp;
							}
						}
					}
				}
			}
		}
		for(i=0; i<n; ++i)
		{
			++frinum[getfri(i)];
		}
		for(i=0, ans=0; i<n; ++i)
		{
			eitemp = frinum[i];
			if(eitemp)
			{
				intemp = ene[i];
				itemp = getfri(intemp);
				if(intemp == -1)
				{
					ans += eitemp;
				}
				else if(i != itemp)
				{
					eintemp = frinum[itemp];
					if(eitemp > eintemp)
					{
						ans += eitemp;
					}
					else
					{
						ans += eintemp;
					}
					frinum[itemp] = 0;
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}
