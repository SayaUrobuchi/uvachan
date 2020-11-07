#include <iostream>

int main()
{
	int count, h, t, m;
	char cmd[64];
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s%d%d%d", cmd, &t, &h, &m);
		m += h*60;
		if (*cmd == 'B')
		{
			m += 60*24-t;
		}
		else
		{
			m += t;
		}
		m %= 60*24;
		printf("%d %d\n", m/60, m%60);
	}
	return 0;
}
