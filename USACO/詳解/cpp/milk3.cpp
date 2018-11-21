/*
ID: dd.ener1
PROG: milk3
LANG: C++
*/
#include <fstream>
using namespace std;

long A,B,C;
bool v[21][21];//v[b][c]表示桶B为b，桶C为c的情况是否可以得到（桶A就不用说了，呵呵） 

void input(){
	ifstream cin("milk3.in");
	cin>>A>>B>>C;
	memset(v,false,sizeof(v));
}
inline long min(long a,long b){
	return a<b?a:b;
}
void search(long b,long c){
	if(v[b][c])return;
	v[b][c]=true;
	long a=C-b-c,delta;
	//A->B
	delta=min(a,B-b);
	if(delta)search(b+delta,c);
	//B->A
	delta=min(b,A-a);
	if(delta)search(b-delta,c);
	//B->C
	delta=min(b,C-c);
	if(delta)search(b-delta,c+delta);
	//C->B
	delta=min(c,B-b);
	if(delta)search(b+delta,c-delta);
	//A->C
	delta=min(a,C-c);
	if(delta)search(b,c+delta);
	//C->A
	delta=min(c,A-a);
	if(delta)search(b,c-delta);
}
void output(){
	ofstream cout("milk3.out");
	bool first=true;
	for(long c=0;c<=C;++c)
		if(v[C-c][c]){
			if(first)cout<<c;
			else cout<<' '<<c;
			first=false;
		}
	cout<<endl;
}
int main(){
	input();
	search(0,C);
	output();
	return 0;
}
