/*
ID: dd.ener1
PROG: prime3
LANG: C++
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

int L,Sum;
int S[1000][5];
int S2[1000][4];
bool V[11][11][11][11][11];
int Now[5][5];
int res[300][5][5];
int N,N2,R;
int Mid[10][1000][4];//中间一数已确定
int MidN[10];
int EENo0[10][10][500][3];//两边两数已确定且没有0
int EENo0N[10][10];
int EE1379[10][10][300][3];//两边两数已确定且仅有1379组成
int EE1379N[10][10];

void input(){
	freopen("prime3.in","r",stdin);
	scanf("%d%d",&Sum,&L);
}
void add_S(int k){
	static char s[6];
	sprintf(s,"%d",k);
	int sum=0;
	for(int i=0;i<5;++i){
		s[i]-='0';
		sum+=s[i];
	}
	if(sum!=Sum)return;
	for(int i=0;i<5;++i)
		S[N][i]=s[i];
	++N;
	Mid[s[2]][MidN[s[2]]][0]=s[0];
	Mid[s[2]][MidN[s[2]]][1]=s[1];
	Mid[s[2]][MidN[s[2]]][2]=s[3];
	Mid[s[2]][MidN[s[2]]][3]=s[4];
	++MidN[s[2]];
	if(s[0]==L){
		for(int i=0;i<4;++i)
			S2[N2][i]=s[i+1];
		++N2;
	}
	if((s[1]%2)&&(s[2]%2)&&(s[3]%2)&&s[1]!=5&&s[2]!=5&&s[3]!=5){
		for(int i=0;i<3;++i)
			EE1379[s[0]][s[4]][EE1379N[s[0]][s[4]]][i]=s[i+1];
		EE1379N[s[0]][s[4]]++;
	}
	if(s[1]&&s[2]&&s[3]){
		for(int i=0;i<3;++i)
			EENo0[s[0]][s[4]][EENo0N[s[0]][s[4]]][i]=s[i+1];
		EENo0N[s[0]][s[4]]++;
	}
}
void gen_S(){
	bool pp[100000];
	memset(pp,-1,sizeof(pp));
	pp[0]=pp[1]=false;
	for(int p=2;p<100000;++p){
		if(!pp[p])continue;
		for(int k=2;k*p<100000;++k)
			pp[k*p]=false;
	}
	N=0;
	for(int k=10000;k<=99999;++k)
		if(pp[k])add_S(k);
}
void gen_V(){
	memset(V,0,sizeof(V));
	V[10][10][10][10][10]=true;
	for(int i=0;i<N;++i){
		int a=S[i][0],b=S[i][1],c=S[i][2],d=S[i][3],e=S[i][4];
		const int x=10;
		V[a][x][x][x][x]=true;
		V[x][b][x][x][x]=true;
		V[x][x][c][x][x]=true;
		V[x][x][x][d][x]=true;
		V[x][x][x][x][e]=true;
		
		V[a][b][x][x][x]=true;
		V[a][x][c][x][x]=true;
		V[a][x][x][d][x]=true;
		V[a][x][x][x][e]=true;
		V[x][b][c][x][x]=true;
		V[x][b][x][d][x]=true;
		V[x][b][x][x][e]=true;
		V[x][x][c][d][x]=true;
		V[x][x][c][x][e]=true;
		V[x][x][x][d][e]=true;
		
		V[a][b][c][x][x]=true;
		V[a][b][x][d][x]=true;
		V[a][b][x][x][e]=true;
		V[a][x][c][d][x]=true;
		V[a][x][c][x][e]=true;
		V[a][x][x][d][e]=true;
		V[x][b][c][d][x]=true;
		V[x][b][c][x][e]=true;
		V[x][b][x][d][e]=true;
		V[x][x][c][d][e]=true;
		
		V[a][b][c][d][x]=true;
		V[a][b][c][x][e]=true;
		V[a][b][x][d][e]=true;
		V[a][x][c][d][e]=true;
		V[x][b][c][d][e]=true;
		
		V[a][b][c][d][e]=true;
	}
}
void print(){
	for(int i=0;i<5;++i){
		for(int j=0;j<5;++j)
			printf("%d",Now[i][j]);
		putchar('\n');
	}
	putchar('\n');
}
void add_res(){
	print();
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			res[R][i][j]=Now[i][j];
	++R;
}
void search6(){//(2,1)(2,3)
	for(Now[2][1]=0;Now[2][1]<10;++Now[2][1]){
		if(!V[Now[0][1]][Now[1][1]][Now[2][1]][Now[3][1]][Now[4][1]])continue;
		for(Now[2][3]=0;Now[2][3]<10;++Now[2][3]){
			if(!V[Now[0][3]][Now[1][3]][Now[2][3]][Now[3][3]][Now[4][3]])continue;
			if(!V[Now[2][0]][Now[2][1]][Now[2][2]][Now[2][3]][Now[2][4]])continue;
			add_res();
		}
	}
	Now[2][1]=Now[2][3]=10;
}
void search5(){//(1,2)(3,2)
	for(Now[1][2]=0;Now[1][2]<10;++Now[1][2]){
		if(!V[Now[1][0]][Now[1][1]][Now[1][2]][Now[1][3]][Now[1][4]])continue;
		for(Now[3][2]=0;Now[3][2]<10;++Now[3][2]){
			if(!V[Now[3][0]][Now[3][1]][Now[3][2]][Now[3][3]][Now[3][4]])continue;
			if(!V[Now[0][2]][Now[1][2]][Now[2][2]][Now[3][2]][Now[4][2]])continue;
			search6();
		}
	}
	Now[1][2]=Now[3][2]=10;
}
void search4(){//枚举上部中间的三个和左边中间的三个
	for(int i=EENo0N[Now[0][0]][Now[0][4]]-1;i>=0;--i){
		Now[0][1]=EENo0[Now[0][0]][Now[0][4]][i][0];
		if(!V[Now[0][1]][Now[1][1]][Now[2][1]][Now[3][1]][Now[4][1]])continue;
		Now[0][2]=EENo0[Now[0][0]][Now[0][4]][i][1];
		if(!V[Now[0][2]][Now[1][2]][Now[2][2]][Now[3][2]][Now[4][2]])continue;
		Now[0][3]=EENo0[Now[0][0]][Now[0][4]][i][2];
		if(!V[Now[0][3]][Now[1][3]][Now[2][3]][Now[3][3]][Now[4][3]])continue;
			for(int j=EENo0N[Now[0][0]][Now[4][0]]-1;j>=0;--j){
				Now[1][0]=EENo0[Now[0][0]][Now[4][0]][j][0];
				if(!V[Now[1][0]][Now[1][1]][Now[1][2]][Now[1][3]][Now[1][4]])continue;
				Now[2][0]=EENo0[Now[0][0]][Now[4][0]][j][1];
				if(!V[Now[2][0]][Now[2][1]][Now[2][2]][Now[2][3]][Now[2][4]])continue;
				Now[3][0]=EENo0[Now[0][0]][Now[4][0]][j][2];
				if(!V[Now[3][0]][Now[3][1]][Now[3][2]][Now[3][3]][Now[3][4]])continue;
				search5();
			}
	}
	Now[0][1]=Now[0][2]=Now[0][3]=Now[1][0]=Now[2][0]=Now[3][0]=10;
}
void search3(){//枚举底部中间的三个和右边中间的三个
	if(!EE1379N[Now[0][4]][Now[4][4]]||!EE1379N[Now[4][0]][Now[4][4]])return;
	for(int i=EE1379N[Now[4][0]][Now[4][4]]-1;i>=0;--i){
		Now[4][1]=EE1379[Now[4][0]][Now[4][4]][i][0];
		if(!V[Now[0][1]][Now[1][1]][Now[2][1]][Now[3][1]][Now[4][1]])continue;
		Now[4][2]=EE1379[Now[4][0]][Now[4][4]][i][1];
		if(!V[Now[0][2]][Now[1][2]][Now[2][2]][Now[3][2]][Now[4][2]])continue;
		Now[4][3]=EE1379[Now[4][0]][Now[4][4]][i][2];
		if(!V[Now[0][3]][Now[1][3]][Now[2][3]][Now[3][3]][Now[4][3]])continue;
		for(int j=EE1379N[Now[0][4]][Now[4][4]]-1;j>=0;--j){
			Now[1][4]=EE1379[Now[0][4]][Now[4][4]][j][0];
			if(!V[Now[1][0]][Now[1][1]][Now[1][2]][Now[1][3]][Now[1][4]])continue;
			Now[2][4]=EE1379[Now[0][4]][Now[4][4]][j][1];
			if(!V[Now[2][0]][Now[2][1]][Now[2][2]][Now[2][3]][Now[2][4]])continue;
			Now[3][4]=EE1379[Now[0][4]][Now[4][4]][j][2];
			if(!V[Now[3][0]][Now[3][1]][Now[3][2]][Now[3][3]][Now[3][4]])continue;
			search4(); 
		}
	}
	Now[4][1]=Now[4][2]=Now[4][3]=Now[1][4]=Now[2][4]=Now[3][4]=10;
}
void search2(){//枚举右上到左下对角线
	int M=Now[2][2];
	for(int i=MidN[M]-1;i>=0;--i){
		Now[0][4]=Mid[M][i][0];
		Now[1][3]=Mid[M][i][1];
		Now[3][1]=Mid[M][i][2];
		Now[4][0]=Mid[M][i][3];
		search3();
	}
	Now[0][4]=Now[1][3]=Now[3][1]=Now[4][0]=10;
}
void search1(){//枚举左上到右下的对角线 
	for(int i=0;i<N2;++i){
		Now[1][1]=S2[i][0];
		Now[2][2]=S2[i][1];
		Now[3][3]=S2[i][2];
		Now[4][4]=S2[i][3];
		search2();
	}
}
void solve(){
	gen_S();
	gen_V();
	R=0;
	for(int i=0;i<5;++i)
		for(int j=0;j<5;++j)
			Now[i][j]=10;
	Now[0][0]=L;
	search1();
}
void output(){
	freopen("prime3.out","w",stdout);
	if(R==0){
		puts("NONE");
		return;
	}
	string ss[R];
	for(int k=0;k<R;++k){
		ostringstream s;
		for(int j=0;j<5;++j){
			for(int i=0;i<5;++i)
				s<<res[k][i][j];
			s<<'\n';
		}
		ss[k]=s.str();
	}
	sort(ss,ss+R);
	for(int k=0;k<R-1;++k)
		printf("%s\n",ss[k].c_str());
	printf("%s",ss[R-1].c_str());
}
int main(){
	freopen("prime3.log","w",stdout);
	input();
	solve();
	output();
}
