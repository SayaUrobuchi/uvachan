#include <stdio.h>

unsigned int id, s;

int idfs(int last, unsigned int n, int d)
{
	if(d == id)
	{
		return n == s;
	}
	/*if(s < n || (s >> id-d) > n)
	 * 	{
	 * 			return 0;
	 * 				}*/
	if(n)
	{
		if(idfs(0, n<<1, d+1))
		{
			return 1;
		}
	}
	if(last != 2)
	{
		if(idfs(1, n+1, d+1))
		{
			return 1;
		}
	}
	if(last != 1)
	{
		if(idfs(2, n-1, d+1))
		{
			return 1;	
		}	
	}
	return 0;
}

int main()
{
	while(scanf("%u", &s) == 1)
	{
		for(id=0; ; id++)
		{
			if(idfs(0, 0u, 0))
			{
				break;
			}
		}
		printf("%d\n", id);
	}
	return 0;
}

