#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    mkfifo("/Users/AlexVargas/Documents/ITESM/Quinto semestre/Operating Systems/Files/pipe.txt", O_CREAT | 0666);
    int f = open("/Users/AlexVargas/Documents/ITESM/Quinto semestre/Operating Systems/Files/pipe.txt", O_WRONLY);
    char *buffer = "hello";
    write(f, buffer, strlen(buffer) + 1);
    close(f);
}