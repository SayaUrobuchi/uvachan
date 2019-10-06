#include <stdio.h>

char s[1048576], cmd[8];

long long gcd(long long p, long long q)
{
    while ((p%=q) && (q%=p));
    return p+q;
}

int main()
{
    long long p, q;
    long long res;
    while (fgets(s, sizeof(s), stdin))
    {
        res = sscanf(s, "%[A-Z] ( %lld , %lld )", cmd, &p, &q);
        switch (*cmd)
        {
        case 'G':
            res = gcd(p, q);
            break;
        case 'L':
            res = (long long)p/gcd(p, q)*q;
            break;
        case 'A':
            res = (long long)p + q;
            break;
        case 'S':
            res = p - q;
            break;
        case 'M':
            res = (long long)p * q;
            break;
        case 'D':
            res = p / q;
            break;
        }
        printf("%lld\n", res);
    }
    return 0;
}
