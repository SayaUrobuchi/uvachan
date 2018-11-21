/*
ID: dd.ener1
PROG: wissqu
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <cstdlib>
using namespace std;

int s[6][6];//现在的牛，只使用1-4的数祖下标 
int v[6][6][5];//v[i][j][k]表示(i,j)周围k种牛的数目
int l[5]={3,3,3,4,3};//表示某种牛还剩下的个数 
int stx[16],sty[16],stc[16];//栈上保存步骤，移(x,y)的c
int resx[16],resy[16],resc[16];
bool mark[6][6];//表示已经移动过了 
int res;


void input(){
	memset(s,-1,sizeof(s));
	freopen("wissqu.in","r",stdin);
	for(int i=1;i<=4;++i){
		for(int j=1;j<=4;++j)
			s[i][j]=getchar()-'A';
		getchar();
	}
}
void fill(int i,int j,int c,int d){
	for(int d1=-1;d1<=1;++d1)
		for(int d2=-1;d2<=1;++d2)
			v[i+d1][j+d2][c]+=d;
}
void pretreat(){
	memset(v,0,sizeof(v));
	memset(mark,0,sizeof(mark));
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j)
			fill(i,j,s[i][j],1);
}
void solution(){
	if(!res)
		for(int k=0;k<16;++k){
			resx[k]=stx[k];
			resy[k]=sty[k];
			resc[k]=stc[k];
		}
	++res;
}
void replace(int i,int j,int n){
	fill(i,j,s[i][j],-1);
	s[i][j]=n;
	fill(i,j,n,1);
}
void search(int k){
	if(k==16){
		solution();
		return;
	}
	for(int c=0;c<5;++c){
		if(l[c]<=0)continue;
		stc[k]=c;
		--l[c];
		for(int i=1;i<=4;++i)
			for(int j=1;j<=4;++j){
				if(mark[i][j])continue;
				if(v[i][j][c]>0)continue;
				stx[k]=i;
				sty[k]=j;
				
				int old=s[i][j];
				replace(i,j,c);
				mark[i][j]=true;
				
				search(k+1);
				
				mark[i][j]=false;
				replace(i,j,old);
			}
		++l[c];
	}
}
void search0(){
	const int c=3,k=0;

	stc[k]=c;
	--l[c];
	for(int i=1;i<=4;++i)
		for(int j=1;j<=4;++j){
			if(v[i][j][c]>0)continue;
			stx[k]=i;
			sty[k]=j;

			int old=s[i][j];
			replace(i,j,c);
			mark[i][j]=true;

			search(k+1);

			mark[i][j]=false;
			replace(i,j,old);
		}
	++l[c];
}
void solve(){
	pretreat();
	search0();
}
void output(){
	freopen("wissqu.out","w",stdout);
	for(int i=0;i<16;++i)
		printf("%c %d %d\n",'A'+resc[i],resx[i],resy[i]);
	printf("%d\n",res);
}
int main(){
	freopen("wissqu.log","w",stdout);
	input();
	solve();
	output();
}
