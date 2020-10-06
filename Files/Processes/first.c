//Alex Vargas   A00824525
//Cesar Martinez A00517067

#include <stdio.h>
#include <stdlib.h>

//3.- Function
int function(int a){
    int b=10;
    int *c=&b;
    
    printf("%d\n", *c);
    c--;
    printf("%d\n", *c);
    c--;
    printf("%d\n", *c);
}

int main(){

    int a=5;
    double b = 12;
    char c = 'z';
    
    int *pa = &a;
    double *pb = &b;
    char *pc = &c;
    
    
    //1.- Variables
    printf("Content: %d, Address: %p, Size: %ld\n", a, &a, sizeof(a));
    printf("Content: %p, Address: %p, Size: %ld\n", pa, &pa, sizeof(pa));
    
    printf("Content: %f, Address: %p, Size: %ld\n", b, &b, sizeof(b));
    printf("Content: %p, Address: %p, Size: %ld\n", pb, &pb, sizeof(pb));
    
    printf("Content: %c, Address: %p, Size: %ld\n", c, &c, sizeof(c));
    printf("Content: %p, Address: %p, Size: %ld\n", pc, &pc, sizeof(pc));
    
    printf("\n");
    
    //2.- Malloc 
    int *iM =(int *)malloc(10*sizeof(int));
    iM[0] = 5;
    iM[1] = 3;
    
    printf("Content: %p, Address: %p, Size: %ld\n", iM, &iM, sizeof(iM));
    printf("Content: %d, Address: %p, Size: %ld\n", iM[1], &iM[1], sizeof(iM[1]));
    
    printf("\n");
    
    //3.- Function
    function(13);
    
    /*
    d=enteros
    f=float/double
    c=char
    s=string
    p=pointer
    */
}