// qsort.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


// crt_qsort.c
// arguments: every good boy deserves favor

/* This program reads the command-line
* parameters and uses qsort to sort them. It
* then displays the sorted arguments.
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>



int compare( const void *arg1, const void *arg2 );
int mysort(void* arr,size_t width,size_t num, int (_cdecl *compare)(const void *,const void *));
int main()
{ 
	int a[5]={8,2,7,9,-1};
	/* Eliminate argv[0] from sort: */


	/* Sort remaining args using Quicksort algorithm: */
	qsort( (void *)a, (size_t)5, sizeof(int), compare );

	/* Output sorted list: */
	for(int i = 0; i < 5; ++i )
		printf( " %d", a[i] );
	//FILE* stream = fopen("test.txt","w");
	//fwrite(a,sizeof(int),5,stream);
	//fclose(stream);
	//int a[5];
	//FILE* stream=fopen("test.txt","r");
	//int num = fread(a,sizeof(int),5,stream);
	//for(int i = 0;i<num;i++){
	//	printf( " %d", a[i] );

	//}

}
int mysort(void* arr,size_t width,size_t num,int (_cdecl *compare)(const void *,const void *))
{
	int iarr = (unsigned int)arr;
	for(int i = 0;i<num-1;i++)
	{
		for(int j=i;j<num;j++)
		{
			if(compare((void*)(iarr+j*width),(void*)(iarr+(j+1)*width))>0)
			{
				for(int k = 0;k<width;k++)
				{	
					char temp = *((char*)(iarr+k));
					*((char*)(iarr+k)) = *((char*)(iarr+k+width));
					*((char*)(iarr+k+width)) = temp;
				}
			}
		}

	}
	return 1;
}
int compare( const void *arg1, const void *arg2 )
{
	/* Compare all of both strings: */
	return (*(int*)arg1-*(int*)arg2);
}
