/*
ID: dd.ener1
PROG: charrec
LANG: C++
*/

#include <cstdio>
#include <cstring>
using namespace std;

const int INF=100000000;
const int maxn=1200;
char dict[27][20][21];
char s[maxn][21];
int diff[maxn][27][20];//diff[i][k][j]��ʾ��i�����k����ĸ��j�еĲ�� 
int v[maxn][27];//v[i][k]��ʾ�ѵ�i�е��ɵ�k����ĸ�ĵ�0��ʱ�������С���
int l[maxn][27];//l[i][k]��ʾv[i][k]���ֵʱ������ 
int N;

void input(){
	freopen("font.in","r",stdin);
	scanf("%d\n",&N);
	for(int k=0;k<=26;++k)
		for(int i=0;i<20;++i)
			scanf("%s\n",dict[k][i]);
	freopen("charrec.in","r",stdin);
	scanf("%d\n",&N);
	for(int i=0;i<N;++i)
		scanf("%s\n",s[i]);
}
void solve_diff(){
	memset(diff,INF,sizeof(diff));
	for(int i=0;i<N;++i)
		for(int k=0;k<=26;++k)
			for(int j=0;j<20;++j){
				diff[i][k][j]=0;
				for(int l=0;l<20;++l)
					diff[i][k][j]+=(s[i][l]!=dict[k][j][l]);
			}
	for(int k=0;k<=26;++k)
		diff[N][k][0]=0;
}
bool update(int& old,int x){
	if(old>x){
		old=x;
		return true;
	}
	return false;
}
void solve(int I,int K){
	v[I][K]=INF;
	{
		//û����Ӻ���©�����
		int res1=INF;
		for(int k=0;k<=26;++k)
			update(res1,v[I+20][k]);
		for(int j=0;j<20;++j)
			res1+=diff[I+j][K][j];
		if(update(v[I][K],res1))
			l[I][K]=20;
	}
	{
		//��©��һ�е����
		int res21=INF;
		for(int k=0;k<=26;++k)
			update(res21,v[I+19][k]);
		int res22=INF;
		for(int del=0;del<20;++del){
			int t=0;
			for(int j1=0,j2=0;j1<19;++j1,++j2){
				if(j2==del)++j2;
				t+=diff[I+j1][K][j2];
			}
			update(res22,t);
		}
		if(update(v[I][K],res21+res22))
			l[I][K]=19;
	}
	{
		//�����һ�е����
		int res31=INF;
		for(int k=0;k<=26;++k)
			update(res31,v[I+21][k]);
		int res32=INF;
		for(int del=0;del<21;++del){
			int t=0;
			for(int j1=0,j2=0;j1<21;++j1,++j2){
				if(j1==del)++j1;
				t+=diff[I+j1][K][j2];
			}
			update(res32,t);
		}
		if(update(v[I][K],res31+res32))
			l[I][K]=21;
	}
}
void solve(){
	solve_diff();
	for(int i=N-1;i>=0;--i)
		for(int k=0;k<=26;++k)
			solve(i,k);
}
void print(int k){
	if(!k)
		putchar(' ');
	else
		putchar('a'-1+k);
}
void output(){
	freopen("charrec.out","w",stdout);
	for(int I=0;I<N;){
		int best=INF,K=-1;
		for(int k=0;k<=26;++k)
			if(update(best,v[I][k]))
				K=k;
		print(K);
		I+=l[I][K];
	}
	putchar('\n');
}
int main(){
	input();
	solve();
	output();
}
