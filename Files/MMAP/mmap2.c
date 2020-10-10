#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>

int main(){
	//char *text = (char *)malloc(sizeof(char) * 20);
	int fileDescriptor = open("/Users/AlexVargas/Documents/ITESM/Quinto semestre/Operating Systems/Files/MMAP/example.txt", O_CREAT | O_RDWR);
	char *text = (char *)mmap(
		NULL, 
		sizeof(char)*20, 
		PROT_READ | PROT_WRITE,
		MAP_SHARED,
		fileDescriptor,
		0
	);
	strcpy(text, "hello");
	printf("Text from one process %s\n", text);
	munmap(text, sizeof(char)*20); //deoccupy the memory space
	close(fileDescriptor);
}