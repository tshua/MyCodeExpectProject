#include <stdlib.h>
#include <iostream>
using namespace std;
int main()

{
	FILE* inputfile = fopen("inputfile","r");
	FILE* resultfile = fopen("resultfile","w");
	int a = 0;
	int num = fread(&a,sizeof(char),1,inputfile);//注意这里，文件中采用ansi编码存的数字是一个字节，所以sizeof(char),逐个字节复制。
	while(num>0)
	{
		fwrite(&a,sizeof(char),1,resultfile);
		num = fread(&a,sizeof(char),1,inputfile);
		cout<<num<<"  ";
	}
	if(feof(inputfile)==0)
		cout<<"读取错误"<<endl;
	else
	{
		fclose(inputfile);
		fclose(resultfile);
		cout<<"ok"<<endl;
	}
	
}