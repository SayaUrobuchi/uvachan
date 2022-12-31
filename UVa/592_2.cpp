#include <iostream>
using namespace std;

const int HUMAN = 0;
const int DIVINE = 1;
const int EVIL = 2;
const int DAY = 0;
const int NIGHT = 1;
const int LYING = 5;

const int DIALOG_N = 50;
const int N = 6;
const int M = 3;
const int ALL = M*M*M*M*M*2;
const int WEATHER = 5;

const string name_str[] = {"A", "B", "C", "D", "E", "It"};
const string desc_str[][3] = {
	{"human", "divine", "evil"}, 
	{"day", "night"}
};

int speaker[DIALOG_N], target[DIALOG_N], descript[DIALOG_N], revers[DIALOG_N];
int guess[N], match[N][M];
int fact_target[N], fact_desc[N];

int to_desc(const string &s)
{
	if (s == "day.")
	{
		return DAY;
	}
	else if (s == "night.")
	{
		return NIGHT;
	}
	else if (s == "human.")
	{
		return HUMAN;
	}
	else if (s == "divine.")
	{
		return DIVINE;
	}
	else if (s == "evil.")
	{
		return EVIL;
	}
	return LYING;
}

int to_id(const string &s)
{
	return s[0] - 'A';
}

bool judge_lying(int guess[], int speaker)
{
	return guess[speaker] == EVIL
	   || (guess[speaker] == HUMAN && guess[WEATHER] == NIGHT);
}

void print_ans(int target, int desc)
{
	cout << name_str[target] << " is " << desc_str[target/5][desc] << ".\n";
}

int main()
{
	int cas, n, i, j, t, d, ans;
	bool is_conflict, is_truth, truth;
	string s, ignored;
	cas = 0;
	while (cin >> n)
	{
		if (n == 0)
		{
			break;
		}
		// 將輸入的敘述轉存成狀態
		for (i=0; i<n; i++)
		{
			cin >> s;
			speaker[i] = to_id(s);
			cin >> s;
			if (s == "I")
			{
				target[i] = speaker[i];
			}
			else if (s == "It")
			{
				target[i] = WEATHER;
			}
			else
			{
				target[i] = to_id(s);
			}
			cin >> ignored >> s;
			revers[i] = false;
			if (s == "not")
			{
				revers[i] = true;
				cin >> s;
			}
			descript[i] = to_desc(s);
		}
		for (i=0; i<N; i++)
		{
			for (j=0; j<M; j++)
			{
				match[i][j] = 0;
			}
		}
		// 進位制窮舉所有可能，一一檢查是否符合所有敘述
		for (i=0; i<ALL; i++)
		{
			t = i;
			guess[WEATHER] = (t & 1) + DAY;
			t >>= 1;
			for (j=0; j<5; j++, t/=3)
			{
				guess[j] = (t % 3);
			}
			for (j=0, is_conflict=false; j<n&&!is_conflict; j++)
			{
				is_truth = !revers[j];
				if (judge_lying(guess, speaker[j]))
				{
					is_truth = !is_truth;
				}
				if (descript[j] == LYING)
				{
					truth = judge_lying(guess, target[j]);
				}
				else
				{
					truth = (guess[target[j]] == descript[j]);
				}
				if (truth != is_truth)
				{
					is_conflict = true;
				}
			}
			// 若無矛盾，記錄每個對象存在這種可能
			if (!is_conflict)
			{
				for (j=0; j<N; j++)
				{
					++match[j][guess[j]];
				}
			}
		}
		// 若任一敘述符合數為 0 => 矛盾
		// 若無任何敘述有唯一解 => 完全無法特定
		// 若某敘述有唯一解 => 可被特定
		for (i=0, ans=0, is_conflict=false; i<N&&!is_conflict; i++)
		{
			for (j=0, d=0, t=0; j<M; j++)
			{
				if (match[i][j] != 0)
				{
					++t;
					d = j;
				}
			}
			if (t == 0)
			{
				is_conflict = true;
			}
			else if (t == 1)
			{
				fact_target[ans] = i;
				fact_desc[ans] = d;
				++ans;
			}
		}
		++cas;
		cout << "Conversation #" << cas << "\n";
		if (is_conflict)
		{
			cout << "This is impossible.\n";
		}
		else if (ans == 0)
		{
			cout << "No facts are deducible.\n";
		}
		else
		{
			for (i=0; i<ans; i++)
			{
				print_ans(fact_target[i], fact_desc[i]);
			}
		}
		cout << "\n";
	}
	return 0;
}