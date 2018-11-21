/*
ID: dd.ener1
PROG: milk2
LANG: C++
*/
#undef DEBUG
#include <fstream>
#include <cstring>
using namespace std;

bool s[1100000];
int main(){
	memset(s,false,sizeof(s));
	ifstream cin("milk2.in");
	long n,small=1100000,big=-1;
	cin>>n;
	do{
		long beg,end;
		cin>>beg>>end;
		memset(s+beg-1,-1,sizeof(bool)*(end-beg));
		if(end>big)big=end;
		if(beg<small)small=beg;
	}while(--n);
	long max_t=0,max_f=0;
	#ifdef DEBUG
	ofstream clog("milk2.log");
	#endif
	for(long i=small-1,f=0,t=0;i<big-1;++i){
		#ifdef DEBUG
		clog<<i<<' '<<s[i]<<endl;
		#endif
		if(s[i]){
			++t;
			f=0;
		}
		else{
			++f;
			t=0;
		}
		if(f>max_f){
			max_f=f;
			#ifdef DEBUG
			clog<<"updated max_f="<<max_f<<endl;
			#endif
		}
		if(t>max_t){
			max_t=t;
			#ifdef DEBUG
			clog<<"updated max_t="<<max_t<<endl;
			#endif
		}
	}
	ofstream cout("milk2.out");
	cout<<max_t<<' '<<max_f<<endl;
	return 0;
}
