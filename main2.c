#include  <stdio.h>
#include  <sys/types.h>
#include <stdlib.h>
#define   MAX_COUNT  200

void  ChildProcess(void);                /* child process prototype  */
void  ParentProcess(void);               /* parent process prototype */

void  main(void)
{
     pid_t  pid;
     
     pid = fork();
     if (pid == 0) 
          ChildProcess();
     else {
       pid= fork();
       if (pid == 0) {
         ChildProcess();
       }
          ParentProcess();
  
           int status;
           wait(status);
           printf("   *** Child Pid: %d has completed ***\n", pid);
       
     }
}

void  ChildProcess(void)
{
     srandom(123);
     int   i;
     int loopRange = random() % 31;
     pid_t child_pid = getpid();
     pid_t parent_pid = getppid();
     for (i = 1; i <= loopRange; i++) {
          printf("   This line is from child, value = %d\n", i);
          printf("Child Pid: %d is going to sleep!\n", child_pid);
          sleep(random() % 11);
          printf("Child Pid: %d is awake!\nWhere is my Parent: %d?\n", child_pid, parent_pid);
      }
  

  exit(0);
}

void  ParentProcess(void)
{
     srandom(1234);
     int   i;

     for (i = 1; i <= MAX_COUNT; i++)
          printf("This line is from parent, value = %d\n", i);
     printf("*** Parent is done ***\n");
     
     
}