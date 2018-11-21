/*
ID: dd.ener1
PROG: ride
LANG: C++
*/
#include <fstream>
#include <string>

using namespace std;
inline long calc(char c){
	return c-'A'+1;
}
inline long calc(string s){
	long res=1,len=s.length();
	for(long i=0;i<len;++i){
		res*=calc(s[i]);
		res%=47;
	}
	return res;
}
int main(){
	ifstream cin("ride.in");
	string s1,s2;
	cin>>s1>>s2;
	ofstream cout("ride.out");
	if(calc(s1)==calc(s2))cout<<"GO"<<endl;
	else cout<<"STAY"<<endl;
	return 0;
}
