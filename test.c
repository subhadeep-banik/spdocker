#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>
#include "header.h"
#include <dlfcn.h>
#include <time.h>
#define PIPE_READ 0
#define PIPE_WRITE 1
void get_rand_bytes(unsigned char *x, int n){
int i;

for(i=0;i<n;i++) x[i]=rand()&0xff;
}
int main ()
{
  int pid, died, exit_status, nbytes;
  int fd[2],i;
  char buf[4096];
  unsigned char key[16],pt[16],ct[16];
  srand(time(NULL));
  pipe(fd);

  switch(pid=fork()) {
  case -1:
    // No forking :-(
    printf("Cannot fork, failing");
  case 0:
    // This is the child process
    close(fd[PIPE_READ]);
    dup2(fd[PIPE_WRITE], STDOUT_FILENO);
    execl("./synthesize","synthesize","-s", "1", "-f", "e", "-t", "1", "-e", "1", NULL);
  default:
    close(fd[PIPE_WRITE]);
    // This is the parent process
    do {
      died = waitpid(pid, &exit_status, 0);
    } while (!WIFEXITED(exit_status));
    nbytes = read(fd[PIPE_READ], buf, sizeof(buf)-1);
 
    close(fd[PIPE_READ]);
  }

 
for(i=0;i<strlen(buf);i++) if(buf[i]==10) buf[i]=0;

puts(buf);
//strcpy(buf,"enc_s01_n02");

void *handle;
        handle = dlopen("./lib_enc.so", RTLD_NOW|RTLD_GLOBAL);
         if (handle == NULL) {
         fprintf(stderr, "%s\n", dlerror());
         return 1;
         }

  typedef void (*function)(unsigned char *, unsigned char *, unsigned char *);
  function func = (function) dlsym(handle, buf);
  if (func == NULL) {
    fprintf(stderr, "%s\n", dlerror());
    return 2;
  }
get_rand_bytes(key,16);
get_rand_bytes(pt, 16);  
func(key,pt,ct );

printf("Plaintext: ");
for(i=0;i<16;i++)printf("%02x",pt[i]);
printf("\n");

printf("Key: ");
for(i=0;i<16;i++)printf("%02x",key[i]);
printf("\n");


printf("Ciphertext: ");
for(i=0;i<16;i++)printf("%02x",ct[i]);
printf("\n");

}
