#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

//ONLY WRITING SIDE

int main()
{
	mkfifo("pipe.txt", O_CREAT | 0666);
	int f = open("pipe.txt", O_WRONLY);
	char *buffer = (char *)malloc(100);
	printf("Name of the patient: ");
	scanf("%[^\n]s", buffer);
	write(f, buffer, strlen(buffer) + 1);
	close(f);
}