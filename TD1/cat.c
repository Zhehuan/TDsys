#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int ac, char **av){
	int fd, nread;
	fd = open(av[1], O_RDONLY);
	if(fd == -1){
		perror(av[1]);
		return 0;
	}
	char *buf = malloc(1024);
	while((nread = read(fd, buf, sizeof(buf))) > 0){
		write(1, buf, nread);
	}
	close(fd);
}
