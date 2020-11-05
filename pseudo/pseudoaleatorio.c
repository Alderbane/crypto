#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc!=3){
		printf("Favor de introducir 2 parametros\n");
		printf("random/random #bytes");
		return -1;
	}
	unsigned char * buf;
	char * type = argv[1];
	int size = atoi(argv[2]);
	buf = malloc(size);
	if(!strcmp(type, "urandom")){
		int fd = open("/dev/urandom", O_RDONLY);
		read(fd, buf, size);
		close(fd);

	}
	else if(!strcmp(type, "random")){
		int fd = open("/dev/urandom", O_RDONLY);
		read(fd, buf, size);
		close(fd);
	}
	else {
		printf("introducir tipo valido\n");
		printf("random/random #bytes");
		return -1;
	}
	int i;
	for(i=0; i<size; i++)
		printf("%02X", buf[i]);
	printf("\n");
}
