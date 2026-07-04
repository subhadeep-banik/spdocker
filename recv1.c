 
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>
#include <string.h>
char run [1024];
 


void signal_handler(int signo, siginfo_t *info, void *context) {

  void *ptr;
  char *p;
  ptr = info->si_value.sival_ptr;
  p =(char *) ptr;
  printf("address=%llx %llx %llx\n", (char*)info->si_value.sival_ptr, (char *)ptr,p);

  printf(" %c\n", *p);
  for(int i=0;i<2;i++) printf(" %c ", *(p  + i));
  printf("\n");
   // memcpy( run , info->si_value.sival_ptr,1024);
  
    printf("\nRecieved signal %s\n",run);
}



void sig_set_handler ( int signo, void *handler )
{
struct sigaction *act;
act = malloc ( sizeof ( struct sigaction ) );
act -> sa_sigaction = handler;
act -> sa_flags = SA_SIGINFO;

sigaction ( signo, act, NULL );
}

 





void print1(void)
{
  printf("\rpid %d value is 1",getpid());
  sleep(1);
  fflush(stdout);
}

void print2(void)
{
  printf("\rpid %d value is 2",getpid());
  sleep(1);
    fflush(stdout);
}

void print3(void)
{
  printf("\rpid %d value is 3",getpid());
  sleep(1);
      fflush(stdout);
}
void main()
{
sig_set_handler(SIGUSR1,&signal_handler);
printf("pid is %d\n",getpid());
 
for(;;){
if(!strcmp(run,"a1")) print1();
else if(!strcmp(run,"a2")) print2();
else print3();
} 

 

}
