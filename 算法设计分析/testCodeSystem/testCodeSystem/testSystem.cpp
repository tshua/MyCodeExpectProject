#include <stdlib.h>
#include <iostream>
using namespace std;
int main()

{
	FILE* inputfile = fopen("inputfile","r");
	FILE* resultfile = fopen("resultfile","w");
	int a = 0;
	int num = fread(&a,sizeof(char),1,inputfile);
	while(num>0)
	{
		fwrite(&a,sizeof(char),1,resultfile);
		num = fread(&a,sizeof(char),1,inputfile);
		cout<<num<<"  ";
	}
	if(feof(inputfile)==0)
		cout<<"¶ÁÈ¡´íÎó"<<endl;
	else
	{
		fclose(inputfile);
		fclose(resultfile);
		cout<<"ok"<<endl;
	}
	
}