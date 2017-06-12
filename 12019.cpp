#include <stdio.h>

int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
const char *week[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};

int main()
{
	int count, i, m, d, td, st;
	st = 5;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &d);
		td = 0;
		for(i=1; i<m; i++)
		{
			td += month[i];
		}
		td += d-1;
		printf("%s\n", week[(td+st)%7]);
	}
	return 0;
}
