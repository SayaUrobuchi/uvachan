/*
ID: dd.ener1
PROG: friday
LANG: C++
*/

#include <fstream>
using namespace std;

long NowYear,NowMonth,NowDay;

inline bool isLeapYear(){
	if(!(NowYear%100))return !(NowYear%400);
	return !(NowYear%4);
}
inline bool incDay(){
	++NowDay;
	switch(NowMonth){
		case 2:
			if(NowDay==30)
				return true;
			if(NowDay==29)
				if(!isLeapYear())return true;
			break;
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(NowDay==32)return true;
			break;
		default:
			if(NowDay==31)return true;
	}
	return false;
}
inline bool incMonth(){
	NowDay=1;
	++NowMonth;
	return NowMonth==13;
}
inline void incYear(){
	NowMonth=1;
	++NowYear;
}
inline void getNextDay(){
	if(incDay())
		if(incMonth())
			incYear();
}	
int main(){
	long last;
	{
		ifstream cin("friday.in");
		cin>>last;
	}
	last+=1900;
	NowYear=1900;
	NowMonth=1;
	NowDay=1;
	long Day=0;
	long res[7];
	for(long i=0;i<7;++i)res[i]=0;
	#ifdef DEBUG
	ofstream clog("friday.log");
	#endif
	do{
		#ifdef DEBUG
		clog<<NowYear<<'-'<<NowMonth<<'-'<<NowDay<<endl;
		#endif
		if(NowDay==13)++res[Day];
		++Day;
		Day%=7;
		getNextDay();
	}while(NowYear!=last);
	{
		ofstream cout("friday.out");
		cout<<res[5]<<' '<<res[6]<<' '<<res[0]<<' '<<res[1]<<' '<<res[2]<<' '<<res[3]<<' '<<res[4]<<endl;
	}
	return 0;
}
