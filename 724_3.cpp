#include <stdio.h>
#include <string.h>

char *p, *ptr;
char buf[100000];

void write(char *s)
{
	strcpy(buf, s);
	p = buf + strlen(buf);
	for(ptr=s; *ptr; ptr++)
	{
		if(*ptr == '"')
		{
			*(p++) = '\\';
			*(p++) = '"';
		}
		else if(*ptr == '\\')
		{
			*(p++) = '\\';
			*(p++) = '\\';
		}
		else if(*ptr == '\n')
		{
			*(p++) = '\\';
			*(p++) = 'n';
		}
		else if(*ptr == '\t')
		{
			*(p++) = '\\';
			*(p++) = 't';
		}
		else
		{
			*(p++) = *ptr;
		}
	}
	strcpy(p, "\");\n\trev();\n\treturn 0;\n}\n");
	p += strlen(p);
	*p = 0;
	printf("%s", buf);
}

void rev()
{
	for(ptr=buf+strlen(buf)-2; ptr>=buf; ptr--)
	{
		putchar(*ptr);
	}
	putchar('\n');
}

int main()
{
	write("#include <stdio.h>\n#include <string.h>\n\nchar *p, *ptr;\nchar buf[100000];\n\nvoid write(char *s)\n{\n\tstrcpy(buf, s);\n\tp = buf + strlen(buf);\n\tfor(ptr=s; *ptr; ptr++)\n\t{\n\t\tif(*ptr == '\"')\n\t\t{\n\t\t\t*(p++) = '\\\\';\n\t\t\t*(p++) = '\"';\n\t\t}\n\t\telse if(*ptr == '\\\\')\n\t\t{\n\t\t\t*(p++) = '\\\\';\n\t\t\t*(p++) = '\\\\';\n\t\t}\n\t\telse if(*ptr == '\\n')\n\t\t{\n\t\t\t*(p++) = '\\\\';\n\t\t\t*(p++) = 'n';\n\t\t}\n\t\telse if(*ptr == '\\t')\n\t\t{\n\t\t\t*(p++) = '\\\\';\n\t\t\t*(p++) = 't';\n\t\t}\n\t\telse\n\t\t{\n\t\t\t*(p++) = *ptr;\n\t\t}\n\t}\n\tstrcpy(p, \"\\\");\\n\\trev();\\n\\treturn 0;\\n}\\n\");\n\tp += strlen(p);\n\t*p = 0;\n\tprintf(\"%s\", buf);\n}\n\nvoid rev()\n{\n\tfor(ptr=buf+strlen(buf)-2; ptr>=buf; ptr--)\n\t{\n\t\tputchar(*ptr);\n\t}\n\tputchar('\\n');\n}\n\nint main()\n{\n\twrite(\"");
	rev();
	return 0;
}
