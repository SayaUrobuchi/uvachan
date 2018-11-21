/*
ID: dd.ener1
PROG: pprime
LANG: C++
*/
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

long A,B;
long maxp;
bool* prime;
basic_string<long> primes;

void input(){
	freopen("pprime.in","r",stdin);
	scanf("%d%d",&A,&B);
	maxp=B+1;
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
bool isprime(long p){
	if(p<maxp)return prime[p];
	static long len=primes.length();
	long end=long(sqrt(double(p)));
	for(long i=0;i<len&&primes[i]<=end;++i)
		if(!(p%primes[i]))return false;
	return true;
}
inline long makepals(long n){
	static char str[20];
	long len=sprintf(str,"%d",n);
	for(long i=len-2,j=len;i>=0;--i,++j)
		str[j]=str[i];
	str[len*2-1]='\0';
	return atol(str);
}
inline void output(long n){
	if(n<A||n>B)return;
	static FILE *out=fopen("pprime.out","w");
	fprintf(out,"%d\n",n);
}
void produce(){
	if(A<=11){
		output(3);
		output(5);
		output(7);
		output(11);
		A=12;
	}
	for(long beg=1;;beg*=10){
		long end=beg*10;
		if(beg*end<A)continue;
		if(beg*beg>B)break;
		for(long i=beg;i<end;++i){
			long a=makepals(i);
			if(a>B)return;
			if(isprime(a))output(a);
		}
	}
}
int main(){
	input();
	solveprime();
	produce();
	return 0;
}
