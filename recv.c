
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <unistd.h>
#include <signal.h>

int run = 1;
 


void signal_handler(int signo, siginfo_t *info, void *context) {
 
 
    int received_val = info->si_value.sival_int;
    run = received_val;
    printf("\nRecieved signal %d\n",run);
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
if(run==1) print1();
else if(run==2) print2();
else print3();
} 

 

}
