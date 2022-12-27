#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	bool is_ans;
	scanf("%d", &n);
	is_ans = false;
	for (i=0; i<=n&&!is_ans; i+=4)
	{
		for (j=0; i+j<=n&&!is_ans; j+=7)
		{
			if (i+j == n)
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