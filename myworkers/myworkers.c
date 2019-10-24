#include <stdio.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdlib.h>
#include <sys/sem.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{
        struct timespec tp;
        clock_gettime(CLOCK_MONOTONIC, &tp);
        int sec1 = tp.tv_sec;
        int nsec1 = tp.tv_nsec;

        int wrkNum = atoi(argv[1]);
        int tskNum = atoi(argv[2]);

        int id = shmget(IPC_PRIVATE, sizeof(long), IPC_CREAT | 0777);

        int semid = semget(IPC_PRIVATE, 1, IPC_CREAT | 0777);
        if (semid < 0)
                perror("ERROR IN SEMID");
        struct sembuf sopsInc = {0, 1, 0};

        if (semop(semid, &sopsInc, 1) < 0)
                perror("ERROR IN SEMOP INC line 25");
        if (id < 0)
        {
                perror("ERROR IN shmget");
                exit(1);
        }

        long *p = (long *)shmat(id, NULL, 0);
        *p = 0;

        for (long i = 0; i < wrkNum; i++)
        {
                pid_t pid = fork();
                if (pid < 0)
                        perror("Error in fork");
                if (pid == 0)
                {
                        struct sembuf sopsInc = {0, 1, 0};
                        struct sembuf sopsDec = {0, -1, 0};

                        if (semop(semid, &sopsDec, 1) < 0)
                                perror("ERROR IN SEMOP INC line 46");
                        for (long j = 0; j < tskNum; j++)
                        {
                                (*p)++;
                        }
                        if (semop(semid, &sopsInc, 1) < 0)
                                perror("ERROR IN SEMOP DEC line 52");
                        return 0;
                }
        }

        for (long i = 0; i < wrkNum; i++)
        {
                wait(NULL);
        }

        clock_gettime(CLOCK_MONOTONIC, &tp);
        int sec2 = tp.tv_sec;
        int nsec2 = tp.tv_nsec;
        printf("TIME : %.2f ns\n", (sec2 * 1000 + nsec2 / 1000000 - sec1 * 1000 - nsec1 / 1000000));
        printf("Expected %d\n", wrkNum * tskNum);
        printf("Real %ld\n", *p);

        if (shmdt(p) < 0)
                perror("ERROR IN DETATCH");
        if (shmctl(id, IPC_RMID, NULL) < 0)
                perror("ERROR IN shmctl");
        if (semctl(semid, 0, IPC_RMID, 0) < 0)
                perror("ERROR IN semctl");
        return 0;
}
