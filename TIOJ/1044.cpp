#include <stdio.h>
#include <1044_Guess.h>

int main()
{
	int left, right, center, comp;
	left = 1;
	right = Initialize();
	while(1)
	{
		center = left + right;
		center /= 2;
		comp = Guess(center);
		if(comp)
		{
			right = center - 1;
			if(left > right)
			{
				Report(center);
			}
		}
		else
		{
			left = center + 1;
			if(left > right)
			{
				Report(center + 1);
			}
		}
	}
	return 0;
}
