#include<stdio.h>

int main(void)
{
char buf[128]={0}; 
	FILE *fp=fopen("a.txt","r");
	while (0!=fread(buf,1,127,fp))
{
	printf("%s",buf);
	memset(buf,0,128);
}
	fclose(fp);
	return 0;
}
