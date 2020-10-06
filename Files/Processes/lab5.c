#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

//TERMINATED PROCESS
//Process which has completed execution and was waited on by its parent
int main(){
    pid_t p = fork();
    if(p == 0){
        printf("I'm the child, with PID: %d\n",getpid());
        printf("My parent's PID: %d\n",getppid());
    }else{
        wait(NULL); //Wait until its child process is finished
        sleep(5); //give us time to run the ps
        printf("I'm the parent, with PID: %d\n", getpid());
        printf("My child's PID: %d\n",p);
    }
    return 0;
}