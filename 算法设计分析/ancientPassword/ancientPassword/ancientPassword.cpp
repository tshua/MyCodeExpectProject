// ancientPassword.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <string>
#include <iostream>
using namespace std;
int searchs1(char a,string &s1,int offset,bool* b)
{
	int i,offset1;
	for(i = 0;i<s1.length();i++)
	{
		if(s1[i]>a)
			offset1 = s1[i] - a;
		else
			offset1 =  s1[i] - a + 26;
		if(offset1==offset&&!b[i])
		{
			b[i] = true;
			return i;
		}
	}
	return i;
}

int _tmain(int argc, _TCHAR* argv[])
{
	string s1,s2;
	int offset;
	cin>>s1;
	cin>>s2;
	bool* b = new bool[s1.length()];

	for(int i = 0;i<s1.length();i++)
	{
		for(int k=0;k<s1.length();k++)
			b[k] = false;
		if(s2[0]<s1[i])
			offset = s1[i] - s2[0];
		else
			offset = s1[i] - s2[0] + 26;
		b[i] = true;
		int j;
		for(j = 1;j<s2.length();j++)
		{
			if(searchs1(s2[j],s1,offset,b)==s1.length())
				break;
		}
		if(j==s1.length())
		{
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;

	return 0;
}

