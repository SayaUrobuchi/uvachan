#include <stdio.h>

int main()
{
	int count, m, s, nm, ns;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d:%d", &m, &s);
		if(m == 12)
		{
			m = 0;
		}
		ns = 0;
		if(s)
		{
			ns = 60-s;
			m++;
		}
		nm = 12-m;
		if(nm == 0)
		{
			nm = 12;
		}
		printf("%02d:%02d\n", nm, ns);
	}
	return 0;
}
