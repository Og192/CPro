#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<errno.h>
#include<dirent.h>
#include<limits.h>
#include<sys/stat.h>
char *path_alloc(int *);
typedef int Myfunc(const char *, const struct stat *,int);
static Myfunc myfunc;
static int myftw(char *, Myfunc *);
static int dopath(Myfunc *);

static long nerg, ndir, nblk, nchr, nfifo, nslink, nsock, ntot;

int main(int argc, char *argv[])
{
	int ret;
	if(argc != 2){
		printf("Usage: ftw <starting-pathname>\n");
		exit(EXIT_FAILURE);
	}

	ret = myftw(argv[1],myfunc);
	ntot = nerg + ndir + nblk + nchr + nfifo + nslink + nsock;
	if(ntot == 0)
		ntot = 1;

	printf("regular files	= %7ld, %5.2f %%\n", nerg, 
			nerg * 100.0/ntot);
	printf("directories	= %7ld, %5.2f %%\n", ndir,
			ndir * 100.0/ntot);
	printf("block special	= %7ld, %5.2f %%\n", nblk,
			nblk * 100.0/ntot);
	printf("char special	= %7ld, %5.2f %%\n", nchr,
			nchr * 100.0/ntot);
	printf("FIFOs 		= %7ls, %5.2f %%\n", nfifo,
			nfifo * 100.0/ntot);
	printf("symbolic links	= %7ld, %5.2f %%\n", nslink,
			nslink * 100.0/ntot);
	printf("sockets		= %7ld, %5.2f %%\n", nsock,
			nsock * 100.0/ntot);

	exit(EXIT_FAILURE);
}

#define FTW_F	1
#define FTW_D	2
#define FTW_DNR	3
#define FTW_NS	4
static char *fullpath;

static int myftw(char *pathname, Myfunc *func)
{
	int len;
	fullpath = path_alloc(&len);

	strncpy(fullpath,pathname,len);
	fullpath[len-1] = 0;

	return (dopath(func));
}

static int dopath(Myfunc *func)
{
	struct stat	statbuf;
	struct dirent	*dirp;
	DIR		*dp;
	int 		ret;
	char 		*ptr;

	if(lstat(fullpath, &statbuf) < 0)
		return (func(fullpath, &statbuf, FTW_NS));
	if(S_ISDIR(statbuf.st_mode) == 0)
		return (func(fullpath, &statbuf,FTW_F));

	if((ret = func(fullpath, &statbuf, FTW_D)) != 0)
		return (ret);

	ptr = fullpath + strlen(fullpath);
	*ptr++='/';
	*ptr = 0;

	if((dp = opendir(fullpath)) == NULL)
		return (func(fullpath, &statbuf,FTW_DNR));

	while((dirp = readdir(dp)) != NULL){
		if(strcmp(dirp->d_name, ".") == 0 || 
		   strcmp(dirp->d_name, "..") == 0)
			continue;

		strcpy(ptr,dirp->d_name);

		if((ret = dopath(func)) != 0)
			break;
	}

	ptr[-1] = 0;
	if(closedir(dp) < 0){
		perror("can't close directory ");
		exit(EXIT_FAILURE);
	}

	return (ret);
}

static int myfunc(const char *pathname, const struct stat *statptr, int type)
{
	switch(type){
		case FTW_F:
			switch(statptr->st_mode & S_IFMT){
				case S_IFREG: nerg++; break;
				case S_IFBLK: nblk++; break;
				case S_IFCHR: nchr++; break;
				case S_IFIFO: nfifo++;break;
				case S_IFLNK: nslink++;break;
				case S_IFSOCK:nsock++; break;
				case S_IFDIR:
					      printf("for S_IFDOR for %s",pathname);
			}
			break;
		case FTW_D:
			ndir++;
			break;
		case FTW_DNR:
			printf("can't read directory %s",pathname);
			break;
		case FTW_NS:
			printf("stat error for %s",pathname);
			break;
		default:
			printf("unknow type %d for pathname %s", type, pathname);
	}

	return (0);
}
