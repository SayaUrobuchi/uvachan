#include <stdio.h>

char s[256];

int main()
{
	int count, i, op, isx, num, isnum, cf, xf, rev, res;
    scanf("%d", &count);
    gets(s);
    while (count--)
    {
        gets(s);
        op = 0;
        isx = 0;
        num = 0;
        isnum = 0;
        cf = 0;
        xf = 0;
        rev = 1;
        for (i=0; ; i++)
        {
            if (s[i] >= '0' && s[i] <= '9')
            {
                num = num*10 + s[i]-'0';
                isnum = 1;
            }
            else if (s[i] == 'x')
            {
                isx = 1;
            }
            else
            {
                if (!isnum && isx)
                {
                    num = 1;
                }
                if (op)
                {
                    num = -num;
                }
                if (isx)
                {
                    xf += num * rev;
                }
                else
                {
                    cf -= num * rev;
                }
                if (s[i] == '=' || s[i] == '+')
                {
                    op = 0;
                }
                else
                {
                    op = 1;
                }
				if (s[i] == '=')
				{
					rev = -1;
				}
				num = 0;
				isx = 0;
				isnum = 0;
            }
			if (!s[i])
			{
				break;
			}
        }
        if (xf == 0)
        {
            if (cf == 0)
            {
                puts("IDENTITY");
            }
            else
            {
                puts("IMPOSSIBLE");
            }
        }
        else
        {
            res = cf / xf;
            if (cf % xf && xf * cf < 0)
            {
                --res;
            }
            printf("%d\n", res);
        }
    }
    return 0;
}