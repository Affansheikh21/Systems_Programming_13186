#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

int main()
{

        char parentid[12]={0x0};
        int i= (int)getpid();
        sprintf(parentid,"%d", i);

                write(STDOUT_FILENO,"Parent id:",sizeof("Parent id:"));
                write(STDOUT_FILENO, parentid, sizeof(parentid));



int result =0;
int temp=0;
char pos[] = "\nEnter Command: ";
write(STDOUT_FILENO,pos,sizeof(pos));
char str[30];
int rfs = read(STDIN_FILENO,str,30);


char * token = NULL;
char * tokenize;
token = strtok(str," ");
tokenize = token;
    if  (strcmp(tokenize,"Add") == 0 || strcmp(tokenize,"add") == 0) {
   /* walk through other tokens */
   token = strtok(NULL," ");
   while( token != NULL ) {
     // printf( " %s\n", token );
    temp = atoi(token);
    result = result + temp;
      token = strtok(NULL, " ");
   } //end while
   char res[12]={0x0};
    int q= result;
    sprintf(res,"%d", q);
   write(STDOUT_FILENO, res, sizeof(res));

} // end if



    else if (strcmp(tokenize,"Run") == 0 || strcmp(tokenize,"run") == 0){
        pid_t pid=fork();


            if (pid == 0 ) {
              char childid[12]={0x0};
            int j= (int)getpid();
        sprintf(childid,"%d", j);
        write(STDOUT_FILENO,"Child id:",sizeof("Child id:"));
        write(STDOUT_FILENO, childid, sizeof(childid));


     token = strtok(NULL," ");


    char * path;
    char * fname;


    if (strstr(token, "/") != NULL) {
        path= token;
        token = strtok(NULL, " ");
        fname = token;
                            }

    else {
        fname = token;
        token = strtok(NULL, " ");
        path = token;

                            }




        char * args[] = {path,fname,NULL};
        char * para[] = {fname,NULL};
        int execprog = execvp(args[0],args);

        if (execprog == -1) {
          int ealt = execl(args[0],NULL);
            if (ealt == -1) {
                int ealt2 = execvp(para[0],para);
                    if (ealt2 == -1)  {
                        int ealt3 = execlp(path,NULL);
                            if (ealt3 == -1) {
                            perror("Error: ");
                                }
                    }
            }

        }



    } // end if

       else {
           waitpid(pid,0,0);
           } // end else






   } //end else if




    else {
    printf("%s","Nothing");

    } // end else














}
