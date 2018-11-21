#ifndef EVAL

#endif
#include <iostream>
#include "guess.h"

int main()
{
	Init();
	for (int i=0; i<10; i++)
	{
		for (int j=0, jj=(1<<i); j<jj; j++)
		{
			for (int k=0, kk=(1<<(9-i)); k<kk; k++)
			{
				Addnum(i+1, j+(k<<(i+1)));
			}
		}
	}
	bool *jret=SubmitSet();
	int ans = 0;
	for (int i=0; i<10; i++)
	{
		if (!jret[i+1])
		{
			ans += (1<<i);
		}
	}
	SubmitAns(ans);
	return 0;
}



