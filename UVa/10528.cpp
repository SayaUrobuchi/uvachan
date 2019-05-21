#include <stdio.h>
#include <string.h>
#include <unordered_map>

char *notes[] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
std::unordered_map<std::string, int> tbl;
int level[] = {0, 2, 2, 1, 2, 2, 2};
int rev_level[13];

int ary[1024];
char buf[1024], s[1024];

int main()
{
	int n, i, j, sum, pos, first;
	char *ptr;
	for (i=0; i<12; i++)
	{
		tbl[notes[i]] = i;
	}
	for (i=0, sum=0; i<7; i++)
	{
		sum += level[i];
		rev_level[sum] = 1;
	}
	while (fgets(buf, sizeof(buf), stdin))
	{
		if (!strtok(buf, "\r\n"))
		{
			*buf = 0;
		}
		if (!strcmp(buf, "END"))
		{
			break;
		}
		for (i=0, ptr=buf; ; i++)
		{
			if (sscanf(ptr, "%s%n", s, &pos) != 1)
			{
				break;
			}
			ary[i] = tbl[s];
			//printf("ary[%d] = %d\n", i, ary[i]);
			ptr += pos;
		}
		n = i;
		first = 1;
		for (i=0; i<12; i++)
		{
			for (j=0; j<n&&rev_level[(ary[j]+12-i)%12]; j++);
			if (j >= n)
			{
				printf(first?"%s":" %s", notes[i]);
				first = 0;
			}
		}
		puts("");
	}
	return 0;
}
