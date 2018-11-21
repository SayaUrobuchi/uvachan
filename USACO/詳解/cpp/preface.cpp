/*
ID: dd.ener1
PROG: preface
LANG: C++
*/

#include <cstdio>
using namespace std;

long N;
long I,V,X,L,C,D,M;

void input(){
	freopen("preface.in","r",stdin);
	scanf("%d",&N);
	I=V=X=L=C=D=M=0;
}
//M:1000
inline void solve_qian(long k){
	switch(k){
		case 3:
			++M;
		case 2:
			++M;
		case 1:
			++M;
	}
}
//C:100 D:500 M:1000
inline void solve_bai(long k){
	switch(k){
		case 9://CM
			++C;
			++M;
			break;
		case 8://DCCC
			++C;
		case 7://DCC
			++C;
		case 6://DC
			++C;
		case 5://D
			++D;
			break;
		case 4://CD
			++C;
			++D;
			break;
		case 3://CCC
			++C;
		case 2:
			++C;
		case 1:
			++C;
	}
}
//X:10 L:50 C:100
inline void solve_shi(long k){
	switch(k){
		case 9://XC
			++X;
			++C;
			break;
		case 8://LXXX
			++X;
		case 7://LXX
			++X;
		case 6://LX
			++X;
		case 5://L
			++L;
			break;
		case 4://XL
			++X;
			++L;
			break;
		case 3://XXX
			++X;
		case 2:
			++X;
		case 1:
			++X;
	}
}
//I:1 V:5 X:10
inline void solve_ge(long k){
	switch(k){
		case 9://IX
			++I;
			++X;
			break;
		case 8://VIII
			++I;
		case 7://VII
			++I;
		case 6://VI
			++I;
		case 5://V
			++V;
			break;
		case 4://IV
			++I;
			++V;
			break;
		case 3://III
			++I;
		case 2:
			++I;
		case 1:
			++I;
	}
}
inline void solve(long k){
	solve_qian(k/1000);
	solve_bai((k/100)%10);
	solve_shi((k/10)%10);
	solve_ge(k%10);
}
void solve(){
	for(long i=1;i<=N;++i)
		solve(i);
}
void output(){
	freopen("preface.out","w",stdout);
	if(I)printf("I %d\n",I);
	if(V)printf("V %d\n",V);
	if(X)printf("X %d\n",X);
	if(L)printf("L %d\n",L);
	if(C)printf("C %d\n",C);
	if(D)printf("D %d\n",D);
	if(M)printf("M %d\n",M);
}
int main(){
	input();
	solve();
	output();
}
