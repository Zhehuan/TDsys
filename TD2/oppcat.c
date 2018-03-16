#include "header.h"

int main(int ac, char **av){
	int fd, nread;
	fd = open(av[1], O_RDWR|O_CREAT, 0775);
	char *buf = malloc(1024);
	while((nread = read(0, buf, sizeof(buf))) > 0){
		write(fd, buf, nread);
	}
	close(fd);
}
