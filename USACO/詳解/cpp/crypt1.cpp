/*
ID: dd.ener1
PROG: crypt1
LANG: C++
*/
#undef DEBUG
#include <fstream>
using namespace std;

/*
      A B C -->x
   x    D E -->y
    -------
      * * *
    * * *
    -------
    * * * *
*/
#ifdef DEBUG
ofstream clog("crypt1.log");
#endif
bool allow[10];
inline bool valid(long num){
	if(num==0)return allow[0];
	while(num!=0){
		if(!allow[num%10])return false;
		num/=10;
	}
	return true;
}
inline long digits(long num){
	if(num==0)return 1;
	long res=0;
	while(num!=0){
		num/=10;
		++res;
	}
	return res;
}
int main(){
	{
		memset(allow,false,sizeof(allow));
		ifstream cin("crypt1.in");
		long n;
		cin>>n;
		do{
			long i;
			cin>>i;
			allow[i]=true;
		}while(--n);
	}
	long res=0;
	for(long A=1;A<10;++A){
		if(!allow[A])continue;
		for(long B=0;B<10;++B){
			if(!allow[B])continue;
			for(long C=0;C<10;++C){
				if(!allow[C])continue;
				long x=A*100+B*10+C;
				for(long D=1;D<10;++D){
					if(!allow[D])continue;
					if(digits(x*D)!=3)continue;
					if(!valid(x*D))continue;
					for(long E=0;E<10;++E){
						if(!allow[E])continue;
						if(digits(x*E)!=3)continue;
						if(!valid(x*E))continue;
						long y=D*10+E;
						if(digits(x*y)!=4)continue;
						if(!valid(x*y))continue;
						++res;
						#ifdef DEBUG
						clog<<"  "<<x<<endl;
						clog<<" x "<<y<<endl;
						clog<<"-----"<<endl;
						clog<<" "<<x*E<<endl;
						clog<<" "<<x*D<<' '<<endl;
						clog<<"-----"<<endl;
						clog<<" "<<x*y<<endl;
						clog<<endl;
						#endif
					}
				}
			}
		}
	}
	ofstream cout("crypt1.out");
	cout<<res<<endl;
}
