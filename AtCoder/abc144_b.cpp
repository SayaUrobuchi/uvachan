#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	bool is_ans;
	scanf("%d", &n);
	is_ans = false;
	for (i=1; i<=9&&!is_ans; i++)
	{
		for (j=1; j<=9&&!is_ans; j++)
		{
			if (i*j == n)
			{
				is_ans = true;
			}
		}
	}
	if (is_ans)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}