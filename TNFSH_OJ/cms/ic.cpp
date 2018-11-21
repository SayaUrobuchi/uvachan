#ifndef EVAL

#endif
#include <iostream>
#include "guess.h"

int main()
{
	Init();
	for (int i=2; i<1024; i++)
	{
		Addnum(i, i);
	}
	bool *jret=SubmitSet();
	int ans = 0;
	for (int i=2; i<1024; i++)
	{
		if (jret[i])
		{
			ans = i;
			break;
		}
	}
	SubmitAns(ans);
	return 0;
}



