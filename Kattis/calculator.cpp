#include <iostream>
#include <vector>
using namespace std;
using pp = pair<int, int>;

const int N = 1048576;
const int NUM = 0;
const int OP = 1;

int prio[128];
char s[N];

int main()
{
	int i;
	prio['+'] = prio['-'] = 5;
	prio['*'] = prio['/'] = 10;
	prio['('] = 0;
	while (fgets(s, sizeof(s), stdin))
	{
		int p, t, last;
		char op;
		vector<char> vop;
		vector<pp> vexpr;
		last = OP;
		for (i=0; s[i]>=' '; i+=p)
		{
			if (last == OP && sscanf(s+i, "%d%n", &t, &p) == 1)
			{
				vexpr.emplace_back(NUM, t);
				last = NUM;
			}
			else
			{
				sscanf(s+i, " %c%n", &op, &p);
				if (op == '(')
				{
					vop.emplace_back(op);
				}
				else if (op == ')')
				{
					while (vop.back() != '(')
					{
						vexpr.emplace_back(OP, vop.back());
						vop.pop_back();
					}
					vop.pop_back();
				}
				else
				{
					while (!vop.empty() && prio[op] <= prio[vop.back()])
					{
						vexpr.emplace_back(OP, vop.back());
						vop.pop_back();
					}
					vop.emplace_back(op);
				}
				last = OP;
			}
		}
		while (!vop.empty())
		{
			vexpr.emplace_back(OP, vop.back());
			vop.pop_back();
		}
		vector<double> vres;
		for (decltype(vexpr)::iterator it=vexpr.begin(); it!=vexpr.end(); ++it)
		{
			if (it->first == NUM)
			{
				vres.emplace_back(it->second);
			}
			else
			{
				double a, b, r;
				b = vres.back();
				vres.pop_back();
				a = vres.back();
				vres.pop_back();
				//printf("%.2lf %c %.2lf\n", a, it->second, b);
				if (it->second == '+')
				{
					r = (a + b);
				}
				else if (it->second == '-')
				{
					r = (a - b);
				}
				else if (it->second == '*')
				{
					r = (a * b);
				}
				else
				{
					r = (a / b);
				}
				vres.emplace_back(r);
			}
		}
		printf("%.2lf\n", vres.back());
	}
	return 0;
}
