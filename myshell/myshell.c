#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

//pipe (int *fd)
// fd[0] - выходной поток pipe
// fd[1] - входной поток pipe

int main()
{
        int length = 0;
        char string[1024];
        int wordsCount = 0;
        printf("AVE OMNISSIAH: ");
        // пока не встретили конец ввода
        while (fgets(string, 1024, stdin) != NULL)
        {
                length = strlen(string);
                string[length - 1] = '\0'; //приведение строки к стандартному виду
                if (strchr(string, '|')) // если есть пайпы
                {
                        int comandCount = 0;
                        char *comands[128]; //массив команд с аргументами в строке string
    
                        int i = 0;
    
                        for (comands[i] = strtok(string, "|"); comands[i]; i++, comands[i] = strtok(NULL, "|"))
                        {
                                ++comandCount;
                        }
    
                        //получили [comand arguments]
    
                        char *words[128][128];
    
                        for (int j = 0; j < comandCount; j++)
                        {
                                i = 0;
                                for(words[j][i] = strtok(comands[j], " "); words[j][i]; i++, words[j][i] = strtok(NULL, " "))
                                {}
                        }
    
                        pid_t pid = 0;
                        int countPipes = comandCount - 1; //в силу вида строки
    
                        //массив файловых дескрипторов и на вход и на выход
                        int fd[2 * countPipes];

                        //создание и проверка входов и выходов pipe'ов
                        for (int i = 0; i < countPipes; i++)
                        {
                                if(pipe(fd + 2 * i) < 0)
                                        perror("ERROR IN PIPE");
                        }
    
                        for (int i = 0, j = 1; i < comandCount; i++, j += 2) //j - счётчик выходов пайпов
                        {
                                int prevFd = 0;
                                pid = fork();
                                if (pid == 0)
                                {
                                        if (i == 0) //первая команда
                                        {
                                                //замена output
                                                close(1);
                                                if (dup(fd[j] < 0)) 
                                                        perror("ERROR IN DUP i = 0");
                                                prevFd = j - 1;//вход для следующего процесса
                                        }
                                        else if (i > 0 && i < comandCount - 1) //не первая и не последняя команды
                                        {
                                                //замена input
                                                close(0);
                                                if (dup(fd[prevFd]) < 0)
                                                        perror("ERROR IN DUP i > 0 in input");
    
                                                //замена output
                                                close(1);
                                                if (dup(fd[j]) < 0)
                                                        perror("ERROR IN DUP i > 0 in output");
    
                                                prevFd = j - 1;
                                        }
                                        else if (i == comandCount - 1) //последняя команда
                                        {
                                                close(0);
                                                if (dup(fd[prevFd]) < 0)
                                                        perror("ERROR IN DUP i = comandCount - 1");
                                        }
    
                                        for (int i = 0; i < 2 * countPipes; i++)
                                        {    
                                                close(fd[i]);
                                        }
                                        //вызываем команды
                                        if(execvp(words[i][0], words[i]) < 0)
                                                perror("ERROR IN EXEC");
                                }
                        }
                        //закрываем лишние файловые дескрипторы ниже stdin stdout и stderr
                        for (int i = 0; i < countPipes * 2; i++)
                        {
                                close(fd[i]);
                        }
                        //ожидаем завершение всх дочерних процессов
                        for (int i = 0; i < comandCount + 1; i++)
                        {
                                wait(NULL);
                        }
                        printf("AVE OMNISSIAH: ");
                }
                //если всего одна команда без пайпа
                else
                {
                        char *words[1024];
                        int i = 0;
                        for (words[i] = strtok(string, " "); words[i]; i++, words[i] = strtok(NULL, " "))
                        {
                                wordsCount++;
                        }
    
                        pid_t pid = fork();
                        if (pid == 0)
                        {
                                words[wordsCount] = NULL;
                                execvp(words[0], words);
                        }
                        wait(NULL);
                        printf("AVE OMNISSIAH: ");
                }
        }
        return 0;
}
