/*
ID: dd.ener1
PROG: vans
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=1024;

struct BigNum{
	long s[100];
	BigNum(long n=0){
		memset(s,0,sizeof(s));
		s[0]=n;
	}
	void smooth(){
		for(long i=0;i<99;++i){
			s[i+1]+=s[i]/100000000;
			s[i]%=100000000;
		}
	}
	void operator+=(BigNum b){
		for(long i=0;i<100;++i)
			s[i]+=b.s[i];
		smooth();
	}
	static void output(long n){
		char s[20];
		sprintf(s,"%d",n);
		for(long l=strlen(s);l<8;++l)
			putchar('0');
		printf("%s",s);
	}
	void output(){
		long i=99;
		for(;i>=0&&s[i]==0;--i);
		if(i==-1)i=0;
		printf("%d",s[i]);
		for(--i;i>=0;--i)
			output(s[i]);
		putchar('\n');
	}
}a[maxn],b[maxn],s;

int N;

int main(){
	freopen("vans.in","r",stdin);
	scanf("%d",&N);

	a[2]=2;
	for(int i=3;i<=N;++i){
		s+=b[i-1];
		a[i]=2;
		a[i]+=a[i-2];
		a[i]+=s;
		a[i]+=s;
		b[i]=a[i-1];
		b[i]+=b[i-1];
	}

	a[N]+=b[N];
	freopen("vans.out","w",stdout);
	a[N].output();
}
