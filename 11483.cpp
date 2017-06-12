#include <stdio.h>

char str[100005];

int main()
{
	int cas, n, i, j;
	cas = 0;
	while(gets(str))
	{
		sscanf(str, "%d", &n);
		if(n == 0)
		{
			break;
		}
		printf("Case %d:\n", ++cas);
		printf("#include<string.h>\n");
		printf("#include<stdio.h>\n");
		printf("int main()\n");
		printf("{\n");
		for(i=0; i<n; i++)
		{
			printf("printf(\"");
			gets(str);
			for(j=0; str[j]; j++)
			{
				if(str[j] == '"' || str[j] == '\\')
				{
					printf("\\");
				}
				printf("%c", str[j]);
			}
			printf("\\n\");\n");
		}
		printf("printf(\"\\n\");\n");
		printf("return 0;\n");
		printf("}\n");
	}
	return 0;
}
