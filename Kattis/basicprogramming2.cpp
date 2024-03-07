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
	int i;
	bool is_ans = false;
	for (i=0; i<n&&!is_ans; i++)
	{
		if (ary[i] <= 7777)
		{
			if (used[7777-ary[i]])
			{
				is_ans = true;
			}
			used[ary[i]] = true;
		}
	}
	puts(is_ans ? "Yes" : "No");
}

void f2()
{
	int i;
	sort(ary, ary+n);
	bool is_ans = false;
	for (i=1; i<n&&!is_ans; i++)
	{
		if (ary[i] == ary[i-1])
		{
			is_ans = true;
		}
	}
	puts(is_ans ? "Contains duplicate" : "Unique");
}

void f3()
{
	int i, j;
	sort(ary, ary+n);
	int ans = -1;
	for (i=0; i<n; i=j)
	{
		for (j=i+1; j<n&&ary[i]==ary[j]; j++);
		if (((j-i)<<1) > n)
		{
			ans = ary[i];
		}
	}
	printf("%d\n", ans);
}

void f4()
{
	int i, j;
	i = ((n-1) >> 1);
	nth_element(ary, ary+i, ary+n);
	printf("%d", ary[i]);
	if (!(n & 1))
	{
		j = i + 1;
		nth_element(ary, ary+j, ary+n);
		printf(" %d", ary[j]);
	}
	puts("");
}

void f5()
{
	sort(ary, ary+n);
	bool is_first = false;
	for (int *ptr=lower_bound(ary, ary+n, 100); ptr<ary+n&&*ptr<=999; ++ptr)
	{
		if (is_first)
		{
			putchar(' ');
		}
		is_first = true;
		printf("%d", *ptr);
	}
	puts("");
}

const VOIDFUNC_T FUNC[] = {nullptr, f1, f2, f3, f4, f5};

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
