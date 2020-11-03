#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void *function(void *arg){
    int value =*(int*)arg;
    printf("Hello from function %d\n", value);
}
    
int main(){
    printf("Hello from main\n");
    int a = 1;
    int *b =(int *)malloc(sizeof(int));
    *b = 2;
    pthread_t tid1, tid2;
    pthread_create(&tid1, NULL, function,(void *)&a);
    pthread_create(&tid2, NULL, function,(void *)b);
    pthread_join(tid1, NULL);
     pthread_join(tid2, NULL);
    
    /*
    int pthread_create(//function to create
        pthread_t *thread,//thread id
        const pthread_attr_t *attr,//attributes of the thread
        void*(*start_routine)(void*),//function
        void *arg)//arguments of the function
    */
    
    return 0;
}