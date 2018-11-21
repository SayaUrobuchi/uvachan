/*
ID: dd.ener1
PROG: buylow
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

struct BigNum{
	long s[200];
	BigNum(long n=0){
		memset(s,0,sizeof(s));
		s[0]=n;
	}
	void smooth(){
		for(long i=0;i<199;++i){
			s[i+1]+=s[i]/1000000;
			s[i]%=1000000;
		}
	}
	void operator-=(BigNum b){
		for(long i=0;i<200;++i)
			s[i]-=b.s[i];
		for(long i=0;i<199;++i){
			while(s[i]<0){
				s[i]+=1000000;
				--s[i+1];
			}
			s[i+1]+=s[i]/1000000;
			s[i]%=1000000;
		}
	}
	void operator+=(BigNum b){
		for(long i=0;i<200;++i)
			s[i]+=b.s[i];
		smooth();
	}
	static void output(long n){
		char s[20];
		sprintf(s,"%d",n);
		for(long l=strlen(s);l<6;++l)
			putchar('0');
		printf("%s",s);
	}
	void output(){
		long i=199;
		for(;s[i]==0;--i);
		printf("%d",s[i]);
		for(--i;i>=0;--i)
			output(s[i]);
		putchar('\n');
	}
};

const int maxn=5010;
int s[maxn];
int N;
int dp[maxn];
BigNum sum[maxn];

void input(){
	freopen("buylow.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d",s+i);
}
void solve(){
	s[N]=-1;
	for(int i=0;i<=N;++i){
		dp[i]=1;
		for(int j=0;j<i;++j)
			if(s[j]>s[i]&&dp[j]+1>dp[i])
				dp[i]=dp[j]+1;
	}
	for(int i=0;i<=N;++i){
		if(dp[i]==1)sum[i]=1;
		int j;
		for(j=0;j<i;++j)
			if(s[j]>s[i]&&dp[j]+1==dp[i])
				sum[i]+=sum[j];
		for(j=0;j<i&&(s[j]!=s[i]||dp[j]!=dp[i]);++j);
		if(j!=i)sum[i]-=sum[j];
	}
}
void output(){
	freopen("buylow.out","w",stdout);
	printf("%d ",dp[N]-1);
	sum[N].output();
}
int main(){
	input();
	solve();
	output();
}
