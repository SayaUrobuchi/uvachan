#include <iostream>
using namespace std;

long long ary[3];
char num[3][32], buf[3][32], op[32];

int main()
{
	int i, j, k, a, b;
	scanf("%s%s%s%*s%s", num[0], op, num[1], num[2]);
	bool is_ans = false;
	for (i=0; i<3&&!is_ans; i++)
	{
		for (j=i+1; j<3&&!is_ans; j++)
		{
			for (a=1; num[i][a]&&!is_ans; a++)
			{
				for (b=1; num[j][b]&&!is_ans; b++)
				{
					sprintf(buf[i], "%.*s%s", b, num[j], num[i]+a);
					sprintf(buf[j], "%.*s%s", a, num[i], num[j]+b);
					sprintf(buf[3-i-j], "%s", num[3-i-j]);
					bool is_ok = true;
					for (k=0; k<3&&is_ok; k++)
					{
						sscanf(buf[k], "%lld", &ary[k]);
						if (ary[k] < 0 || ary[k] > 2147483647)
						{
							is_ok = false;
						}
					}
					if (is_ok)
					{
						if (*op == '+')
						{
							is_ok = (ary[0] + ary[1] == ary[2]);
						}
						else
						{
							is_ok = (ary[0] * ary[1] == ary[2]);
						}
					}
					if (is_ok)
					{
						is_ans = true;
						printf("%s %s %s = %s\n", buf[0], op, buf[1], buf[2]);
					}
				}
			}
		}
	}
	return 0;
}
