#include <iostream>
#include <unordered_map>
#include <cstring>

char s[1024];

int main()
{
	int n, i, last, loser, turn;
	std::unordered_map<std::string, bool> tbl;
	while (scanf("%d%s", &n, s) == 2)
	{
		tbl.clear();
		tbl[s] = true;
		for (i=1, last=s[strlen(s)-1], turn=2, loser=0; i<n; i++, turn=3-turn)
		{
			scanf("%s", s);
			if (!loser && (*s != last || tbl.find(s) != tbl.end()))
			{
				loser = turn;
			}
			last = s[strlen(s)-1];
			tbl[s] = true;
		}
		if (loser)
		{
			printf("Player %d lost\n", loser);
		}
		else
		{
			puts("Fair Game");
		}
	}
	return 0;
}
