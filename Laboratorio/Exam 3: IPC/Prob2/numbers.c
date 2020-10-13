#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>
#include <sys/wait.h>
#include <time.h>
#include <fcntl.h>
#include <sys/mman.h>

#define READ 0
#define WRITE 1

int main()
{
	srand(time(NULL));
	truncate("numbers.txt", 0);
	int fileDescriptor = open("numbers.txt", O_RDWR | O_CREAT, 0666);
	ftruncate(fileDescriptor, sizeof(char) * 20);
	char *text = (char *)mmap(NULL, sizeof(char) * 20, PROT_READ | PROT_WRITE, MAP_SHARED, fileDescriptor, 0);
	pid_t child = fork();

	if (child == 0)
	{
		int num1 = rand() % 50;
		int num2 = rand() % 50;
		int num3 = rand() % 50;
		int num4 = rand() % 50;
		int num5 = rand() % 50;
		char str[100];
		sprintf(str, "%d, %d, %d, %d, %d\n", num1, num2, num3, num4, num5);
		strncat(text, str, sizeof(char) * 100);
		munmap(text, sizeof(char) * 100);
		close(fileDescriptor);
	}
	else
	{
		wait(NULL);
		printf("The numbers are %s", text);
	}
	return 0;
}