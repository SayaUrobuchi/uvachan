#ifndef EVAL

#endif
#include <iostream>
#include "guess.h"

int calc(int n)
{
	return 1023/n + n-1;
}

int main()
{
	Init();
	int div = 2;
	int idx = 0;
	for (int i=3; i<1024; i++)
	{
		if (calc(i) < calc(div))
		{
			div = i;
		}
	}
	int tim = 1023/div;
	for (int i=0; i<tim; i++)
	{
		for (int j=0; j<div; j++)
		{
			Addnum(idx, i*div+j);
		}
		++idx;
	}
	for (int i=0; i<div-1; i++)
	{
		for (int j=i; j<1024; j+=div)
		{
			Addnum(idx, j);
		}
		++idx;
	}
	bool *jret=SubmitSet();
	int ans = 0;
	for (int i=0; i<tim+1; i++)
	{
		if (jret[i] || i==tim)
		{
			for (int j=tim; j<tim+div; j++)
			{
				if (jret[j] || j==tim+div-1)
				{
					ans = i*div+(j-tim);
					break;
				}
			}
			break;
		}
	}
	SubmitAns(ans);
	return 0;
}



