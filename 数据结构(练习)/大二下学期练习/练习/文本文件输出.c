#include<stdio.h>
#include<stdlib.h>
int main()
{
	FILE *p;char ch;
	p=fopen("d://filetest.txt","r");//·������ʽ 
	//ch=fgetc(p);
	while(ch!=EOF) 
	{ 
		 
		ch=fgetc(p);
		putchar(ch); 
	} 
	fclose(p);
 } 