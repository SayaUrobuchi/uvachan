#include <stdio.h>
#include <string.h>

char str[10000];

int main()
{
    int count, len;
    scanf("%d", &count);
    gets(str);
    while(count--)
    {
        gets(str);
        len = strlen(str);
        if(len == 1 && (str[0] == 49 || str[0] == 52) || !strcmp(str, "78"))
        {
            puts("+");
        }
        else if(str[len-1] == 53 && str[len-2] == 51)
        {
            puts("-");
        }
        else if(str[0] == 57 && str[len-1] == 52)
        {
            puts("*");
        }
        else
        {
            puts("?");
        }
    }
    return 0;
}
