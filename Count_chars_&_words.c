#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <error.h>
#include <string.h>
int main()
{

     char dos[] = {"Enter input: "};
     int wts = write(STDOUT_FILENO,dos,strlen(dos));

     char input[100]= " ";
  //   int rfs = read(STDIN_FILENO,input,100);



                while (1){
                int rfs = read(STDIN_FILENO,input,100);

                // remove enter
                    if (input[strlen(input)-1] = "\0") {
                        input[strlen(input)-1] = 0;
                    }

                    if (strcmp(input,"chalnikal") == 0) {
                    break;

                    }



                     int count =0;
                     int space=0;

                    for(int i=0; i<strlen(input);i++){

                        if (input[i] == ' '){
                        space++;
                        }
                    }

                            if(input[strlen(input)-2] == ' ') {
                            space--;
                            }

    count = space+1;

    printf("Total words are: %d\n",count);
    printf("Total words are: %d\n",rfs-1-space);

                }







  /*                  // remove enter
                    if (input[strlen(input)-1] = "\0") {
                        input[strlen(input)-1] = 0;
                    }




                    // check if user
                   if(strcmp(input,"chalnikal") == 0) {
                   write(STDOUT_FILENO,"Good bye!",sizeof("Good bye!")-1);
                    exit(0);

                }






     // count number of words.
     int count =0;
     int space=0;

                    for(int i=0; i<strlen(input);i++){

                        if (input[i] == ' '){
                        space++;
                        }
                    }
                        if (input[strlen(input)-1] = "\0"){
                            if(input[strlen(input)-2] == ' ') {
                            space--;
                            }
                        }
    count = space+1;

    printf("Total words are: %d\n",count);
    printf("Total words are: %d\n",rfs-1-space);
*/
}
