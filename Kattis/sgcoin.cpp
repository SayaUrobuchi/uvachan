#include <iostream>
using namespace std;

string msg[] = {"wryyyyyyyyyyyyyyyy", "mudamudamudamudamudamudamudamudamudamudamudamudamudamuda"};
long long target[] = {930000000, 730000000};

// ---- copied from problem description
long long H(long long previousHash, string &transaction,
            long long token) {
  long long v = previousHash;
  for (int i = 0; i < transaction.length(); i++) {
    v = (v * 31 + transaction[i]) % 1000000007;
  }
  return (v * 7 + token) % 1000000007;
}
// ---- copied from problem description

long long calc(long long h, string &s, long long t)
{
  long long v = h;
  for (int i = 0; i < s.length(); i++) {
    v = (v * 31 + s[i]) % 1000000007;
  }
  long long m = v*7 % 1000000007;
  return (t-m+1000000007)%1000000007;
}

int main()
{
	int i;
	long long n, token;
	while (scanf("%lld", &n) == 1)
	{
		for (i=0; i<2; i++)
		{
			token = calc(n, msg[i], target[i]);
			printf("%s %lld\n", msg[i].c_str(), token);
			n = H(n, msg[i], token);
			//printf("hash: %lld\n", n);
		}
	}
	return 0;
}
