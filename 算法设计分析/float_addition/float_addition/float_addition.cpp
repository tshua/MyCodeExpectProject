// float_addition.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int main()
{ 
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	int n;
	cin>>n;
	while(n--)
	{
		int a_len,b_len,i,j,da,db,dalen=0,dblen=0;
		char a[110]={0},b[110]={0},a1[110]={0},b1[110]={0};
		cin>>a;
		cin>>b;
		//getchar();
		a_len = strlen(a);
		b_len = strlen(b);
		i = 0;
		while(a[i])
		{
			if(a[i]==46)
			{
				da = i;
				while(a[i])
				{
					dalen++;
					a[i] = a[i+1];
					i++;
				}
			}
			i++;	
		}
		i = 0;
		while(b[i])
		{
			if(b[i]==46)
			{
				db = i;
				while(b[i])
				{
					dblen++;
					b[i] = b[i+1];
					i++;
				}
			}
			i++;	
		}
		dalen--;
		dblen--;
		a_len--;
		b_len--;


		if(dalen<dblen)//补小数的0
		{
			int s = dblen - dalen;
			for(i = 0;i<s;i++)
			{
				a[a_len+i]='0';
			}
			a_len+=s;
			a[a_len] = 0;
		}
		else
		{
			int s = dalen - dblen;
			for(i = 0;i<s;i++)
			{
				b[b_len+i]='0';
			}
			b_len+=s;
			b[b_len]=0;
		}

		for(i = 0;i<a_len;i++)
		{
			a1[i] = a[a_len-i-1];
		}
		a1[a_len]=0;
		for(i = 0;i<b_len;i++)
		{
			b1[i] = b[b_len-i-1];
		}
		b1[b_len]=0;

		for(i = 0 ;i<a_len;i++)
			a1[i] -= 48;
		for(i = 0;i<b_len;i++)
			b1[i] -= 48;

		if(a_len>=b_len)
		{
			for(i = 0;i<b_len;i++)
			{
				a1[i] += b1[i];
				j = i;
				while(a1[j]>9)
				{
					a1[j] = a1[j]%10;
					j++;
					a1[j] += 1;
				}
			}

			for(i = 0;i<a_len;i++)
			{
				a1[i]+=48;
			}
			//cout<<a1;
			for(i = 0;i<a_len;i++)
			{
				a[i] = a1[a_len-i-1];
			}
			for(i = a_len-1;i>=0;i--)
			{
				if(a[i]=='0')
				{
					a[i]=0;

				}
				else
					break;
			}
			for(i = 0;i<a_len;i++)
			{
				int len = max(dalen,dblen);
				if(i==a_len-len&&a[i]!=0)
					cout<<'.';
				cout<<a[i];
				//if(a[i+1]==0)
					//break;
			}
			cout<<endl;
			
		}
		else
		{
			for(i = 0;i<b_len;i++)
			{
				b1[i] += a1[i];
				j = i;
				while(b1[j]>9)
				{
					b1[j] = b1[j]%10;
					j++;
					b1[j] += 1;
				}
			}
			for(i = 0;i<b_len;i++)
			{
				b1[i]+=48;
			}
			//cout<<b1<<endl;
			for(i = 0;i<b_len;i++)
			{
				b[i] = b1[b_len-i-1];
			}
			for(i = b_len-1;i>=0;i++)
			{
				if(b[i]=='0')
				{
					b[i]=0;
				}
				else
					break;
			}
			for(i = 0;i<b_len;i++)
			{
				int len = max(dalen,dblen);
				if(i==b_len-len&&b[i]!=0)
					cout<<'.';
				cout<<b[i];
				if(b[i+1]==0)
					break;
			}
			cout<<endl;
		}
		
		//cout<<a<<endl<<b<<endl;
		//cout<<a1<<endl;
		//cout<<b1<<endl;
		//cout<<dalen<<endl<<dblen;
	}
}