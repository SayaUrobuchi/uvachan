#ifndef EVAL

#endif
#include <iostream>
#include "guess.h"

int main()
{
	Init();
	for (int i=0; i<10; i++)
	{
		for (int j=0; j<1024; j++)
		{
			(j & (1<<i)) ? Addnum(i+1, j) : 0;
		}
	}
	bool *jret=SubmitSet();
	int ans = 0;
	for (int i=0; i<10; i++)
	{
		if (jret[i+1])
		{
			ans += (1<<i);
		}
	}
	SubmitAns(ans);
	return 0;
}



