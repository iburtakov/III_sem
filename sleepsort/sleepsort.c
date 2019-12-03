#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char* argv[])
{

        int n = argc;

        for(int i = 1; i < n; ++i)
        {

                int pid = fork();
                if(pid == 0)
                {
                        int number = atoi(argv[i]);
                        usleep(10000 * (number));
                        printf("%d ", number);
                        return 0;
                }
        }

        for(int i = 0; i < n; ++i)
        {
                wait(NULL);
        }
        printf("\n");

        return 0;
}
