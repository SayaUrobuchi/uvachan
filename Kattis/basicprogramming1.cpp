#include <iostream>
#include <algorithm>
using namespace std;
using VOIDFUNC_T = void (*)();

const int N = 200005;

int n;
int ary[N];
bool used[N];

void f1()
{
	puts("7");
}

void f2()
{
	if (ary[0] > ary[1])
	{
		puts("Bigger");
	}
	else if (ary[0] == ary[1])
	{
		puts("Equal");
	}
	else
	{
		puts("Smaller");
	}
}

void f3()
{
	nth_element(ary, ary+1, ary+3);
	printf("%d\n", ary[1]);
}

void f4()
{
	int i;
	long long sum = 0;
	for (i=0; i<n; i++)
	{
		sum += ary[i];
	}
	printf("%lld\n", sum);
}

void f5()
{
	int i;
	long long sum = 0;
	for (i=0; i<n; i++)
	{
		if (!(ary[i] & 1))
		{
			sum += ary[i];
		}
	}
	printf("%lld\n", sum);
}

void f6()
{
	int i;
	for (i=0; i<n; i++)
	{
		putchar('a' + ary[i]%26);
	}
	puts("");
}

void f7()
{
	int i;
	bool is_fail = false;
	bool is_done = false;
	for (i=0; ; i=ary[i])
	{
		if (i < 0 || i >= n)
		{
			is_fail = true;
			break;
		}
		else if (i == n-1)
		{
			is_done = true;
			break;
		}
		if (used[i])
		{
			break;
		}
		used[i] = true;
	}
	if (is_fail)
	{
		puts("Out");
	}
	else if (is_done)
	{
		puts("Done");
	}
	else
	{
		puts("Cyclic");
	}
}

void (* const FUNC[])() = {nullptr, f1, f2, f3, f4, f5, f6, f7};
//const VOIDFUNC_T FUNC[] = {nullptr, f1, f2, f3, f4, f5, f6, f7};

int main()
{
	int m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	FUNC[m]();
	return 0;
}
