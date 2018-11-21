#ifndef EVAL

#endif
#include <iostream>

int calc(int n)
{
	return 1023/n + n-1;
}

int main()
{
	int div = 2;
	for (int i=3; i<1024; i++)
	{
		if (calc(i) < calc(div))
		{
			div = i;
		}
	}
	std::cout << div << ": " << calc(div) << std::endl;
	return 0;
}



