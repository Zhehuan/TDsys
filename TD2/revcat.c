#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#define BUFFER 1024

int main(int ac, char* av[]){
	int fd1 = open(av[1], O_RDONLY, 0775);
	int fd2 = open(av[2], O_WRONLY|O_CREAT, 0775);
	char* buf = malloc(1);
	if(fd1 == -1){
		perror(av[1]);
		return 0;
	}
	int count = lseek(fd1,0,SEEK_END);
	for(int i = 2; i < count; i++){
		if(lseek(fd1, -i, SEEK_END)){
			read(fd1, buf, 1);
			write(fd2, buf, 1);
		}
	}
	close(fd1);
	close(fd2);
	return EXIT_SUCCESS;
}
