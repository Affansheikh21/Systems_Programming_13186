#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

void sighandler(int signo) {
    write(STDOUT_FILENO, "\nYou pressed CTRL-C!\n", sizeof("\nYou pressed CTRL-C!\n"));
}

int main() {
    /*signal(SIGINT, sighandler);
    while(true){
        pause();
    }*/
    char buff[50];
   signal(SIGINT,sighandler);



    int ret=read(STDIN_FILENO,buff,100);
    if (ret==-1) {
        perror("Error1");
    }
    ret=write(STDOUT_FILENO,buff,ret);
    if (ret==-1) {
        perror("Error2");
    }
    return 0;
}
