#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <error.h>
#include <errno.h>

#define MAX_SIZE 100
int main(){
/*
Write a program that spawns one process. 
The child takes as in input one number from the user and using the exit code indicates
to the parent if number is even or odd. The parent prints the "Odd number" if the inputted number
in child was odd and "Even number" if the inputted number in child was even.
Use of pipes and any other IPC mechanism is not required. 
Make sure all necessary checks are part of your code.
*/
 int status=0;
__pid_t pid;

char buff[MAX_SIZE]= " ";


    pid = fork();
        if(pid ==-1) {
            perror("Fork Failed");
            sprintf(buff,"Error number value: %d\n",errno);
            write(STDOUT_FILENO,buff,strlen(buff));
        } 

        if (pid == 0) {
            char input[MAX_SIZE];
            write(STDOUT_FILENO,"Enter number:\n",sizeof("Enter number:\n"));
            int r = read(STDIN_FILENO,input,10);
                if (r == -1) {
                    perror("Nothing to Read");
                }
            if(input[r-1] ='\0'){
                input[r-1] =0;
            }

            int exitstatus = atoi(input);
            exit(exitstatus);
        }

        else {
            // parent
        int x = wait(&status);
         
         if (x == -1) {
                    perror("wait");
                }
            
            int value = WEXITSTATUS(status);        
                if (value%2 == 0) {
                     sprintf(buff,"The number %d is even \n",WEXITSTATUS(status));
                     write(STDOUT_FILENO,buff,strlen(buff));

                }
                else if (value%2 != 0){
                    sprintf(buff,"The number %d is odd \n",WEXITSTATUS(status));
                     write(STDOUT_FILENO,buff,strlen(buff));
                }
                
            

        }









}
