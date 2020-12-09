#include <iostream>
#include <unordered_map>

using um = std::unordered_map<int, std::string>;

const char *ot = "+-*/";

int stk[1024], sn;
int op[1024], opn;
int ord[] = {0, 0, 1, 1};
char buf[1024];

void exec(int op)
{
	//printf("exec %c: %d %d .. ", ot[op], stk[sn-2], stk[sn-1]);
	if (op == 0)
	{
		stk[sn-2] = stk[sn-2] + stk[sn-1];
	}
	else if (op == 1)
	{
		stk[sn-2] = stk[sn-2] - stk[sn-1];
	}
	else if (op == 2)
	{
		stk[sn-2] = stk[sn-2] * stk[sn-1];
	}
	else if (op == 3)
	{
		if (stk[sn-1] == 0)
		{
			stk[sn-2] = 100000000;
		}
		else
		{
			stk[sn-2] = stk[sn-2] / stk[sn-1];
		}
	}
	//printf(" %d\n", stk[sn-2]);
	--sn;
}

int main()
{
	int count, i, j, u, t;
	um tbl;
	um::iterator it;
	for (i=0; i<64; i++)
	{
		for (j=0, t=i, sn=0, opn=0; j<7; j++)
		{
			if (j & 1)
			{
				u = (t & 3);
				t >>= 2;
				for (; opn>0; opn--)
				{
					if (ord[u] > ord[op[opn-1]])
					{
						break;
					}
					exec(op[opn-1]);
				}
				op[opn++] = u;
			}
			else
			{
				stk[sn] = 4;
				++sn;
			}
		}
		for (; opn>0; opn--)
		{
			exec(op[opn-1]);
		}
		sprintf(buf, "4 %c 4 %c 4 %c 4 = %d", ot[i&3], ot[(i>>2)&3], ot[(i>>4)&3], stk[0]);
		//puts(buf);
		tbl[stk[0]] = buf;
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &t);
		if ((it=tbl.find(t)) != tbl.end())
		{
			printf("%s\n", (it->second).c_str());
		}
		else
		{
			puts("no solution");
		}
	}
	return 0;
}
