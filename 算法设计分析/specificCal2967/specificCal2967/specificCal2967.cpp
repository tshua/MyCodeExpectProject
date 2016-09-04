// specificCal2967.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

bool isRunYear(int year)
{

    if((year%4==0&&year%100!=0)||year%400==0)  
        return true;  
    else  
        return false;

}
int calculateDay(int day,int month,int year)
{
	int count = 0;
	int dayofmonth[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

	for(int i=2000;i<year;i++)
	{
		if(isRunYear(i))
			count += 366;
		else
			count += 365;
	}
	if(isRunYear(year))
		dayofmonth[1] = 29;
	for(int i = 0;i<month-1;i++)
	{
		count += dayofmonth[i];
	}
	count+=day-1;
	return count;
}
int _tmain(int argc, _TCHAR* argv[])
{
	int n,hour,minute,second,day,month,year,mhour,mminute,msecond,mday,mmonth,myear,days;
	cin>>n;
	while(n--)
	{
		scanf("%d:%d:%d %d.%d.%d",&hour,&minute,&second,&day,&month,&year); 
		//cout<<hour<<":"<<minute<<":"<<second<<" "<<day<<"."<<month<<"."<<year<<endl;
		//cout<<calculateDay(day,month,year);
		days = calculateDay(day,month,year);
		myear =  days/1000;
		days -=myear*1000;
		mmonth = days/100+1;
		days -= (mmonth-1)*100;
		mday = days+1;
		
		cout<<mday<<"  "<<mmonth<<" "<<myear<<endl;

	}
	


	return 0;
}

