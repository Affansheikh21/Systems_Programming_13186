#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

int count=0;
void sighandler(int signo) {
    if (signo == SIGINT) {

    write(STDOUT_FILENO, "\nYou pressed CTRL-C!\n", sizeof("\nYou pressed CTRL-C!\n"));
   // psignal(signo, "What the hell dude");
    count++;
    }

}

int main() {
    /*signal(SIGINT, sighandler);
    while(true){
        pause();
    }*/
    char buff[50];

    sigset_t set;
    sigset_t oldset;
    sigset_t suspendset;

    sigfillset(&set);

    // checking
    int w = sigismember(&set,SIGINT);
        if(w==1) {
        write(STDOUT_FILENO,"working fine\n",sizeof("working fine\n"));
        }
        else {
        write(STDOUT_FILENO,"issue\n",sizeof("issue\n"));
        }


// initialize sigprocmask

int s = sigprocmask(SIG_SETMASK,&set,NULL);


    int counter=3;

    while(counter>0) {
   signal(SIGINT,sighandler);
   //signal(SIGINT,SIG_IGN);



	int w=5;
    int ret=read(STDIN_FILENO,buff,w);
    if (ret==-1) {
        perror("Error1");
    }

    ret=write(STDOUT_FILENO,buff,ret);
    if (ret==-1) {
        perror("Error2");
    }
    counter--;

	}

    s = sigprocmask(SIG_UNBLOCK,&set,NULL);
    int pen = sigpending(&oldset);
    int o = sigismember(&oldset,SIGINT);
        if(o==0) {
        write(STDOUT_FILENO,"signals\n",sizeof("signals\n"));
        }
        else {
        write(STDOUT_FILENO,"issue\n",sizeof("issue\n"));
        }




        printf("%d\n",count);
    return 0;
}
