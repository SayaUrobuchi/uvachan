/*
ID: dd.ener1
PROG: bigbrn
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int maxn=1024;
bool s[maxn][maxn];
int barn[maxn][maxn];

int N;
int res;

void input(){
	memset(s,0,sizeof(s));
	freopen("bigbrn.in","r",stdin);
	int m;
	scanf("%d%d",&N,&m);
	for(int i=0;i<m;++i){
		int x,y;
		scanf("%d%d",&x,&y);
		s[x][y]=true;
	}
}
int min(int a,int b){
	return a<b?a:b;
}
void solve(){
	res=0;
	for(int i=1;i<=N;++i){
		for(int j=1;j<=N;++j){
			barn[i][j]=s[i][j]?0:(min(barn[i-1][j-1],min(barn[i-1][j],barn[i][j-1]))+1);
			if(barn[i][j]>res)res=barn[i][j];
		}
	}
	
}
void output(){
	freopen("bigbrn.out","w",stdout);
	printf("%d\n",res);
}
int main(){
	input();
	solve();
	output();
}
