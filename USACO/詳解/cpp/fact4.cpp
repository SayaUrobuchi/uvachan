/*
ID: dd.ener1
PROG: fact4
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
	freopen("fact4.in","r",stdin);
	long N;
	scanf("%d",&N);
	long twofive=0;
	long res=1;
	for(long i=1;i<=N;++i){
		long k=i;
		while(!(k%2)){
			k/=2;
			++twofive;
		}
		while(!(k%5)){
			k/=5;
			--twofive;
		}
		res*=k;
		res%=10;
	}
	if(twofive)
	switch(twofive%=4){
		case 0:
			res*=6;
			break;
		case 1:
			res*=2;
			break;
		case 2:
			res*=4;
			break;
		case 3:
			res*=8;
			break;
	}
	res%=10;
	freopen("fact4.out","w",stdout);
	printf("%d\n",res);
}
