/*
ID: dd.ener1
PROG: lamps
LANG: C++
*/
#include <cstdio>
#include <cstring>
using namespace std;

const long max=0100;//0b1000000
long N,C;
long light,dark;
bool last[max];
const long bits[]={0x20,0x10,0x8,0x4,0x2,0x1};

void input(){
	freopen("lamps.in","r",stdin);
	scanf("%d%d",&N,&C);
	light=dark=0;
	for(;;){
		long a;
		scanf("%d",&a);
		if(a==-1)break;
		light|=bits[(a-1)%6];
	}
	for(;;){
		long a;
		scanf("%d",&a);
		if(a==-1)break;
		dark|=bits[(a-1)%6];
	}
	if(C>4)
		C=4-C%2;
	memset(last,0,sizeof(last));
}
void solve(long now,long step){
	if(step==C){
		if(!last[now]&&(0==(now&dark))&&(0==~(now|~light)))last[now]=true;
		return;
	}
	solve(now^63/*0b111111*/,step+1);
	solve(now^42/*0b101010*/,step+1);
	solve(now^21/*0b010101*/,step+1);
	solve(now^36/*0b100100*/,step+1);
}
void output(){
	freopen("lamps.out","w",stdout);
	bool outed=false;
	for(long i=0;i<max;++i)
		if(last[i]){
			outed=true;
			for(long j=0;j<N;++j)
				putchar(i&(bits[j%6])?'1':'0');
			putchar('\n');
		}
	if(!outed)puts("IMPOSSIBLE");
}
int main(){
	input();
	solve(63/*0b111111*/,0);
	output();
	return 0;
}
