#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <string.h>
int main()
{
/*
*/

char buffer[] = "Enter program name: ";
char input[50] = " ";
int wts = write(STDOUT_FILENO,buffer,strlen(buffer));
int rfs =read(STDIN_FILENO,input,50);

//printf("%s",input);
//printf("%d\n",strlen(input));
        int count=0;
        for (int i=0; i<strlen(input);i++) {
                    if (input[i] == ' ')
                    count++;


        }

printf("%d",count);



            if (count == 1) {


            char * token = NULL;
            token = strtok(input, " ");

            char * execname = token;
            printf("%s\n",token);
            printf("%d",strlen(token));


            char * filename = NULL;

            token = strtok(NULL," ");

            if(token[strlen(token)-1] = "\0") {

                token[strlen(token)-1] = 0;

            }

             filename = token;
            printf("%s\n",token);
            printf("%d",strlen(token));




                char * args[] = {execname,filename,NULL};
                int ret=0;

                ret = execvp(execname,args);
                    if (ret == -1) {
                        printf("%d\n",errno);

                    }







            }

/*

    if (input[rfs-1]){
        input[rfs-1] = 0;
   // printf("%s",input);
 //   printf("%d",strlen(input));
    }


    char * args[] = {input,NULL};
    int ret=0;

    ret = execvp(input,args);
        if (ret == -1) {
            printf("%d\n",errno);

        }





*/
}
