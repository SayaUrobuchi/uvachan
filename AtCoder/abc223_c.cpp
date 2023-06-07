#include <iostream>
using namespace std;

const int N = 100005;

int ary[N], bry[N];
double pre[N];

int main()
{
	int n, i, len;
	double last, tar, sum, ans;
	scanf("%d", &n);
	for (i=0, sum=0; i<n; i++)
	{
		scanf("%d%d", &ary[i], &bry[i]);
		sum += (double)ary[i] / bry[i];
		pre[i] = sum;
	}
	for (i=0, last=0, tar=sum/2, len=0; i<n; len+=ary[i], last=pre[i], i++)
	{
		if (last < tar && pre[i] >= tar)
		{
			ans = len + (tar - last) * bry[i];
			break;
		}
	}
	printf("%.10lf\n", ans);
	return 0;
}
