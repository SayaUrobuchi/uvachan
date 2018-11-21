#include <stdio.h>

int main()
{
	int i;
	double ans, temp;
	for(i=0, ans=0.0; i<12; i++)
	{
		scanf("%lf", &temp);
		ans += temp;
	}
	printf("$%.2lf\n", ans/12);
	scanf(" ");
	return 0;
}
