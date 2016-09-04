// shugen2764.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

void add(char* m_num,int& num_len)
{
	int k = 0,newnum_len = 0;
	char numtemp[1001]={0};
	for(int i = 0;i<num_len;i++)
	{
		numtemp[0] = numtemp[0] + m_num[i]-48;
		k = 0;
		while(numtemp[k]>9)
		{
			numtemp[k++] = numtemp[k]%10;
			numtemp[k] += 1;
			if(newnum_len < k)
				newnum_len = k;
		}
	}
	memcpy(m_num, numtemp, newnum_len+2);
	num_len = newnum_len+1;
}


int _tmain(int argc, _TCHAR* argv[])
{

	char m_num[1001]={0};
	cin>>m_num;
	int num_len = 0;//记录加之前的长度
	int newnum_len = 0;//记录加完后的长度

	while(m_num[0]-48!=0)
	{
		 num_len = strlen(m_num);
		//cout<<m_num<<endl;

		while(num_len!=1)
		{
			add(m_num,num_len);

			for(int i = 0;i < num_len;i++)
			{
				m_num[i]+=48;
			}
		}
		cout<<m_num<<endl;	
		cin>>m_num;
	}
	//cout<<m_num;
	return 0;
}

