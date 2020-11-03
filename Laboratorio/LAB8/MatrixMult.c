/*
Alex Vargas A00824525
Cesar Martinez A00517067
*/

#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

#define M 3
#define N 3
#define O 3

int A[M][O] = {{1,2,3}, {4,5,6}, {7,8,9}};
int B[O][N] = {{1,1,1}, {1,1,1}, {1,1,1}};
int C[M][N] = {{0,0,0}, {0,0,0}, {0,0,0}};

void printResultado(){
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            printf("%d, ", C[i][j]);
        }
        printf("\n");
    }
}

struct arguments{
    int i;
    int j;
};

void *Multip(void *args){
    int iFila =((struct arguments *)args)->i;
    int jCol =((struct arguments *)args)->j;
    
   
    for (int k=0;k<O;k++){
        C[iFila][jCol] += A[iFila][k]*B[k][jCol];
    }

    free(args);
}
    
    
int main(){
    pthread_t tids[M][N];
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            struct arguments *args = (struct arguments *)malloc(sizeof(struct arguments));
            args->i=i;
            args->j=j;
            pthread_create(&tids[i][j], NULL, Multip,(void *)args);
        }
    }
    
    for (int i=0;i<M;i++){
        for (int j=0;j<N;j++){
            pthread_join(tids[i][j], NULL);
        }
    }

    printResultado();

}