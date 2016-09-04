// 8to10_2735.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <stdlib.h>
#include <cmath>
#include <string>
#include <iostream>
using namespace std;

int main ()
{
	string s;int n=0,i=0,temp;char* a;
	cin>>s;
	a = &s[0];
	for(;i<s.length();i++)
	{
		if(i==0)
			temp = atoi(a+(s.length()-i-1));
		else
			temp = atoi(a+(s.length()-i-1))/static_cast<int>(pow(static_cast<double>(10),i));
		n+=temp*pow(static_cast<double>(8),i);
		//cout<<temp<<"  "<<pow(static_cast<double>(10),i)<<endl;
	}
	cout<<n;
	return 0;
}
