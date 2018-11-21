/*
ID: dd.ener1
PROG: clocks
LANG: C++
*/
#undef DEBUG
#include <fstream>
using namespace std;
long ori[9];
long best[9],best_steps;
long now[9],now_steps;
#ifdef DEBUG
ofstream clog("clocks.log");
#endif

void input(){
/*
12 --> 0
3  --> 1
6  --> 2
9  --> 3
*/
	ifstream cin("clocks.in");
	for(long i=0;i<9;++i){
		long a;
		cin>>a;
		switch(a){
			case 3:
				ori[i]=1;
				break;
			case 6:
				ori[i]=2;
				break;
			case 9:
				ori[i]=3;
				break;
			case 12:
				ori[i]=0;
				break;
		}
	}
}
void init(){
	memset(best,-1,sizeof(best));
	memset(now,0,sizeof(now));
	best_steps=100000000;
	now_steps=0;
}
inline bool better(){
	if(now_steps<best_steps)return true;
	if(now_steps>best_steps)return false;
	for(long i=0;i<9;++i){
		if(now[i]>best[i])return true;
		if(now[i]<best[i])return false;
	}
	return false;
}
inline void fillnew(){
	best_steps=now_steps;
	for(long i=0;i<9;++i)best[i]=now[i];
}
inline bool valid(){
	if((ori[0]+now[0]+now[1]+now[3])%4)return false;//A 013
	if((ori[1]+now[0]+now[1]+now[2]+now[4])%4)return false;//B 0124
	if((ori[2]+now[1]+now[2]+now[5])%4)return false;//C 125
	if((ori[3]+now[0]+now[3]+now[4]+now[6])%4)return false;//D 0346
	if((ori[4]+now[0]+now[2]+now[4]+now[6]+now[8])%4)return false;//E 02468
	if((ori[5]+now[2]+now[4]+now[5]+now[8])%4)return false;//F 2458
	if((ori[6]+now[3]+now[6]+now[7])%4)return false;//G 367
	if((ori[7]+now[4]+now[6]+now[7]+now[8])%4)return false;//H 4678
	if((ori[8]+now[5]+now[7]+now[8])%4)return false;//I 578
	#ifdef DEBUG
	clog<<"Valid:";
	for(long i=0;i<9;++i)clog<<now[i]<<' ';
	clog<<endl;
	#endif
	return true;
}
void search(long i){
	if(valid()&&better()){
		fillnew();
		return;
	}
	if(i==9)return;
	for(now[i]=0;now[i]<4;++now[i]){
		now_steps+=now[i];
		search(i+1);
		now_steps-=now[i];
	}
	now[i]=0;
}
void output(){
	bool firstwrite=true;
	ofstream cout("clocks.out");
	for(long i=0;i<9;++i)
		for(long j=0;j<best[i];++j){
			if(firstwrite){
				cout<<i+1;
				firstwrite=false;
			}
			else cout<<' '<<i+1;
		}
	cout<<endl;
}
int main(){
	input();
	init();
	search(0);
	output();
}
