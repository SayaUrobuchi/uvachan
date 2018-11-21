/*
ID: dd.ener1
PROG: sprime
LANG: C++
*/
#include <fstream>
#include <cmath>
using namespace std;

long N;
long maxp;
bool* prime;
basic_string<long> primes;

void input(){
	ifstream cin("sprime.in");
	cin>>N;
	maxp=1;
	for(long i=0;i<N;++i)
		maxp*=10;
	if(maxp>500000)maxp=500000;
}
void solveprime(){
	prime=new bool[maxp];
	memset(prime,true,sizeof(bool)*maxp);
	for(unsigned long i=2L;i<maxp;++i){
		if(!prime[i])continue;
		primes+=i;
		for(unsigned long j=i;;++j){
			if(i*j>=maxp)break;
			prime[i*j]=false;
		}
	}
}
inline bool isprime(long p){
	if(p<maxp)return prime[p];
	long len=primes.length();
	for(long i=0;i<len&&primes[i]*primes[i]<=p;++i)
		if(!(p%primes[i]))return false;
	return true;
}
inline void output(long p){
	static ofstream cout("sprime.out");
	cout<<p<<endl;
}
void search(long now,long len){
	if(len==N)output(now);
	now*=10;
	for(long i=0;i<=9;++i)
		if(isprime(now+i))search(now+i,len+1);
}
int main(){
	input();
	solveprime();
	search(2,1);
	search(3,1);
	search(5,1);
	search(7,1);
	return 0;
}
