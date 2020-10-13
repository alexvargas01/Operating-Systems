#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//ONLY READING SIDE

int main()
{
	mkfifo("pipe.txt", O_CREAT | 0666);
	char *buffer = (char *)malloc(100);
	while (1)
	{
		int f = open("pipe.txt", O_RDONLY);
		read(f, buffer, 100);
		printf("Ingress: %s\n", buffer);
		close(f);
	}
}