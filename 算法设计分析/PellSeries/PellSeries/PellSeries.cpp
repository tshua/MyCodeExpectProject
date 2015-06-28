// PellSeries.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int* Pell()
{
	int* arr_pell = new int[1000000];
	arr_pell[0] = 1;
	arr_pell[1] = 2;
	for(long i = 2; i < 1000000; ++i) arr_pell[i] = (2 * arr_pell[i - 1] + arr_pell[i - 2]) % 32767;
	return arr_pell;

}
int _tmain(int argc, _TCHAR* argv[])
{
	long n,k;
	cin>>n;
	int* result = Pell();
	while(n--)
	{
		cin>>k;
		cout<<result[k-1]<<endl;
	}
	return 0;
}

