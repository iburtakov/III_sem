#include <unistd.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>

#define READY_TYPE runnersCount + 2
#define JUDGE_TYPE 666
struct msgbuf
{
        long type;
        // char text[1];
};

//msgsnd
//id очереди
//указатель на структуру сообщения
//размер char text
//Параметр msgflg

//msgrcv
//id очереди
//указатель на структуру сообщения
//размер char text
//лейбл c номером сообщения из очереди берется первое сообщение типа msgtyp
//Параметр msgflg

int main(int argc, char *argv[])
{
        int runnersCount = atoi(argv[1]);
        int id = msgget(IPC_PRIVATE, IPC_CREAT | 0777); //очередь сообщений
        pid_t pid = 0;

        pid = fork(); //создаем процесс judge

        if (pid == 0)
        {
                printf("I'm judge here!\n");

                struct msgbuf buf = {1}; //сообщение

                //судья должен говорить первым
                for (int i = 1; i < runnersCount + 1; i++)
                {
                        buf.type = i;
                        msgsnd(id, &buf, 0, 0);
                }

                //судья ожидает сообщения от всех бегунов и начинает соревнования
                for (int i = 0; i < runnersCount; i++)
                {
                        msgrcv(id, &buf, 0, READY_TYPE, 0);
                }
                printf("Start\n");

                buf.type = 1;

                msgsnd(id, &buf, 0, 0); //старт первого бегуна
                msgrcv(id, &buf, 0, runnersCount + 1, 0); //ожидание сообщения от последнего бегуна

                printf("End of race\n");
                return 0;
        }


        for (int i = 1; i < runnersCount + 1; i++)
        {
                pid = fork();
                if (pid == 0)
                {
                        //бегун ждет, пока судья назовет его имя
                        struct msgbuf buf;
                        msgrcv(id, &buf, 0, i, 0);
                        printf("I'm runner %d\n", i);

                        //отправляем сообщения о готовности
                        buf.type = READY_TYPE;
                        msgsnd(id, &buf, 0, 0);

                        //передачи инфы между бегунами
                        buf.type = i;
                        msgrcv(id, &buf, 0, buf.type, 0);

                        printf("I'm running - number %d \n", i);
                        //после конца забега отправляем следующему
                        buf.type = i + 1;
                        msgsnd(id, &buf, 0, 0);

                        return 0;
                }
        }


        //родительский процесс ожидает завершения бегов и завершается
        for (int i = 0; i < runnersCount + 1; i++)
        {
                wait(NULL);
        }

        return 0;
}
