// diannostic.cpp : 定义控制台应用程序的入口点。
//
#include <stdafx.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{
	double b,h;
	int k,xd,xb,xx,count=0;
	string sex;
	cin>>k;
	while(k>0)
	{
		k--;
		count=0;
		cin>>sex>>b>>h>>xd>>xb>>xx;
		if(b<4||b>10)
			count++;
		if(h<3.5||h>5.5)
			count++;
		if(sex=="male"&&(xd<120||xd>160))
			count++;
		if(sex=="female"&&(xd<110||xd>150))
			count++;
		if(sex=="male"&&(xb<42||xb>48))
			count++;
		if(sex=="female"&&(xb<36||xb>40))
			count++;
		if(xx<100||xx>300)
			count++;

		if(count==0)
			cout<<"normal"<<endl;
		else
			cout<<count<<endl;
	}
	return 0;
}
