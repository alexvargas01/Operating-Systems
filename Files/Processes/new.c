#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(){
    pid_t own=getpid();
    pid_t parent=getppid();
    printf("My process id is %d, and my parents id is %d\n", own, parent);
    getchar();
    return 0;
}