#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main (int argc, char* argv[])
{
         int n = atoi(argv[1]);
         printf("parent pid = %d, ppid = %d\n", getpid(), getppid());
         pid_t pid = getpid();

         for (int i = 0; i < n; i++)
         {
                 int pid = fork();

                 if (pid == 0)
                 {
                         sleep(1);

                         printf("child %d, pid = %d, ppid = %d\n", i, getpid(), getppid());
                         return 0;
                 }

         }

         for(int i = 0; i < n; ++i)
         {
                 wait(NULL);
         }
         return 0;
}
