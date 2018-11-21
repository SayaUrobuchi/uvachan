/*
ID: dd.ener1
PROG: theme
LANG: C++
*/

#include <cstdio>
using namespace std;

int s[6000];
int N;
int res;

void input(){
	freopen("theme.in","r",stdin);
	scanf("%d",&N);
	for(int i=0;i<N;++i)
		scanf("%d",s+i);
}
void solve(){
	for(int d=1;d<N;++d){
		int pre=0;
		for(int i=N-1;i>=0;--i){
			int j=i+d;
			if(j>=N)continue;
			int now=
				s[j+1]-s[i+1]==s[j]-s[i]?
				pre+1:1;
			if(now>d)now=d;
			if(now>res)res=now;
			pre=now;
		}
	}
	if(res<5)res=0;
}
void output(){
	freopen("theme.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	solve();
	output();
}
