// calaulate24.cpp : 定义控制台应用程序的入口点。
//
#include "stdafx.h"
#include <iostream>
#include <cmath>
using namespace std;

int ans=0;//全局变量

void dfs(double a[],int n)
{
	int i,j,x,y,k,m;
	double b[4];
	if(n==1&&a[0]>0&&fabs(a[0]-24)<0.0001)
		ans=1;
	else if(n>1)
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				if(i==j)
					continue;
				for(m=k=0;k<n;k++)
					if(k!=i&&k!=j)
					{ 
						b[m]=a[k];
						m++;
					}
					b[m]=a[i]+a[j]; 
					dfs(b,m+1);
					b[m]=a[i]-a[j]; 
					dfs(b,m+1);
					b[m]=a[i]*a[j];
					dfs(b,m+1);
					if(a[j]!=0)b[m]=a[i]/a[j]; 
					dfs(b,m+1);
			}
		}
}
int main(int argc, char *argv[])
{
	double a[4];
	//freopen("24.txt","w",stdout);
	while(cin>>a[0]>>a[1]>>a[2]>>a[3]&&(a[0]+a[1]+a[2]+a[3])!=0)
	{
		ans=0;
		dfs(a,4);
		if(ans)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
