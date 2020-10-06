#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
 mkfifo("/Users/AlexVargas/Documents/ITESM/Quinto semestre/Operating Systems/Files/pipe.txt", O_CREAT | 0666);
 int f = open("/Users/AlexVargas/Documents/ITESM/Quinto semestre/Operating Systems/Files/pipe.txt", O_RDONLY);
 char *buffer=(char *)malloc(100);
 read(f, buffer, 100);
 printf("Received from the pipe: %s\n", buffer);
 close(f);
}
