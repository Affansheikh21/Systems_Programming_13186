#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/time.h>
       #include <sys/stat.h>
       #include <fcntl.h>
#define MAX_SIZE 100

int main() {

struct timeval tv;
fd_set fd;
// timeout set is five seconds
tv.tv_sec = 5;

// populate set
FD_ZERO(&fd);
FD_SET(STDIN_FILENO,&fd);


    int ret = select(STDIN_FILENO+1,&fd,NULL,NULL,&tv);
        if (ret == -1){
            perror("There's a problem");
        }

        else if (!ret) {
            printf("Time elapsed: %d\n",5);
        }

        if (__FD_ISSET(STDIN_FILENO,&fd) ) {
            write(STDOUT_FILENO,"Data entered:\n",sizeof("Data entered:\n"));
            char buff[MAX_SIZE];
            int r = read(STDIN_FILENO,buff,100);
            write(STDOUT_FILENO,buff,strlen(buff));
            printf("Time that was remaining: %d\n",tv.tv_sec);
        }



}
