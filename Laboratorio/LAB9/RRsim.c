/*
Lab07 - Round Robin
Alex Vargas A00824525
Cesar Martinez A00517067
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int count = 0;
_Atomic int pid=0;

typedef struct Processes
{
	int id;
	int remainingTime;
	struct Processes *next;
} Process;

Process *front;

Process *createProcess(int id, int remainingTime)
{
	Process *toAdd = (Process *)malloc(sizeof(Process));
	toAdd->id = id;
	toAdd->remainingTime = remainingTime;
	toAdd->next = NULL;
	return toAdd;
}

void enqueue(Process *toAdd)
{
	if (front == NULL)
	{
		front = toAdd;
	}
	else
	{
		Process *temp = front;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = toAdd;
	}
	count++;
}

Process *dequeue()
{
	Process *toReturn = front;
	front = front->next;
	count--;
	toReturn->next = NULL;
	return toReturn;
}

void printQueue()
{
	Process *temp = front;
	printf("Total: %d; ", count);
	while (temp != NULL)
	{
		printf("id:%d,rT:%d; ", temp->id, temp->remainingTime);
		temp = temp->next;
	}
	printf("\n");
}

void printValues()
{
	Process *temp = front;
	while (temp != NULL)
	{
		printf("Adding process %d of time %d; \n", temp->id, temp->remainingTime);

		temp = temp->next;
	}
	printf("\n");
}

void *user(void *args){
	int id=*(int *)args;
	int processesToCreate=(rand()%10)+5;
	for (int i=0;i<processesToCreate;i++){
		int rTime=rand()%30;
		int currentPid=pid++;
		printf("Processes %d created with burst %d\n", currentPid, rTime);
		enqueue(createProcess(currentPid,rTime));

	}

}

int main()
{
	pthread_t user1, cpu1;
	int id1=1;
	int id2=2;
	pthread_create(&user1, NULL, user, (void*)&id1);
	pthread_join(user1,NULL);
	pthread_create(&cpu1, NULL, user, (void*)&id1);
	pthread_join(cpu1, NULL);





	srand(time(NULL));
	int Quantum = 4;

	printf("Time Slice is: %d \n", Quantum);

	enqueue(createProcess(1, rand() % 15));
	enqueue(createProcess(2, rand() % 15));
	enqueue(createProcess(3, rand() % 15));
	enqueue(createProcess(4, rand() % 15));
	enqueue(createProcess(5, rand() % 15));

	printValues();

	Process *temp = front;
	while (temp != NULL)
	{
		
		Process *curr = dequeue();
		int random;

		printf("Running process %d \n", curr->id);

		for (int i = 0;i<Quantum;i++){
			random = rand() % 100;
			curr->remainingTime--;
			if (curr->remainingTime == 0){
				printf("Process %d finished execution \n", curr->id);
				break;
			}else if(random <= 10){
				break;
			}
		}
	
		if (curr->remainingTime != 0){
			if (random <= 10){
				printf("Process %d blocked for IO and was preempted with remaining time %d \n", curr->id, curr->remainingTime);
			}else{
			printf("Process %d time slice ended and was preempted with remaining time %d \n", curr->id, curr->remainingTime);
			}
			enqueue(curr);
		}
		temp=front;
		
	}

	return 0;
}