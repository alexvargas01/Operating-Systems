#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <string.h>
#include <sys/msg.h>

struct msgbuf
{
  long mtype;      /* message type, must be > 0 */
  char mtext[100]; /* message data */
};

int main()
{
  key_t key = ftok("/Users/red/Desktop/TEC DE MONTERREY/5 Semestre/OperatingSystems/Exam3_IPC/Q1_ServiceStation/key.txt", 7);
  int mailbox = msgget(key, IPC_CREAT | 0666);
  struct msgbuf m;
  int value = msgrcv(mailbox, &m, sizeof(struct msgbuf), 0, IPC_NOWAIT);
  if (value == -1)
  {
    printf("There are not any more orders. You can take a break\n");
  }
  else
  {
    printf("The next order to attend is %s\n", m.mtext);
  }

  return 0;
}