#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

#define MAX_SIZE 2048

int main(int argc,char *argv[])
{
	int in_fd;
	int cut_fd;
	int chars;
	char buf[MAX_SIZE]={0};
	if(argc!=3)
	{
		printf("please input a!\n");
		exit(1);
	}
	in_fd=open(argv[1],O_RDONLY);
	if(in_fd==-1)
	{
		printf("open file error!\n");
		exit(1);
	}

	out_fd=creat(argv[2],0644);
	if(out_fd==-1)
	{
		printf("create file error!\n");
		exit(1);
	}

	chars=read(in_fd,buf,MAX_SIZE);
	if(chars==-1)
	{
		printf("read file error!\n");
		exit(1);

	}

	if(write(out_fd,buf,chars)!=chars)
	{
		printf("write file error!\n");
		exit(1);
	}

	close(in_fd);
	close(out_fd);
	return 0;


}
