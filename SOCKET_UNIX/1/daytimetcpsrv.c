#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<time.h>
#include<sys/types.h>
#define MAXLINE 4096
#define LISTENQ 1024
int Socket(int family, int type, int portocol)
{
	int n;
	if((n = socket(family, type, portocol)) < 0){
		perror("socket");
		exit(EXIT_FAILURE);
	}

	return (n);
}

void Bind(int listenfd, struct sockaddr *servaddr, int size_servaddr)
{
	if(bind(listenfd, servaddr, size_servaddr) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

void Listen(int listenfd, int listenq)
{
	if(listen(listenfd, listenq) < 0){
		perror("listen");
		exit(EXIT_FAILURE);
	}
}

int Accept(int listenfd, struct sockaddr *servaddr, socklen_t *len)
{
	int connfd;
	if((connfd = accept(listenfd, servaddr, len)) < 0){
		perror("sccept");
		exit(EXIT_FAILURE);
	}

	return (connfd);
}

void Write(int connfd, char *buff, int size_buff)
{
	if(write(connfd, buff, size_buff) < 0){
		perror("write");
		exit(EXIT_FAILURE);
	}
}

void Close(int connfd)
{
	if(close(connfd) < 0){
		perror("close");
		exit(EXIT_FAILURE);
	}
}

int main(void)
{
	int listenfd, connfd;
	struct sockaddr_in servaddr;
	char buff[MAXLINE];
	time_t ticks;

	/* create the socket */
	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	/* clear the address struct */
	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;/* set the family */
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);/* receive all address client */
	servaddr.sin_port = htons(3333);	/* set the portnumber */

	/* bind the sockfd snd the address */
	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
	/* listening the client */
	Listen(listenfd, LISTENQ);
	/* accept the client */
	for(;;){
		/* if there is a client?Yes, then accept the client */
		connfd = Accept(listenfd, (struct sockaddr *)NULL, NULL);

		/* get system time */
		ticks = time(NULL);

		/* get the chararcters of system tiem */
		snprintf(buff,sizeof(buff), "%.24s\r\n", ctime(&ticks));
		/* write the connfd */
		Write(connfd, buff, strlen(buff));
		Close(connfd);
	}
}
