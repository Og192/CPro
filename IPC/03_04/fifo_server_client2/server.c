#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>

#define MAXLINE 1024

void server(int readfd, int writefd)
{
	int filefd; 
	int n;
	char buff[MAXLINE];

	if((n = read(readfd, buff, MAXLINE)) < 0){
		perror("read");
		exit(EXIT_FAILURE);
	}
	buff[n] = 0;

	if((filefd = open(buff, O_RDONLY, 0)) < 0){
		perror("open");
		exit(EXIT_FAILURE);
	}

	while((n = read(filefd, buff, MAXLINE)) > 0){
		write(writefd, buff, n);
	}

	if(close(filefd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}

	exit(EXIT_SUCCESS);
}
